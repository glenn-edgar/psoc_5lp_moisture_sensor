
/*
**
** File: process_modbus_message.h
**
**/

#ifndef _PROCESS_MODBUS_MESSAGE_H_
#define _PROCESS_MODBUS_MESSAGE_H_
    
#include <device.h>
    
#define MODBUS_REGISTER_LENGTH 128 

/*
**
** Modbus Register Definitions
**
*/ 

#define MOISTURE_SENSOR_NUMBER 8
typedef enum 
{
                NOT_POPULATED     = 0 ,
                RESISTIVE_ELEMENT = 1,
                WATER_MARK        = 2 
    
} MOISTURE_SENSOR_TYPE;
    
// System Definitions
    
#define MOD_UNIT_ID                     0
#define MOD_UNIT_TEMP                   1
#define MOD_RTU_WATCH_DOG_FLAG          2
#define MOD_CONTROLLER_WATCH_DOG_FLAG   3
#define MOD_COMMISSIONING_FLAG          4
#define MOD_POWER_UP_EVENT              5
#define MOD_MINUTE_ROLLOVER             6
#define MOD_DISCRETE_IO_CHANGE          7
#define MOD_YEAR                        8
#define MOD_MONTH                       9
#define MOD_DAY                        10
#define MOD_HOUR                       11
#define MOD_MINUTE                     12
#define MOD_SECOND                     13

       
         
// Logging Control
#define LOGGING_FLAG                30
#define LOGGING_INDEX               31
#define LOGGING_RATE                32
#define NEW_MOISTURE_DATA           33


//  Moisture Sensor Data
#define MOISTURE_TEMP_DC_MIN_FLOAT      40
#define MOISTURE_TEMP_AC_MIN_FLOAT      42
#define MOISTURE_TEMP_DC_SEC_FLOAT      44
#define MOISTURE_TEMP_AC_SEC_FLOAT      46
#define MOISTURE_SENSOR_1_FLOAT         50
#define MOISTURE_SENSOR_2_FLOAT         52
#define MOISTURE_SENSOR_3_FLOAT         54
#define MOISTRUE_SENSOR_4_FLOAT         56
#define MOISTURE_SENSOR_5_FLOAT         58
#define MOISTURE_SENSOR_6_FLOAT         60
#define MOISTURE_SENSOR_7_FLOAT         62
#define MOISTURE_SENSOR_8_FLOAT         64   
#define INTERNAL_RESISTANCE_FLOAT       70

// CONFIGURATION DATA
#define MOISTURE_SENSOR_1_CONFIGURATION    80
#define MOISTURE_SENSOR_2_CONFIGURATION    81
#define MOISTURE_SENSOR_3_CONFIGURATION    82 
#define MOISTURE_SENSOR_4_CONFIGURATION    83
#define MOISTURE_SENSOR_5_CONFIGURATION    84
#define MOISTURE_SENSOR_6_CONFIGURATION    85
#define MOISTURE_SENSOR_7_CONFIGURATION    86
#define MOISTURE_SENSOR_8_CONFIGURATION    87

#define MOISTURE_TEMP_CALIBRATION_A        100
#define MOISTURE_TEMP_CALIBRATION_B        102

extern uint16 const logging_flag;
extern uint16 const sampling_interval;

extern const uint16 moisture_configuration_data[ MOISTURE_SENSOR_NUMBER ];    



#define MODBUS_ARRAY_LENGTH  sizeof( modbus_address_data)/sizeof(modbus_address_data)


extern const uint16 modbus_address_data[2];

static inline uint16 get_modbus_address( void )
{
    return modbus_address_data[0];
}

static inline uint16 get_commissioning_address( void )
{
    return modbus_address_data[1];
}



void initialize_modbus_registers( void );
// return out message length or 0 if error 
int process_modbus_message( int in_message_length, uint8 *in_message, int out_buffer_length, uint8 *out_buffer );

int store_modbus_data_registers( unsigned index, unsigned length, uint16 *new_data);
int get_modbus_data_registers( unsigned index, unsigned length, uint16 *buffer );


    
    
#endif