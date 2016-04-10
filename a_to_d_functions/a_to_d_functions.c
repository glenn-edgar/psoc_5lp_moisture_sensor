/*
**
** File: a_to_d_functions.c
** Implements high speed a_to_d_functions
** High speed is needed as we are measuring 60 hz a/c signals
**
**
*/

#include <stdlib.h>
#include <device.h>
#include "a_to_d_functions.h"
#include "moving_average.h"
#include "cf_events.h"


#define SE_NUMBER 3
#define DE_NUMBER 1
#define SIGMA_DELTA_NUMBER 1

static MOVING_AVERAGE_STRUCT se_dc[SE_NUMBER];
static MOVING_AVERAGE_STRUCT se_ac[SE_NUMBER];

static MOVING_AVERAGE_STRUCT de_dc[DE_NUMBER];
static MOVING_AVERAGE_STRUCT de_ac[DE_NUMBER];

static MOVING_AVERAGE_STRUCT sigma_dc[ SIGMA_DELTA_NUMBER ];
static MOVING_AVERAGE_STRUCT sigma_ac[ SIGMA_DELTA_NUMBER ];

#define ALPHA_VALUE .01

CY_ISR_PROTO(process_ad_interrupt)
{
    ad_interrupt_ClearPending();
    cf_send_interrupt_event(  CF_PROCESS_AD_RESULTS, 0 );
}

void ad_setup_interrupt( void )
{
    ad_interrupt_StartEx( process_ad_interrupt );
}

int ad_get_se_number( void )
{
    return SE_NUMBER;
}

void ad_init_se( void )  // init single ended a/d signals
{
    int i;
    for( i = 0; i< SE_NUMBER; i++ )
    {
        ma_initialize( &se_dc[i], ALPHA_VALUE);
        ma_initialize( &se_ac[i],ALPHA_VALUE);
    }
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
}

void ad_process_se( void )  // process single ended 
{
    int   i;
    int16 temp;
    int16 dc_value;
    int16 ac_value;
    for( i = 0; i < SE_NUMBER; i++)
    {
        temp =  ADC_SAR_Seq_1_GetResult16(i);
        dc_value = ma_update( &se_dc[i], temp);
        ac_value = (int16) abs( (int)(dc_value) -(int)temp );
        ma_update(&se_ac[i],ac_value);
    }
}

int ad_get_se_dc( int number, int offset, int16 *buffer )
{
    int i;
    int count;
    
    count = 0;
    if( number > SE_NUMBER)
    {
        number = SE_NUMBER;
    }
    for( i = offset; i < number; i++)
    {
        *buffer++ = ma_get_value( &se_dc[i] );
    }
    return count;
}

int ad_get_se_ac( int number, int offset, int16 *buffer )
{
    int i;
    int count;
    
    count = 0;
    if( number > SE_NUMBER)
    {
        number = SE_NUMBER;
    }
    for( i = offset; i < number; i++)
    {
        *buffer++ = ma_get_value( &se_ac[i] );
    }
    return count;
}


void ad_init_de( void )  // init single ended a/d signals
{
    int i;
    for( i = 0; i< DE_NUMBER; i++ )
    {
        ma_initialize( &de_dc[i], ALPHA_VALUE);
        ma_initialize( &de_ac[i], ALPHA_VALUE);
    }
    ADC_SAR_Seq_2_Start();
    ADC_SAR_Seq_2_StartConvert();
}

void ad_process_de( void )  // process single ended 
{
    int   i;
    int16 temp;
    int16 dc_value;
    int16 ac_value;
    for( i = 0; i < DE_NUMBER; i++)
    {
      temp =  ADC_SAR_Seq_2_GetResult16(i);
        dc_value = ma_update( &de_dc[i], temp);
        ac_value = (int16) abs( (int)(dc_value -temp ) );
        ma_update(&de_ac[i],ac_value);
    }
}


int ad_get_de_number( void )
{
    return DE_NUMBER;
}


int ad_get_de_dc( int number, int offset, int16 *buffer )
{
    int i;
    int count;
    
    count = 0;
    if( number > DE_NUMBER)
    {
        number = DE_NUMBER;
    }
    for( i = offset; i < number; i++)
    {
        *buffer++ = ma_get_value( &de_dc[i] );
    }
    return count;
}

int ad_get_de_ac( int number, int offset, int16 *buffer )
{
    int i;
    int count;
    
    count = 0;
    if( number > DE_NUMBER)
    {
        number = DE_NUMBER;
    }
    for( i = offset; i < number; i++)
    {
        *buffer++ = ma_get_value( &de_ac[i] );
    }
    return count;
}


void ad_init_sigma_delta(unsigned config )
{
    if( config > SIGMA_CONFIG )
    {
        config = SIGMA_CONFIG;
    }
    SIGMA_A_D_Start();
    ma_initialize( &sigma_dc[0], ALPHA_VALUE);
    ma_initialize( &sigma_ac[0], ALPHA_VALUE);
    SIGMA_A_D_StartConvert();
    SIGMA_A_D_SelectConfiguration( config, 1);
    
    
   
}
void ad_process_sigma_delta( void )
{
    
    int16 temp;
    int   status;
    int16 dc_value;
    int16 ac_value;
    int32 mvolts;
    
    temp =   SIGMA_A_D_GetResult16() ;
    status = SIGMA_A_D_IsEndConversion(SIGMA_A_D_RETURN_STATUS);
    mvolts = SIGMA_A_D_CountsTo_mVolts(temp) ;


    dc_value = ma_update( &sigma_dc[0], temp);
    ac_value = (int16) abs( (int)(dc_value -temp ) );
    ma_update(&sigma_ac[0],ac_value);
   
}

int16 ad_get_sigma_delta_dc( void )
{
   return sigma_dc[0].average;   
}

int16 ad_get_sigma_delta_ac( void )
{
    return sigma_ac[0].average;  
}