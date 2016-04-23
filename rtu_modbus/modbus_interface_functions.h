/*
**
** File: modbus_interface_functions.h
**
**
**
**
**
*/

#ifndef _MODBUS_INTERFACE_FUNCTIONS_H_
#define _MODBUS_INTERFACE_FUNCTIONS_H_

#include <device.h>

   
   
uint16  mod_access_read_temp(  uint8 *buffer );
uint16 mod_read_current_time( uint8 *buffer );
uint16  mod_sigma_dc( uint8 *buffer );
uint16  mod_sigma_ac(  uint8 *buffer );
uint16  mod_sar_dc(  uint8 *buffer );
uint16  mod_sar_ac(  uint8 *buffer ); 
uint16  mod_store_current_time( uint8 *buffer );
    
    
    
#endif