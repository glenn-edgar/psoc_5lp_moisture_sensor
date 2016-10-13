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
#include "process_modbus_message.h"
#include "process_type_16_message.h" 
#include "modbus_interface_functions.h"
#include "modbus_utilities.h"


#include "cf_events.h"
#include "cb_logging.h"


#define SWAP_16 0
#define SWAP_32 1

// message is 2 floating point numbers, so length is 2*2 or 4 modbus registers
#define TEMPERATURE_CALIBRATION_MSG_LEN  2*2
#define REFERENCE_RESISTOR_MSG_LEN    MOISTURE_SENSOR_NUMBER*2

typedef uint16 (*FN_16)( uint8 *buffer );

typedef struct
{
    unsigned start_register;
    unsigned register_count;
    unsigned swap_type;
    FN_16   access;
    
}TYPE_16_STRUCT;      

const uint16 moisture_configuration_data[ MOISTURE_SENSOR_NUMBER ];

static uint16 clear_watch_dog_flags( uint8 * buffer )
{
    uint16 temp;
    
    temp =  0;
    store_modbus_data_registers( MOD_RTU_WATCH_DOG_FLAG, 1 , &temp);

    return 1;
}





static uint16 clear_power_up_event( uint8 *buffer )
{
    uint16 temp;
    
    temp = 0;
    store_modbus_data_registers( MOD_POWER_UP_EVENT, 1 , &temp);
    return 1;
}


static uint16 clear_minute_rollover( uint8 *buffer )
{
    uint16 temp;
    
    temp = 0;
    store_modbus_data_registers( MOD_MINUTE_ROLLOVER, 1 , &temp);
    return 1;
}

static uint16 set_controller_watch_dog_flags( uint8 * buffer )
{
    uint16 temp;
    
    temp =  1;
    store_modbus_data_registers( MOD_RTU_WATCH_DOG_FLAG, 1 , &temp);

    return 1;
}




static uint16 change_time( uint8 *buffer )
{
    uint16 *data;
    uint16 second;
    uint16 minute;
    uint16 hour;
    uint16 day;
    uint16 month;
    uint16 year;
    data = (uint16 *)buffer;
    store_modbus_data_registers(MOD_YEAR, 6, data);

    year = *data++;
    month = *data++;
    day  = *data++;
    hour = *data++;
    minute = *data++;
    second = *data++;
    
    
    RTC_1_WriteSecond(second);   
    RTC_1_WriteMinute(minute);  
    RTC_1_WriteHour( hour );
    RTC_1_WriteDayOfMonth(day);
    RTC_1_WriteMonth(month);
    RTC_1_WriteYear( year );
    return 1;

}

static uint16 change_modbus_address( uint8 *buffer )
{
    uint16 mod_commission_flag;
    uint16 return_value;
    
    get_modbus_data_registers( MOD_COMMISSIONING_FLAG, 1, &mod_commission_flag );
    
    if( mod_commission_flag != 0  )
    {
        return_value = 1;
        Em_EEPROM_1_Write( (const uint8* )buffer, (const uint8*)modbus_address_data , sizeof(modbus_address_data));
        cf_send_event(  CF_COMMISSIONING_DONE, 0 );
    }
    else
    {
        return_value = 0;
    }    
    return return_value;
}
/*
static uint16 store_calibration_variables( uint8 *buffer )
{
    uint16 *temp;
    CyGlobalIntDisable
    temp = (uint16*) buffer;
    store_modbus_data_registers( MAIN_FLOW_RATE_CALIBRATION, CALIBRATION_ARRAY_LENGTH *2 , temp);
    Em_EEPROM_1_Write( (const uint8*)buffer,(uint8*) calibration_factors, CALIBRATION_ARRAY_LENGTH*4);
    CYGlobalIntEnable
    return 1;
 
}
*/

static uint16 set_moisture_sampling_rate( uint8 *buffer )
{
    uint16 temp16;
    
    store_modbus_data_registers( LOGGING_RATE, 1, (uint16 *)buffer);
    get_modbus_data_registers( LOGGING_RATE,1, &temp16 );
    cf_send_event( CF_MEASUREMENT_RATE, temp16 );
    return 0;
}

    
static uint16 clear_moisture_log_data( uint8 *buffer )
{

    uint16 temp16;
    temp16 = 0;
    store_modbus_data_registers( LOGGING_INDEX, 1,&temp16 );
    cf_send_event( CF_RESET_LOG, 0 );
    return 1;
}



