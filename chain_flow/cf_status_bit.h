/*
** File cb_status_bit.h
** File to dispatch actions based upon status bits.
** 
**
**
**
*/

#ifndef CF_STATUS_BIT_H_
#define CF_STATUS_BIT_H
    
/*
Status Bit Definitions
Max 32 bits
*/
    
#define CF_PROCESS_AD_RESULTS  1
#define CF_PROCESS_MODBUS      2
// next bit would be 4
// next bit would be 8
    
#include <device.h>    
    
void cf_initialize_status_manager( void );
void cf_set_interrupt_status_bit( uint32 status_bit );
void cf_set_status_bit( uint32 status_bit );
uint32 cf_get_status( void );

    
#endif