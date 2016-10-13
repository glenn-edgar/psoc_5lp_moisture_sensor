/* 
**
**
** Function a_to_d_functions.h
**
**
*/

#ifndef  _A_TO_D_FUNCTIONS_H_
#define  _A_TO_D_FUNCTIONS_H_
    
    
#include <device.h>

#define SIGMA_CONFIG 1
#define SIGMA_DELTA_NUMBER 1

#define SE_NUMBER 1
    
void ad_setup_interrupt( void );



void ad_init_se( void );  // init single ended a/d signals


void ad_process_se( void );  // process single ended 


void ad_process_se_second( void );

void ad_process_minute_second( void );

        


void ad_init_sigma_delta( void );
void ad_init_sigma_switch_channel(unsigned channel, unsigned config );
void ad_process_sigma_delta( void );
void  ad_sigma_ad_end_of_sequence( void );
void ad_sigma_ad_minute_processing( );




#endif