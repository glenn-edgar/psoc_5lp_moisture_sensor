/*
**
** File: moisture_measurements.c
**
**
**
*/

#include <device.h>
#include "cf_external_functions.h"
#include "moisture_measurements.h"
#include "a_to_d_functions.h"
#include "cf_events.h"
#include "cb_logging.h"
#include "process_modbus_message.h"
#include "digitial_io.h"



static uint32 logging_flag;
static uint32 active_flag = 0;
static uint32 measurement_minute_count = 0;






static float moisture_meaurements[ MOISTURE_SENSOR_NUMBER ];
static float temp_c;
static float inline get_soil_temperature( void )
{
    float temp_f;
    
    
    get_modbus_data_registers( MOISTURE_TEMP_DC_SEC_FLOAT , 2, (uint16 *)&temp_f );
    if( temp_f < 0 )
    {
        temp_c = 20.0;
    }
    else
    {
        temp_c = (temp_f-32)*5.0/9.0;
    }
    return temp_c;
}


/*
**
** Routines to store data
** resistance unknow resistance equals
** reference resistance is stored in modbus location REFERENECE_RESISTANCE
** i = ( sigma_v_rail)/known_resistance
** unknown resistance = v_measurement/i
*/
static inline int store_moisture_data(unsigned current_channel, float high_voltage, float low_voltage, float sensor_voltage )
{
    float measurement;
    float source_current;
    float source_resistance;
    float reference_resistance;
    int sensor_type;
    float temperature;
    
    sensor_type = get_moisture_sensor_configuration( current_channel );
    
    reference_resistance = get_reference_resistor( current_channel );
    source_current = ((float) high_voltage -(float)sensor_voltage)/reference_resistance;
    source_resistance = (sensor_voltage - low_voltage)/source_current;
    switch( sensor_type )
    {
        case NOT_POPULATED:  // not connected sensor -- should not reach this poi
           measurement = 0;
           break;
        
        case RESISTIVE_ELEMENT:
            measurement = source_resistance;
            break;
            
        case WATER_MARK:
            temperature = get_soil_temperature();
            source_resistance = source_resistance/1000.;
            //kPa=(4.093+3.213*R)/(1-0.009733*R-0.01205*T)
            measurement = ( 4.093 + 3.213* source_resistance  )/( 1. - .009733*source_resistance - .01205* temperature );
            break;
       default:
            CYASSERT(0);
    }
    
    moisture_meaurements[ current_channel ] = measurement;
    return 0;
}





/*
**
** Public ChainFlow Functions
**
**
**
*/

/*
** Moisture Measurement Initialization Functions
**
**
**
*/

int init_moisture_processing(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   logging_flag     = 0;
   active_flag      = 0;
   measurement_minute_count = 0;

   Source_Reg_Write(0);
   Sink_Reg_Write(0);
   Sink_Source_Setup_Start();
   Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER);
   SIGMA_A_D_Start();
   SIGMA_A_D_Sleep();
   moisture_interval_clock_Stop();
   return 0;
}









CY_ISR_PROTO(process_moisture_interval_interrupt)
{
    ad_interrupt_1_ClearPending();
    cf_send_event(  CF_120HZ_TICK,0 );
}





int set_up_moisture_interrupt(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    moisture_interval_clock_Stop();
    moisture_interval_interrupt_StartEx(process_moisture_interval_interrupt);
    return 0;
}




/*
**  Monitor Pins to determine if active or if logging
**  Check to see if it is time to measure moisture
**
**
*/





int check_moisture_active_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
      uint16 temp;
      temp =  Active_Pin_Read();
      if( read_active_pin() != 0 )
      {
          active_flag = 0;
      }
      else
      {  
          active_flag = 1;
      }
      temp = active_flag;
      store_modbus_data_registers( LOGGING_FLAG, 1, &temp);

      return 0;

}


int check_logging_active_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
      uint16 temp;
      if( read_log_pin() != 0 )
      {
          logging_flag = 0;
      }
      else
      {  
          logging_flag = 1;
      }
      temp = logging_flag;
      store_modbus_data_registers( ACTIVE_FLAG, 1, &temp);

      return 0;

}




int check_for_moisture_measurement(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)





