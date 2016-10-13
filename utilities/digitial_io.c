/*
File: digital_io.c

Digital functions

*/

    
#include <device.h>
 
// Masks for debounced pins
#define LOG_PIN    1
#define BOARD_PIN  2
#define ACTIVE_PIN 4



uint32 read_board_switch( void )
{
   return Status_Reg_1_Read()&BOARD_PIN; 
}

uint32 read_log_pin( void )
{
    return Status_Reg_1_Read()&LOG_PIN;
}


uint32 read_active_pin( void )
{
    return Status_Reg_1_Read()&ACTIVE_PIN;
}

