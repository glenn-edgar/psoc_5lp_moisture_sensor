
"""
File: psoc_moisture_sensor.py
This file is the modbus client for the 5lp moisture sensor.


This Class is a super class to PSOC_BASE_RTU

Additional Modbus Registers are 

       
         
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
#define MOISTURE_SENSOR_2_CONFIGURATION    82
#define MOISTURE_SENSOR_3_CONFIGURATION    84 
#define MOISTURE_SENSOR_4_CONFIGURATION    86
#define MOISTURE_SENSOR_5_CONFIGURATION    88
#define MOISTURE_SENSOR_6_CONFIGURATION    90
#define MOISTURE_SENSOR_7_CONFIGURATION    92
#define MOISTURE_SENSOR_8_CONFIGURATION    94

#define MOISTURE_TEMP_CALIBRATION_A        100
#define MOISTURE_TEMP_CALIBRATION_B        102


Registers which can be changes are through type 16 messages
Additional type 16 messages are

Application level changes
    set_moisture_sampling_rate          
    write clear logging data
    clear_moisture_log_data          
    update_moisture_sensor_configuration             
    force_moisture_reading      
   
Special Type 33 message is used to read log data
Read Log Data    
   read moisture data in eeprom

Python Functions are provided for all common accesses

"""
import datetime
from  psoc_rtu_base import *

