/*
**
** File: process_modbus_message.h
**
**/

#ifndef _PROCESS_MODBUS_MESSAGE_H_
#define _PROCESS_MODBUS_MESSAGE_H_

// return out message length or 0 if error 
int process_modbus_message( int in_message_length, char *in_message, int out_buffer_length, char *out_buffer );


    
    
#endif