/*
** File:  cb_logging.c
** Handles EEPROM Moisture Logging
**
*/
#include <device.h>
#include "cb_logging.h"

/*
Layout of EEPROM Format  in 4 bytes value
position 0 -- Initialization Flag  0xa5a55a5a
position 4 -- Number of 4 byte entries per entry 
position 8 -- Time in Minutes Between Logging Interval
position 12 --  Current Logged Number
position 16 --  start of Logging Data
position 16 + number of log elements * 4  -- start of Second Logs


 */




static int validate_eeprom( void );



void initialize_eeprom_logging( uint32 number_of_sensors, uint32 sample_time_interval )
{
    // Start up EEPROM
    uint32 zero;
    uint32 init_value;
    uint32 max_log_number;
    
    
    max_log_number = ( EEPROM_1_EEPROM_SIZE - EEPROM_LOG_DATA_START_INDEX)/( number_of_sensors * 4 );
    
    init_value = EEPROM_INITIALIZATION_VALUE;
    zero = 0;
    EEPROM_1_Start();
    EEPROM_1_UpdateTemperature();
    write_32_eeprom( EEPROM_INITIALIZATION_INDEX, (uint8 *) init_value );
    write_32_eeprom( EEPROM_NUMBER_OF_ENTRIES, ( uint8 *)number_of_sensors );
    write_32_eeprom( EEPROM_SAMPLING_RATE, (uint8 *)&sample_time_interval );
    write_32_eeprom( EEPROM_LOGGING_INDEX, (uint8 *) zero );
    write_32_eeprom( EEPROM_MAX_NUMBER_OF_ENTRIES,(uint8 *) max_log_number );
}

void log_data( uint32 sensor_position, float value )
{
    uint32 number_of_sensors;
    uint32 logging_index;
    uint32 position_index;
    if( validate_eeprom() )
    {
         read_32_eeprom( EEPROM_NUMBER_OF_ENTRIES, (uint8 *)&number_of_sensors );
         if( sensor_position < number_of_sensors )
         {
             read_32_eeprom( EEPROM_LOGGING_INDEX, (uint8 *) &logging_index  );
             position_index = EEPROM_LOG_DATA_START_INDEX  + ( number_of_sensors *4*logging_index )+(sensor_position *4 );
             write_32_eeprom( position_index , (uint8 *) &value );
         }
    }
}
       
void advance_index( void )
{
    uint32 log_index;
    uint32 max_index;
    log_index = 0; // remove warning
    max_index = 0; // remove warning
    if( validate_eeprom() )
    {
        
       read_32_eeprom( EEPROM_LOGGING_INDEX, (uint8 *)&log_index );
       read_32_eeprom(EEPROM_MAX_NUMBER_OF_ENTRIES, (uint8 *)max_index);
       log_index = log_index +1;
       if( log_index < max_index )
       {
          write_32_eeprom(  EEPROM_LOGGING_INDEX, (uint8 *) log_index);
        
       }
    }
}
        


void write_32_eeprom( int eeprom_position, uint8 *value )
{
  EEPROM_1_WriteByte( *value++, eeprom_position++ );
  EEPROM_1_WriteByte( *value++, eeprom_position++ );
  EEPROM_1_WriteByte( *value++, eeprom_position++ );
  EEPROM_1_WriteByte( *value++, eeprom_position++ );
}

void read_32_eeprom( int eeprom_position, uint8 *value )
{
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
}

void read_16_eeprom( int eeprom_position, uint8 *value )
{
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
   EEPROM_1_WriteByte( *value++, eeprom_position++ );
}  

// this function treats eeprom as a 16 bit modbus registes
int get_modbus_eeprom_registers( unsigned starting_register, unsigned number, uint16 *out )
{
    unsigned i;
    int return_value;
      
    
    starting_register = starting_register;
    number            = number;
    if( ( starting_register + number ) < EEPROM_1_EEPROM_SIZE )
    {
        for( i= starting_register*2 ; i < number*2 ; i+=2 )
        {
           read_16_eeprom( i, (uint8 *)out );
           out++;
        }
       
        return_value = 1;
        
    }
    else
    {
        return_value = 0;
    }
    return return_value;
}


static int validate_eeprom( void )
{
    uint32 value;
    int    return_value;
    
    value = 0;  // remove warning
    read_32_eeprom( EEPROM_INITIALIZATION_INDEX, ( uint8 *)value );
    if( value == EEPROM_INITIALIZATION_VALUE )
    {
        return_value = 1;
    }
    else
    {
        return_value = 0;
    }
    return return_value;
    
}


