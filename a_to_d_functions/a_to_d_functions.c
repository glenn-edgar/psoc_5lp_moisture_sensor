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
#include "cf_status_bit.h"
#include "process_modbus_message.h"
#include "cf_external_functions.h"

#define ALPHA_VALUE_SEC .01
#define ALPHA_VALUE_MIN .2

#define   SIGMA_SETTLING_TIME   10
#define   SIGMA_WAIT_FOR_INIT_STATE  0
#define   SIGMA_SETTLING_STATE       1
#define   SIGMA_MEASUREMENT_STATE    2





static const int se_reg_mapping[1]       = { MOISTURE_TEMP_DC_MIN_FLOAT };


static const int se_calibration_mapping[] = { MOISTURE_TEMP_CALIBRATION_A };


static MOVING_AVERAGE_STRUCT se_dc_sec[ SE_NUMBER];
static MOVING_AVERAGE_STRUCT se_ac_sec[ SE_NUMBER];
static MOVING_AVERAGE_STRUCT se_dc_min[ SE_NUMBER];
static MOVING_AVERAGE_STRUCT se_ac_min[ SE_NUMBER ];



CY_ISR_PROTO(process_ad_interrupt)
{
    ad_interrupt_1_ClearPending();
    cf_set_interrupt_status_bit(  CF_PROCESS_AD_RESULTS );
}

/*
**
**  SAR Functions
**
*/

void ad_setup_interrupt( void )
{
    AD_CLOCK_Start();
    ad_interrupt_1_StartEx( process_ad_interrupt );
}


void ad_init_se( void )  // init single ended a/d signals
{
    int i;
    for( i = 0; i< SE_NUMBER; i++ )
    {
        ma_initialize( &se_dc_sec[i], ALPHA_VALUE_SEC,0);
        ma_initialize( &se_ac_sec[i], ALPHA_VALUE_SEC,0);
        ma_initialize( &se_dc_min[i], ALPHA_VALUE_MIN,0);
        ma_initialize( &se_ac_min[i],ALPHA_VALUE_MIN,0);

    }
    
    ADC_SAR_Seq_1_Start();
    ADC_SAR_Seq_1_StartConvert();
}

void ad_process_se( void )  // process single ended 
{
    int   i;
    int32 temp;
    int32 dc_value;
    int32 ac_value;
    int32 mvolts;
    
    
    for( i = 0; i < SE_NUMBER; i++)
    {
         temp =  ADC_SAR_Seq_1_GetResult16(i);
         mvolts = ADC_SAR_Seq_1_CountsTo_mVolts(temp);
         dc_value = ma_update( &se_dc_sec[i], mvolts);
         ac_value = (int16) abs( (int)(dc_value -mvolts ) );
         ma_update(&se_ac_sec[i],ac_value);
 
    }
}

void ad_process_se_second( void )
{
    int i;
    float value;
    float calibration_a;
    float calibration_b;
    
    for( i = 0; i< SE_NUMBER; i++ )
    {
        get_modbus_data_registers( se_calibration_mapping[i], 2, (uint16 *)&calibration_a );
        get_modbus_data_registers( se_calibration_mapping[i]+2, 2, (uint16 *)&calibration_b );
        value = ma_get_value( &se_dc_sec[i]);
        ma_update(   &se_dc_min[i], value );
        value = (value*calibration_a) + calibration_b;
        store_modbus_data_registers( se_reg_mapping[i]+4, 2,(uint16*) &value);
        value = ma_get_value( &se_ac_sec[i]);
        ma_update(   &se_ac_min[i], value );
        value = (value) * calibration_a;
        store_modbus_data_registers( se_reg_mapping[i]+6, 2,(uint16*) &value);
    }
}
        

void ad_process_minute_second( void )
{
    int i;
    float value;
    float calibration_a;
    float calibration_b;
    
    for( i = 0; i< SE_NUMBER; i++ )
    {
        get_modbus_data_registers( se_calibration_mapping[i], 2, (uint16 *)&calibration_a );
        get_modbus_data_registers( se_calibration_mapping[i]+2, 2, (uint16 *)&calibration_b );
        value = ma_get_value( &se_dc_min[i]);
        value = (value*calibration_a) + calibration_b;
        store_modbus_data_registers( se_reg_mapping[i], 2,(uint16*) &value);
        value = ma_get_value( &se_ac_min[i]);
        value = (value) * calibration_a;
        store_modbus_data_registers( se_reg_mapping[i]+2, 2,(uint16*) &value);
    
        
    }    
    
}
      

/*
**
**  Sigma A/D Functions
**
**
**
*/ 


