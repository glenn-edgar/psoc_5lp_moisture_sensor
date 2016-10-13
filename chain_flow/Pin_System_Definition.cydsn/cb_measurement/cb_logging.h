/*
   File cb_logging.h
*/

#ifndef CB_LOGGING_H
#define CB_LOGGING_H

#include <device.h>

#define EEPROM_INITIALIZATION_INDEX      0 
#define EEPROM_INITIALIZATION_VALUE      0xa5a55a5a
#define EEPROM_NUMBER_OF_ENTRIES         4
#define EEPROM_SAMPLING_RATE             8
#define EEPROM_LOGGING_INDEX            12
#define EEPROM_MAX_NUMBER_OF_ENTRIES    16
#define EEPROM_LOG_DATA_START_INDEX     20
    
    
/*
** eeprom access functions
**
**
*/
void write_32_eeprom( int eeprom_position, uint8* value );
void read_32_eeprom( int eeprom_position,  uint8* value );
int get_modbus_eeprom_registers( unsigned starting_register, unsigned number, uint16 *out );

void initialize_eeprom_logging( uint32 number_of_sensors, uint32 sample_time_interval );
void log_data( uint32 sensor_position, float value );
void advance_index( void );
    
#endif