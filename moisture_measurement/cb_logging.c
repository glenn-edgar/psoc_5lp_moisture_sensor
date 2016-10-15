/*
** File:  cb_logging.c
** Handles EEPROM Moisture Logging
**
*/
#include <device.h>
#include "cb_logging.h"
#include "process_modbus_message.h"

/*
Layout of EEPROM Format  in 4 bytes value
position 0 -- Initialization Flag  0xa5a55a5a
position 4 -- Number of 4 byte entries per entry 
position 8 -- Time in Minutes Between Logging Interval
position 12 --  Current Logged Number
position 16 --  start of Logging Data
position 16 + number of log elements * 4  -- start of Second Logs


 */
 

static const uint16 sampling_interval   = 2;  // for production use 60 or 1 hour


const float reference_resistance_array [ MOISTURE_SENSOR_NUMBER ] = 
{
  9930.,  // 0
  9930.,  // 1
  9930.,  // 2 
  9930.,  // 3
  9930.,  // 4
  9930.,  // 5
  9930.,   // 6
  9930.,   // 7
  9930.   // 8
  
};



const uint16 moisture_configuration_data[ MOISTURE_SENSOR_NUMBER ] =
{
   WATER_MARK,
   WATER_MARK,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
   RESISTIVE_ELEMENT,
    
};

#define CALIBRATION_NUMBER 1
    
#define CALIBRATION_ARRAY_LENGTH  CALIBRATION_NUMBER *2
// temperature calibration in degrees F
const float temperature_calibration_factors[CALIBRATION_NUMBER *2] = { (.18), -58. };

static void write_32_eeprom( int eeprom_position, float value );
static float read_32_eeprom( int eeprom_position );
static int validate_eeprom( void );
static void initialize_shaddow_ram_buffer( void );

static uint8 shaddow_eeprom[EEPROM_1_EEPROM_SIZE];

float get_reference_resistor( uint32 channel )
{
    uint16 return_value;
    if( channel >= MOISTURE_SENSOR_NUMBER )
    {
        CYASSERT(0);
    }
    else
    {
        return_value =reference_resistance_array[ channel];
    }
    return return_value;
}

uint16 get_moisture_sensor_configuration( unsigned sensor_id )
{
    uint16 return_value;
    if( sensor_id >= MOISTURE_SENSOR_NUMBER )
    {
        CYASSERT(0);
    }
    else
    {
        return_value = moisture_configuration_data[ sensor_id];
    }
    return return_value;
}

int store_default_temperature_calibration_values_to_modbus_registers(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    store_modbus_data_registers( MOISTURE_TEMP_CALIBRATION_A, CALIBRATION_ARRAY_LENGTH *2 , (uint16*)temperature_calibration_factors);
    return 0;
}

int store_default_resistor_calibration_values_to_modbus_registers(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    store_modbus_data_registers( REFERENCE_RESISTOR_1_FLOAT, MOISTURE_SENSOR_NUMBER *2 , (uint16*)reference_resistance_array);
    return 0;
}

int reset_eeprom_log(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    float temp32;
    uint16 temp16;
    temp16 = 0;
    store_modbus_data_registers( LOGGING_INDEX, 1,&temp16 );
    temp32 = temp16;
    write_32_eeprom( EEPROM_LOGGING_INDEX , temp32 );
    return 0;
}



int enable_eeprom(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    uint16 temp;
    
    EEPROM_1_Start() ;
    EEPROM_1_UpdateTemperature();
    initialize_shaddow_ram_buffer();  
    store_modbus_data_registers( LOGGING_RATE  , 1,(uint16 *) &sampling_interval );  
    store_modbus_data_registers( MOISTURE_SENSOR_1_CONFIGURATION , sizeof(moisture_configuration_data)/sizeof(uint16),(uint16 *) moisture_configuration_data ); 
    temp = 0;
    store_modbus_data_registers( LOGGING_INDEX, 1, (uint16 *) &temp ); 
    initialize_eeprom_logging( MOISTURE_SENSOR_NUMBER, sampling_interval );
    return 0;

}

int update_reference_resistor_configuration(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    const uint16 *modbus_address;
    uint8 *buffer;
    CyGlobalIntDisable
    modbus_address = get_modbus_register_address();
    buffer = (uint8 *)&modbus_address[REFERENCE_RESISTOR_1_FLOAT];
    //cystatus Em_EEPROM_1_Write(const uint8 srcBuf[], const uint8 eepromPtr[], uint32 byteCount);
    Em_EEPROM_1_Write((uint8 *) reference_resistance_array,buffer, sizeof(reference_resistance_array));
    CYGlobalIntEnable
    return 1;
}

int update_moisture_configuration(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    const uint16 *modbus_address;
    uint8 *buffer;
    CyGlobalIntDisable
    modbus_address = get_modbus_register_address();
    buffer = (uint8 *)&modbus_address[MOISTURE_SENSOR_1_CONFIGURATION];
    //cystatus Em_EEPROM_1_Write(const uint8 srcBuf[], const uint8 eepromPtr[], uint32 byteCount);
    Em_EEPROM_1_Write((uint8 *) moisture_configuration_data,buffer, sizeof(moisture_configuration_data));
    CYGlobalIntEnable
    return 1;
}



