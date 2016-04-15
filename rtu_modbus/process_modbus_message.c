/*
**
** File: process_modbus_message.c
** This file processes the modbus message from
** either the usb or serial handler
**
*/


#include <device.h>
#include "process_modbus_message.h"
#include "modbus_low_level_functions.h"
#include "modbus_implementation.h"

#define TYPE_3_MESSAGES 0
#define TYPE_16_MESSAGES 0
#define TYPE_22_MESSAGES 0
#define TYPE_23_Messages 0
#define TYPE_24_Messages 0

static int process_type_3_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );
static int process_type_16_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );
static int process_type_22_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );
static int process_type_23_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );
static int process_type_24_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );

int process_modbus_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
	int out_length;
	int function_code = 0;
	out_length = 0;
	
	// check crc //
	if( crc_ok != 0)
	{
		;
		// extract function code
		switch( function_code )
		{


#if TYPE_3_MESSAGES 
			
			case 3:
			        out_length = process_type_3_message( in_message_length, in_message, out_buffer_length, out_buffer );
				break;
#endif

#if TYPE_16_MESSAGES 
			
			case 16:
			        out_length = process_type_16_message( in_message_length, in_message, out_buffer_length, out_buffer );
				break;

#endif
#if TYPE_22_MESSAGES 
			case 22:
			        out_length = process_type_22_message( in_message_length, in_message, out_buffer_length, out_buffer );
				break;

#endif

#if TYPE_23_Messages 
			case 23:
			        out_length = process_type_23_message( in_message_length, in_message, out_buffer_length, out_buffer );
				break;

#endif
#if TYPE_24_Messages 			
			case 24:
			        out_length = process_type_24_message( in_message_length, in_message, out_buffer_length, out_buffer );
				break;

				break;
#endif			
			default:
				; // bad message
		}
	}
	return out_length;
}

#if TYPE_3_MESSAGES 
static int process_type_3_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
     // if find address
     // then execute address
}
#endif
#if TYPE_16_ESSAGES 
static int process_type_16_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
     // if find address
     // then execute address
}
#endif
#if TYPE_22_MESSAGES 
static int process_type_22_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
     // if find address
     // then execute address
}
#endif
#if TYPE_23_MESSAGES 
static int process_type_23_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
     // if find address
     // then execute address
}
#endif
#if TYPE_24_MESSAGES 
static int process_type_24_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer )
{
     // if find address
     // then execute address
}
#endif	
	