{
      uint16 minute_count_limit;
      
      if( active_flag == 0 )
      {
        measurement_minute_count = 0;
        return 0;
      }
      else
      {
        ; // no else actions
      }
      get_modbus_data_registers( LOGGING_RATE, 1, &minute_count_limit);
      if( minute_count_limit == 0 )
      {
        return 0;
      }
      else
      {
        // no else actions
      }
      
      if( measurement_minute_count >= minute_count_limit)
      {
          measurement_minute_count = 0;
          cf_send_event(CF_START_MOISTURE_READING, 0 );
      }
      else
      {
        measurement_minute_count += 1;
      }
      return 0;
}

/*
**
**  Functions to make measurements
**
**/



int remove_power(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
     Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER);
     SIGMA_A_D_Sleep();
     Sink_Reg_Write(0);
     Source_Reg_Write( 0);
     moisture_interval_clock_Stop();
    
     return 0;
}


int turn_on_timer_clock(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

    moisture_interval_clock_Start();
    return 0;
}

int set_source_channel(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    SIGMA_A_D_Wakeup();
   
    Sink_Reg_Write( 2 );
    Source_Reg_Write( 3 ) ;
    return 0;
}

int make_source_measurement(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    unsigned i;
    float    low_voltage;
    float    high_voltage;
    float    sensor_voltage;
    

    
    Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER);
    SIGMA_A_D_SelectConfiguration( 1,1);

    SIGMA_A_D_StartConvert();

    SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
    
    low_voltage = SIGMA_A_D_GetResult32();

    Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER+1);
    SIGMA_A_D_SelectConfiguration( 1,1);
    SIGMA_A_D_StartConvert();

    SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
    
    high_voltage = SIGMA_A_D_GetResult32();
    

    
    for( i = 0; i < MOISTURE_SENSOR_NUMBER; i++ )
    {
       if( get_moisture_sensor_configuration( i) != NOT_POPULATED )
       {
          Sink_Source_Setup_FastSelect(i);
          SIGMA_A_D_SelectConfiguration( 1,1);
          SIGMA_A_D_StartConvert();
          SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
         
          sensor_voltage = SIGMA_A_D_GetResult32();
          store_moisture_data(i, high_voltage, low_voltage, sensor_voltage );
       }
       else
       {
          moisture_meaurements[ i] = 0.0;
       }
    
    }
    return 0;

}







int set_sink_channel(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   
    Sink_Reg_Write( 3 );
    Source_Reg_Write (2 );
    
    
    return 0;
}

/*
**
**  This Routine is used to balance time on opposite leg but make no measurement
**
**
**
**
*/


int make_dummy_measurement(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    unsigned i;
    //float    low_voltage;
    //float    high_voltage;
    //float    sensor_voltage;
    
    
    
    Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER);
    SIGMA_A_D_SelectConfiguration( 1,1);

    SIGMA_A_D_StartConvert();
    SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
 
    //low_voltage = SIGMA_A_D_GetResult32();

    Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER+1);
    SIGMA_A_D_SelectConfiguration( 1,1);
    SIGMA_A_D_StartConvert();
    SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond

   // high_voltage = SIGMA_A_D_GetResult32();
    


    for( i = 0; i < MOISTURE_SENSOR_NUMBER; i++ )
    {
       Sink_Source_Setup_FastSelect(i);
       SIGMA_A_D_SelectConfiguration( 1,1);
       SIGMA_A_D_StartConvert();
       SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
  
       //sensor_voltage = SIGMA_A_D_GetResult32();
       ; //store_moisture_data(i, high_voltage, low_voltage, sensor_voltage );
    
    }
    return 0;

}









/*
**  Tell Modbus Devices that moisture measurement is done
**
*/

int update_new_measurement_available(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    uint16 temp;
    store_modbus_data_registers( NEW_MOISTURE_DATA, 1, &temp );
    store_modbus_data_registers( MOISTURE_SENSOR_1_FLOAT, MOISTURE_SENSOR_NUMBER*2, (uint16 *)moisture_meaurements );
    return 0;
    
    
} 


/*
**
** Temp Soil and other a/d measurements
**
**
**
*/

int setup_soil_temperature_measurements(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

    ad_setup_interrupt( );
    ad_init_se( );
    return 0;
}

int measure_soil_temperature(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   ad_process_se_second();
   return 0;
}

int update_soil_temperature_minute(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    ad_process_minute_second();
    return 0;
}
