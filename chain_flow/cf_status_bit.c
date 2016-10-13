/*
**
** File cf_status_bit.c
**
**
**
*/
#include <device.h>
#include "cf_status_bit.h"


static uint32 cf_status_register;



void cf_initialize_status_manager( void )
{
   cf_status_register = 0;
}

void cf_set_interrupt_status_bit( uint32 status_bit )
{
      cf_status_register |= status_bit;

}

void cf_set_status_bit( uint32 status_bit )
{
   CyGlobalIntDisable;
   cf_status_register |= status_bit;
   CyGlobalIntEnable;
}


uint32 cf_get_status( )
{
   int return_value;
   CyGlobalIntDisable;
   // add interrupt protoection
   return_value = cf_status_register;
   cf_status_register = 0;
   CyGlobalIntEnable;
   return return_value;
}
             
  



