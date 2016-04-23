/*
**
** File: process_type_3_message.c

Type 3 message
Query
Field Name (Hex)
Slave Address 11
Function 03
Starting Address Hi 00
Starting Address Lo 6B
No. of Points Hi 00
No. of Points Lo 03
Error Check (LRC or CRC) ––

    
Response
Slave Address 11
Function 03
Byte Count 06
Data Hi (Register 40108) 02
Data Lo (Register 40108) 2B
Data Hi (Register 40109) 00
Data Lo (Register 40109) 00
Data Hi (Register 40110) 00
Data Lo (Register 40110) 64
Error Check (LRC or CRC) ––

**
**
*/
 
#include <device.h>
#include "process_type_3_message.h" 
#include "modbus_interface_functions.h"
#include "modbus_utilities.h"

#define SWAP_16 0
#define SWAP_32 1
typedef uint16 (*FN_3)( uint8 *buffer );

typedef struct
{
    unsigned start_register;
    unsigned register_count;
    unsigned swap_type;
    FN_3   access;
    
}TYPE_3_STRUCT;      


static const TYPE_3_STRUCT type_3_access_functions[] = 
{
    { 10,1,SWAP_16, mod_access_read_temp },
    { 20,3,SWAP_16, mod_read_current_time  },
    { 40,1,SWAP_32, mod_sigma_dc },
    { 50,1,SWAP_32, mod_sigma_ac },
    { 60,1,SWAP_16, mod_sar_dc },
    { 70,1,SWAP_16, mod_sar_ac }
};
        



#define TABLE_LENGTH   sizeof(type_3_access_functions)/sizeof(TYPE_3_STRUCT)

static  const TYPE_3_STRUCT *find_access_function( unsigned start_register, unsigned number );


int process_type_3_message( int in_length, uint8 *in, int out_length, uint8 *out )
{

    unsigned working_register;
    unsigned number_of_registers;
    unsigned count;
    unsigned i;
    unsigned swap_inc;
    const TYPE_3_STRUCT     *acc_struct;
    
    
    
    
    working_register = (*in++)*256;
    working_register += (*in++);
    number_of_registers = (*in++)*256;
    number_of_registers += (*in++);
    if( out_length < (int)(number_of_registers *2))
    {
        return 0;
    }
    *out++ = number_of_registers*2;

    acc_struct = find_access_function( working_register, number_of_registers );
    
    if( acc_struct != NULL )
    {
        count = acc_struct->access( out );
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
        for( i = 0; i< count; i+= swap_inc )
        {
            switch( acc_struct->swap_type)
            {
               case SWAP_16:
                  swap_16( out );
                  break;
               case SWAP_32:
                 swap_32( out);
                 break;
            default:
                // should not happen
                count = 0;
                goto error;
             }
             out += swap_inc;
         }
    
    }
    else
    {
        goto error;  // no register
    }
        
    return  1+count; // add byte count 
error:
    return 0;     
     
}    
                                                    
const TYPE_3_STRUCT * find_access_function( unsigned start_register, unsigned number )
{
   unsigned i;
   FN_3  return_value;
   const TYPE_3_STRUCT *access_ptr;
    
   
   
   access_ptr = &type_3_access_functions[0];
   for( i = 0; i < TABLE_LENGTH; i++ )
   {
       if( (  access_ptr->start_register == start_register ) && (access_ptr->register_count == number))
       {
          return access_ptr;
       }
    }
    return NULL;
    
    
}
