
/*
**
** File: process_modbus_message.h
**
**/

#ifndef _PROCESS_MODBUS_MESSAGE_H_
#define _PROCESS_MODBUS_MESSAGE_H_
    
#include <device.h>

    
#define MODBUS_REGISTER_LENGTH 256

/*
**
** Modbus Register Definitions
**
*/ 


    
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
#define ACTIVE_FLAG                 30
#define LOGGING_FLAG                31
#define LOGGING_INDEX               32
#define LOGGING_RATE                33
#define NEW_MOISTURE_DATA           34


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
#define MOISTURE_SENSOR_9_FLOAT         66
#define MOISTURE_SENSOR_10_FLOAT         68
#define MOISTURE_SENSOR_11_FLOAT         70
#define MOISTURE_SENSOR_12_FLOAT         72
#define MOISTRUE_SENSOR_13_FLOAT         74
#define MOISTURE_SENSOR_14_FLOAT         76
#define MOISTURE_SENSOR_15_FLOAT         78


// CONFIGURATION DATA
#define MOISTURE_SENSOR_1_CONFIGURATION    80
#define MOISTURE_SENSOR_2_CONFIGURATION    81
#define MOISTURE_SENSOR_3_CONFIGURATION    82 
#define MOISTURE_SENSOR_4_CONFIGURATION    83
#define MOISTURE_SENSOR_5_CONFIGURATION    84
#define MOISTURE_SENSOR_6_CONFIGURATION    85
#define MOISTURE_SENSOR_7_CONFIGURATION    86
#define MOISTURE_SENSOR_8_CONFIGURATION    87
#define MOISTURE_SENSOR_9_CONFIGURATION    88
#define MOISTURE_SENSOR_10_CONFIGURATION    89
#define MOISTURE_SENSOR_11_CONFIGURATION    90
#define MOISTURE_SENSOR_12_CONFIGURATION    91 
#define MOISTURE_SENSOR_13_CONFIGURATION    92
#define MOISTURE_SENSOR_14_CONFIGURATION    93
#define MOISTURE_SENSOR_15_CONFIGURATION    94
#define MOISTURE_SENSOR_16_CONFIGURATION    95

#define MOISTURE_TEMP_CALIBRATION_A        100
#define MOISTURE_TEMP_CALIBRATION_B        102

//  Moisture Sensor Data
#define REFERENCE_RESISTOR_1_FLOAT         110
#define REFERENCE_RESISTOR_2_FLOAT         112
#define REFERENCE_RESISTOR__3_FLOAT        114
#define REFERENCE_RESISTOR_4_FLOAT         116
#define REFERENCE_RESISTOR_5_FLOAT         118
#define REFERENCE_RESISTOR_6_FLOAT         120
#define REFERENCE_RESISTOR_7_FLOAT         122
#define REFERENCE_RESISTOR_8_FLOAT         124   
#define REFERENCE_RESISTOR_9_FLOAT         126
#define REFERENCE_RESISTOR_10_FLOAT        128
#define REFERENCE_RESISTOR_11_FLOAT        130
#define REFERENCE_RESISTOR_12_FLOAT        132
#define REFERENCE_RESISTOR_13_FLOAT        134
#define REFERENCE_RESISTOR__14_FLOAT       136
#define REFERENCE_RESISTOR__15_FLOAT       138


    



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
uint16 *get_modbus_register_address();

    
    
#endif