class PSOC_MOISTURE_UNIT(PSOC_BASE_RTU):
    
   def __init__(self,instrument):
       self.system_id = 0x201
       PSOC_BASE_RTU.__init__( self, instrument, self.system_id)
       
       # additional write address definitions definitions
       self.moisture_sampling_rate_address                   = 30  
       self.clear_moisture_log_address                       = 31
       self.update_moisture_sensor_configuration_address     = 32    
       self.force_moisture_reading_address                   = 33
       
       # Moisture Control
       self.moisture_control_start   =    30
       self.moisture_control_list    =  [
                                    "ACTIVE_FLAG",
                                    "LOGGING_FLAG",                
                                    "LOGGING_INDEX",               
                                    "LOGGING_RATE",                
                                    "NEW_MOISTURE_DATA"           

                               ]
                               
       # Moisture Data
       self.moisture_data_start  =    22                   
       self.moisture_data_list = [  
                                     "MOISTURE_TEMP_DC_MIN",
                                     "MOISTURE_TEMP_AC_MIN",      
                                     "MOISTURE_TEMP_DC_SEC",      
                                     "MOISTURE_TEMP_AC_SEC",      
                                     "MOISTURE_SENSOR_1",         
                                     "MOISTURE_SENSOR_2",         
                                     "MOISTURE_SENSOR_3",         
                                     "MOISTRUE_SENSOR_4",         
                                     "MOISTURE_SENSOR_5",         
                                     "MOISTURE_SENSOR_6",         
                                     "MOISTURE_SENSOR_7",        
                                     "MOISTURE_SENSOR_8",           
                                     "INTERNAL_RESISTANCE"      
                                  ]
     
     
       # Moisture Configuration Data
       self.moisture_configuration_start  =    80
       self.moisture_configuration_list   =    [
                                  "MOISTURE_SENSOR_1_CONFIGURATION",
                                  "MOISTURE_SENSOR_2_CONFIGURATION",
                                  "MOISTURE_SENSOR_3_CONFIGURATION", 
                                  "MOISTURE_SENSOR_4_CONFIGURATION", 
                                  "MOISTURE_SENSOR_5_CONFIGURATION",
                                  "MOISTURE_SENSOR_6_CONFIGURATION",
                                  "MOISTURE_SENSOR_7_CONFIGURATION",
                                  "MOISTURE_SENSOR_8_CONFIGURATION"

                                ]
 
       # Temperature Configuration Data
       self.temperature_configuration_start  =    100
       self.temperature_configuration_list   =    [
                                                 "CALIBRATION_A",        
                                                 "CALIBRATION_B"
                                               ]
       
       
 


   # 
   #
   #  Read Variables
   #
   #
 
 


   def read_moisture_control(self, address ):
       return_value = {}
       data =  self.instrument.read_registers( address,  self.moisture_control_start, len(self.moisture_control_list)  , 3 ,False)

       for i in range(0,len(self.moisture_control_list)):
          
           return_value[  self.moisture_control_list[i]  ] = data[i]
           
       return return_value
       


       
   def read_moisture_data( self ,address ):
        return_value = {}
        data =  self.instrument.read_floats( address,  self.moisture_data_start ,len(self.moisture_data_list)  )
        for i in range(0,len(self.moisture_data_list)):
           return_value[ self.moisture_data_list[i] ]  = data[i]
        return return_value
        
        
      
      
      
      
        
   def read_moisture_configuration( self, address ):
       return_value = {}

       data = self.instrument.read_floats( address,self.moisture_configuration_start,len(self.moisture_configuration_list) )
       print "data",data
       for i in range( 0,len(self.moisture_configuration_list)):
           return_value[ self.moisture_configuration_list[i] ] = data[i]
       return return_value
       
   def read_temperature_configuration( self, address ):
       return_value = {}

       data = self.instrument.read_floats( address,self.temperature_configuration_start,len(self.temperature_configuration_list) )
 
       for i in range( 0,len(self.temperature_configuration_list)):
           return_value[ self.temperature_configuration_list[i] ] = data[i]
       return return_value
      

          
  

   #####
   ##### Write Commands
   #####
 
   
   def set_moisture_sampling_rate( self, address, sampling_rate = 60): #sampling rate is in minutes
         self.instrument.write_registers(address, self.moisture_sampling_rate_address, [sampling_rate] )
         
   def clear_moisture_log( self, address):
         self.instrument.write_registers(address, self.clear_moisture_log_address, [0] )
       
   def update_moisture_sensor_data( address, sensor_data ): # sensor data consisting of 0,1,2
        if len( sensor_data) != self.sensor_length :
            raise
        valid_data = set([0,1,2])
        for i in sensor_data:
          if i not in valid_data:
             raise
          
        self.instrument.write_registers( address, self.update_moisture_sensor_configuration_address ,data)
  
   def force_moisture_reading( self,address ):
       self.instrument.write_registers( address, self.force_moisture_reading_address, [0])

 
             
   #
   #  EEPROM Header Mapping
   #define EEPROM_INITIALIZATION_INDEX      0 
   #define EEPROM_INITIALIZATION_VALUE      0xa5a55a5a
   #define EEPROM_NUMBER_OF_SENSORS         4
   #define EEPROM_SAMPLING_RATE             8
   #define EEPROM_LOGGING_INDEX            12
   #define EEPROM_MAX_NUMBER_OF_ENTRIES    16

   def read_log_data( self, address ):
           return_value = {}
           #read header
           data = self.instrument.read_floats( address,0,5 ,functioncode = 34 )
           print "data",data
           return_value["initialization"]    = int(data[0])
           return_value["number_of_sensors"] = int(data[1])
           return_value["sampling_rate"]     = int(data[2])
           return_value["logging_index"]     = int(data[3])
           return_value["max_samples"]       = int(data[4])
           return_value["data"]              = []
           number_of_sensors = int(data[1])
           number_of_logs    = int(data[3])
           data_start = 10
           for i in range( 0, number_of_logs):
               data = self.instrument.read_floats(address,data_start, number_of_sensors) 
               data_start = data_start+number_of_sensors*4
               return_value["data"].append(data)
           return return_value
        
 
if __name__ == "__main__": 
       import new_instrument
       import time
       new_instrument  =  new_instrument.new_instrument( "COM4" ) 
     
       psoc_moisture = PSOC_MOISTURE_UNIT( new_instrument )
       psoc_moisture.update_current_time( 30 )
       print psoc_moisture.read_moisture_control( 30 )
       print psoc_moisture.read_moisture_configuration( 30 )
       print psoc_moisture.read_temperature_configuration(30)
       print psoc_moisture.read_moisture_data(30)
       print psoc_moisture.read_log_data( 30 )
     
       

