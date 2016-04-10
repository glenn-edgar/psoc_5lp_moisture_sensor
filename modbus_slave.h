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

#ifndef _MODBUS_SLAVE_H_
#define _MODBUS_SLAVE_H_

#include "device.h"
#include <stdlib.h>
    
#define MODBUS_ALL_ADDRESSES         1
#define MODBUS_SPECIFIC_ADDRESSES    0
    
void initialize_modbus_slave( void );    
    
void store_modbus_registers( int number, int starting_reg, int *values );

// return actual_number
int get_modbus_registers( int number, int starting_reg, int values );
    

int process_modbus_message( int address_type, int modbus_address,  int input_number, uint8* input_buffer, int max_out_size, uint8 *output_buffer );
    
#endif



/* [] END OF FILE */
