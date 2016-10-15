/*
   File cb_logging.h
*/

#ifndef CB_LOGGING_H
#define CB_LOGGING_H

#include <device.h>


#define EEPROM_INITIALIZATION_INDEX      0 
#define EEPROM_INITIALIZATION_VALUE      33.3334
#define EEPROM_NUMBER_OF_ENTRIES         4
#define EEPROM_SAMPLING_RATE             8
#define EEPROM_LOGGING_INDEX            12
#define EEPROM_MAX_NUMBER_OF_ENTRIES    16
#define EEPROM_LOG_DATA_START_INDEX     20
    
#define MOISTURE_SENSOR_NUMBER           9

    



typedef enum 
{
                NOT_POPULATED       = 0 ,
                RESISTIVE_ELEMENT   = 1,
                WATER_MARK          = 2 ,

    
} MOISTURE_SENSOR_TYPE;
    
/*
    The Following Functions are defined in cf_external_functions.h to support chain_flow processing
    
enable_eeprom
reset_eeprom_log
update_measurement_rate
 
    
    
    
    

** eeprom access functions
**
**
*/

void initialize_eeprom_logging( uint32 number_of_sensors, uint32 sample_time_interval );
void log_data( uint32 sensor_position, float value );
void advance_index( void );
uint16 get_moisture_sensor_configuration( unsigned sensor );
float get_reference_resistor( uint32 channel );
int get_modbus_eeprom_registers( unsigned starting_register, unsigned number, uint16 *out );




#endif