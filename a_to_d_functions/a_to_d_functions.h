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
    
void ad_setup_interrupt( void );
int ad_get_se_number( void );
void ad_init_se( void );  // init single ended a/d signals
void ad_process_se( void );  // process single ended 


int ad_get_se_dc( int number, int offset, int16 *buffer );
int ad_get_se_ac( int number, int offset, int16 *buffer );

int ad_get_de_number( void );

int ad_get_de_number( void );
void ad_init_de(void );        // init differential a/d signals
void ad_process_de( void ); // process differential a/d signals

int ad_get_de_dc( int number, int offset, int16 *buffer );
int ad_get_de_ac( int number, int offset, int16 *buffer );

void ad_init_sigma_delta(unsigned config );
void ad_process_sigma_delta( void ); // process differential a/d signals
int16 ad_get_sigma_delta_dc( void );
int16 ad_get_sigma_delta_ac( void );





#endif