int update_temperature_configuration(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    const uint16 *modbus_address;
    uint8 *buffer;
    CyGlobalIntDisable
    modbus_address = get_modbus_register_address();
    buffer = (uint8 *)&modbus_address[MOISTURE_TEMP_CALIBRATION_A];
    //cystatus Em_EEPROM_1_Write(const uint8 srcBuf[], const uint8 eepromPtr[], uint32 byteCount);
    Em_EEPROM_1_Write((uint8 *) temperature_calibration_factors,buffer, sizeof(temperature_calibration_factors));
    CYGlobalIntEnable
    return 1;
}


int update_measurement_rate(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

    
    float data_float;
    data_float = data;
   
    write_32_eeprom(  EEPROM_SAMPLING_RATE, data_float );
    return 0;
}






void initialize_eeprom_logging( uint32 number_of_sensors, uint32 sample_time_interval )
{
    // Start up EEPROM
    float zero;
    float init_value;
    float max_log_number;
    float sample_time_float;
    float number_of_sensors_float;
    int   validate_flag;
   
    
    sample_time_float = sample_time_interval;
    number_of_sensors_float = number_of_sensors;
    
    
    
    max_log_number = ( EEPROM_1_EEPROM_SIZE - EEPROM_LOG_DATA_START_INDEX)/( number_of_sensors * 4 );
    validate_flag = validate_eeprom();
    if( validate_flag == 0 )
    {
   
        init_value = EEPROM_INITIALIZATION_VALUE;
        zero = 0;
        write_32_eeprom( EEPROM_INITIALIZATION_INDEX, init_value );
       
        write_32_eeprom( EEPROM_NUMBER_OF_ENTRIES, number_of_sensors_float );
        write_32_eeprom( EEPROM_SAMPLING_RATE, sample_time_float );
        write_32_eeprom( EEPROM_LOGGING_INDEX,  zero );
        write_32_eeprom( EEPROM_MAX_NUMBER_OF_ENTRIES, max_log_number );
    }
}

void log_data( uint32 sensor_position, float value )
{
    uint32 number_of_sensors;
    uint32 logging_index;
    uint32 position_index;
    if( validate_eeprom() )
    {
         number_of_sensors = read_32_eeprom( EEPROM_NUMBER_OF_ENTRIES );
         if( sensor_position < number_of_sensors )
         {
             logging_index = read_32_eeprom( EEPROM_LOGGING_INDEX );
             position_index = EEPROM_LOG_DATA_START_INDEX  + ( number_of_sensors *4*logging_index )+(sensor_position *4 );
             write_32_eeprom( position_index , value );
         }
    }
}
       
void advance_index( void )
{
    uint32 log_index;
    uint32 max_index;
    float  log_index_float;
    log_index = 0; // remove warning
    max_index = 0; // remove warning
    if( validate_eeprom() )
    {
        
       log_index = read_32_eeprom( EEPROM_LOGGING_INDEX);
       max_index = read_32_eeprom(EEPROM_MAX_NUMBER_OF_ENTRIES );
       log_index_float = log_index +1;
       if( log_index < max_index )
       {
          write_32_eeprom(  EEPROM_LOGGING_INDEX,  log_index_float);
        
       }
    }
}

// this function treats eeprom as a 16 bit modbus registes
int get_modbus_eeprom_registers( unsigned starting_register, unsigned number, uint16 *out )
{

    int return_value;
      
    
    starting_register = starting_register*2;
    number = number *sizeof(uint16)/sizeof(uint8);

    if( ( starting_register + number ) < EEPROM_1_EEPROM_SIZE )
    {
      memcpy( out, &shaddow_eeprom[starting_register], number );        
      return_value = 1;
        
    }
    else
    {
        return_value = 0;
    }
    return return_value;
}

/*
**
**  Static Functions
**
**
**
*/

static void initialize_shaddow_ram_buffer( void )
{
    unsigned i;
    for( i = 0; i< EEPROM_1_EEPROM_SIZE; i++ )
    {
        shaddow_eeprom[i] = EEPROM_1_ReadByte(i);
    }
}



static void write_32_eeprom( int eeprom_position, float value_float )
{
  uint8 *value;
  value = (uint8 *)&value_float;
  EEPROM_1_WriteByte( *value, eeprom_position );
  shaddow_eeprom[eeprom_position++] = *value++;
  EEPROM_1_WriteByte( *value, eeprom_position );
  shaddow_eeprom[eeprom_position++] = *value++;
  EEPROM_1_WriteByte( *value, eeprom_position );
  shaddow_eeprom[eeprom_position++] = *value++;
  EEPROM_1_WriteByte( *value, eeprom_position );
  shaddow_eeprom[eeprom_position++] = *value++;

}

static float read_32_eeprom( int eeprom_position )
{
   float return_value;
   uint8 *temp;
   temp = (uint8 *)&return_value;
   *temp++ = EEPROM_1_ReadByte(  eeprom_position++ );
   *temp++ = EEPROM_1_ReadByte( eeprom_position++ );
   *temp++ = EEPROM_1_ReadByte( eeprom_position++ );
   *temp++ = EEPROM_1_ReadByte( eeprom_position++ );
   return return_value;
}







static int validate_eeprom( void )
{
    uint32 value;
    int    return_value;
    
   
    value = read_32_eeprom( EEPROM_INITIALIZATION_INDEX );
    if( value == (uint32) EEPROM_INITIALIZATION_VALUE )
    {
        return_value = 1;
    }
    else
    {
        return_value = 0;
    }
    return return_value;
    
}






