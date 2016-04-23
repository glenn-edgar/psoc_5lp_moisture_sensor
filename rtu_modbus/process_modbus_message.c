/*
**
** File: process_modbus_message.c
** This file processes the modbus message from
** either the usb or serial handler
**
*/


#include <device.h>
#include <assert.h>

#include "process_crc.h"
#include "process_type_3_message.h"
#include "process_type_16_message.h"
#include "process_type_24_message.h"

#include "process_modbus_message.h"




int process_modbus_message( int in_length, uint8 *in_buffer, 
                            int out_buffer_length, uint8 *out_buffer )
{
	
	int function_code    = 0;
    int crc_ok;
    int out_length;
    int status;
 
	status = 0;
    crc_ok =  compute_crc( in_length, in_buffer);

	if( crc_ok != 0)
	{
		function_code = in_buffer[1];
        out_buffer[0] = in_buffer[0];  // returning slave address
        out_buffer[1] = out_buffer[1]; // returning function code
        out_buffer_length -=2;
        in_length         -=4;  // removing slave address, function code and 16 bit crc
		// extract function code
		switch( function_code )
		{
            case 3:
                    out_length = process_type_3_message( in_length, in_buffer, out_buffer_length-2,
                                                     &out_buffer[2]);
                    break;
            
            case 16:
                    out_length = process_type_16_message( in_length, in_buffer,out_buffer_length-2,
                                                     &out_buffer[2]);
                    break;
            
            case 24:
                    out_length = process_type_24_message( in_length, in_buffer, out_buffer_length, 
                                   &out_buffer[2]);
                    break;
            default:
                    out_length = 0;
        }
        
        if(  out_length >= 0 )
        {
            out_length += 2; // putting back slave and function id into count
            append_crc( out_length,out_buffer);
            status = 1;
        }
        
        
    }
    return status;
    
}    

