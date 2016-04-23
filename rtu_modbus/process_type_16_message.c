/*
**
** File: process_type_16_message.c
**
**
Query
Slave Address 11
Function 10
Starting Address Hi 00
Starting Address Lo 01
No. of Registers Hi 00
No. of Registers Lo 02
Byte Count 04
Data Hi 00
Data Lo 0A
Data Hi 01
Data Lo 02
Error Check (LRC or CRC) ––    
    
Response
Slave Address 11
Function 10
Starting Address Hi 00
Starting Address Lo 01
No. of Registers Hi 00
No. of Registers Lo 02
Error Check (LRC or CRC) ––    
    




**
**
*/




#include <device.h>
#include "process_type_16_message.h" 
#include "modbus_interface_functions.h"
#include "modbus_utilities.h"

#define SWAP_16 0
#define SWAP_32 1

typedef uint16 (*FN_16)( uint8 *buffer );

typedef struct
{
    unsigned start_register;
    unsigned register_count;
    unsigned swap_type;
    FN_16   access;
    
}TYPE_16_STRUCT;      


static const TYPE_16_STRUCT type_16_access_functions[] = 
{
    { 20,3,SWAP_16, mod_store_current_time  }
};
        



#define TABLE_LENGTH   sizeof(type_16_access_functions)/sizeof(TYPE_16_STRUCT)

static  const TYPE_16_STRUCT *find_access_function( unsigned start_register, unsigned number );


int process_type_16_message( int in_length, uint8 *in, int out_length, uint8 *out )
{

    unsigned working_register;
    unsigned number_of_registers;
    unsigned count;
    unsigned i;
    unsigned swap_inc;
    const TYPE_16_STRUCT     *acc_struct;
    uint8    *ref_pointer;
    
    
    
    *out++           = *in;
    working_register = (*in++)*256;
    *out++           = *in;
    working_register += (*in++);
    *out++           = *in;
    number_of_registers = (*in++)*256;
    *out++           = *in;
    number_of_registers += (*in++);
    count       = 4;
    in++;   // skip byte count;
    ref_pointer = in;
    
    acc_struct = find_access_function( working_register, number_of_registers );
    
    if( acc_struct != NULL )
    {
        
        switch( acc_struct->swap_type)
        {
            case SWAP_16:
                swap_inc = 2;
                break;
            case SWAP_32:
                swap_inc = 4;
                break;
            default:
                // should not happen
                count = 0;
                goto error;
         }
        for( i = 0; i< number_of_registers; i+= swap_inc )
        {
            switch( acc_struct->swap_type)
            {
               case SWAP_16:
                  swap_16( in );
                  break;
               case SWAP_32:
                 swap_32( in);
                 break;
            default:
                // should not happen
                count = 0;
                goto error;
             }
             in += swap_inc;
         }
         acc_struct->access( in );
    }
    else
    {
        goto error;  // no register
    }
        
    return  count;
error:
    return 0;     
     
}    
                                                    
const TYPE_16_STRUCT * find_access_function( unsigned start_register, unsigned number )
{
   unsigned i;
   const TYPE_16_STRUCT *access_ptr;
   
   access_ptr = &type_16_access_functions[0];
   for( i = 0; i < TABLE_LENGTH; i++ )
   {
       if( (  access_ptr->start_register == start_register ) && (access_ptr->register_count == number))
       {
          return access_ptr;
       }
    }
    return NULL;
    
    
} 