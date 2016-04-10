/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "device.h"
#include <stdlib.h>
#include "modbus_slave.h"

void initialize_modbus_slave( void )
{
    ;
}
    
void store_modbus_registers( int number, int starting_reg, int *values )
{
 ;   
}

// return actual_number
int get_modbus_registers( int number, int starting_reg, int values )
{
  return 0; 
}
    

int process_modbus_message( int address_type, int addres, int input_number, uint8* input_buffer, int max_out_size, uint8 *output_buffer )
{
    int i;
    if( input_number > max_out_size )
    {
        input_number = max_out_size;
    }
    for( i=0;i<input_number; i++)
    {
        *output_buffer++ = *input_buffer++;
    }
    return input_number;
}

/* [] END OF FILE */