static uint16 update_moisture_sensor_configuration( uint8 *buffer )
{

   


    store_modbus_data_registers( MOISTURE_SENSOR_1_CONFIGURATION , sizeof(moisture_configuration_data)/sizeof(uint16),(uint16 *) buffer );
    cf_send_event( CF_UPDATE_MOISTURE_CONFIGURATION, 0 );

    return 1;

}

static uint16 force_moisture_reading( uint8 *buffer )
{
    cf_send_event( CF_START_MOISTURE_READING, 0 );
    return 1;
}

static uint16 update_temperature_configuration(  uint8 *buffer )
{

    

    
    store_modbus_data_registers( MOISTURE_TEMP_CALIBRATION_A ,TEMPERATURE_CALIBRATION_MSG_LEN ,(uint16 *) buffer );
    cf_send_event( CF_UPDATE_TEMPERATURE_PARAMETERS, 0 );

    return 1;

}

static uint16 update_reference_resistor( uint8 *buffer )
{

    

    
    store_modbus_data_registers( REFERENCE_RESISTOR_1_FLOAT ,REFERENCE_RESISTOR_MSG_LEN ,(uint16 *) buffer );
    cf_send_event( CF_UPDATE_REFERENCE_RESISTOR, 0 );

    return 1;

}   

#define TABLE_LENGTH 12
static const TYPE_16_STRUCT type_16_access_functions[TABLE_LENGTH] = 
{
    // System Level Writes
    { 20,    6,                                                 SWAP_16,  change_time                    },       
    { 21,    MODBUS_ARRAY_LENGTH,                               SWAP_16,  change_modbus_address          },            
    { 22,    1,                                                 SWAP_16,  clear_watch_dog_flags          },
    { 23,    1,                                                 SWAP_16,  clear_power_up_event           } ,
    { 25,    1,                                                 SWAP_16,  clear_minute_rollover          },
    { 26,    1,                                                 SWAP_16,  set_controller_watch_dog_flags  },
    // Moisture Sensor Related Writes
    // 30 write sampling index
    { 30,    1,                                                 SWAP_16,  set_moisture_sampling_rate          },
    // 31 write clear logging data
    { 31,    1,                                                 SWAP_16,  clear_moisture_log_data          },
    // 33 update moisture configuration
    { 32,     MOISTURE_SENSOR_NUMBER,                           SWAP_16,  update_moisture_sensor_configuration          },
    // 33 force mositure reading
    { 33,    1,                                                 SWAP_16, force_moisture_reading       },
    { 34,    TEMPERATURE_CALIBRATION_MSG_LEN,                   SWAP_16, update_temperature_configuration },
    { 35,    REFERENCE_RESISTOR_MSG_LEN,                       SWAP_16 , update_reference_resistor },
   
};
        


static  const TYPE_16_STRUCT *find_access_function( unsigned start_register, unsigned number );


int process_type_16_message( int in_length, uint8 *in, int out_length, uint8 *out )
{
    int       return_value;
    unsigned working_register;
    unsigned number_of_registers;
    unsigned count;
    unsigned i;
    unsigned swap_inc;
    unsigned swap_type;
    const TYPE_16_STRUCT     *acc_struct;
    uint8                    *ref_pointer;

    
    
    return_value = 0;
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

    ref_pointer =  in;
    acc_struct = find_access_function( working_register, number_of_registers );
    
    if( acc_struct != NULL )
    {
        swap_type = acc_struct->swap_type;
    }
    else
    {
        swap_type = SWAP_16;
    }
        
    switch( swap_type)
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
                return 0;
    }
    for( i = 0; i< number_of_registers*2; i+= swap_inc )
    {
            switch( swap_type)
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
                return 0;
             }
             in += swap_inc;
     }
         
     if( acc_struct != NULL )
     {
        if( acc_struct->access( ref_pointer ) )
        {
            return_value = count;
        }
        else
        {
           return_value = 0;
        }
    }
    else
    {
        return_value = 0;
 #if 0
      if( store_modbus_data_registers( working_register, number_of_registers, (uint16 *) ref_pointer) != 0 )
      {
        return_value = count;
      }
      else
      {
        return_value = 0;
      }
#endif
    }
    if( return_value > 200 )
    {
        CYASSERT(0);
    }
    return return_value;
   
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
       else
       {
          access_ptr++;
       }
    }
    return NULL;
    
    
} 