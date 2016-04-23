/*
**
** File: modbus_utilities.h
** File for shuffling bytes for network ordering
**
**
**
*/

#ifndef _MODBUS_UTILITES_H_
#define _MODBUS_UTILITES_H_

#include <device.h>
  


    
static inline void swap_16( uint8 *input )
{
    
    uint16 *temp_ptr;
    uint16 temp;
    
    temp_ptr = (uint16*)input;
    temp = *temp_ptr;   
    temp =  ((temp&0xff)<<8)|((temp>>8)&0xff);
    *temp_ptr = temp;
      
   
}

static inline void swap_32( uint8 *input )
{
    uint32 *temp_ptr;
    uint32 temp;
    
    temp_ptr = (uint32*)input;
    temp = *temp_ptr;   
  
    temp =  ((temp&0xff000000)>>24)|((temp&0x00ff0000)>>8)|((temp&0xff00)<<8)|((temp&0xff)<<24 );
     *temp_ptr = temp;
}

    
#endif