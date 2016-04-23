/*
**
** File: process_modbus_message.h
**
**/

#ifndef _PROCESS_MODBUS_MESSAGE_H_
#define _PROCESS_MODBUS_MESSAGE_H_
    
/*



    

    
    



 
*/
#include <device.h>
// return out message length or 0 if error 
int process_modbus_message( int in_message_length, uint8 *in_message, int out_buffer_length, uint8 *out_buffer );


    
    
#endif