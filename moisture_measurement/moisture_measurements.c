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

static float reference_resistance;
static int32 current_channel;
static int32 source_voltage;

static uint32 logging_flag;
static uint32 active_flag = 0;
static uint32 measurement_minute_count = 0;
static uint32 sensor_type;

static int32 sigma_a_d_high;



static float moisture_meaurements[ MOISTURE_SENSOR_NUMBER ];




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
   SIGMA_A_D_Start();

   Source_Reg_Write(0);
   Sink_Reg_Write(0);
 
   SWITCH_CLOCK_Start();
   Sink_Source_Setup_Start() ;
   Sink_Source_Setup_FastSelect(9) ;
   SIGMA_A_D_SelectConfiguration( 1,1);
   SIGMA_A_D_StartConvert();
   SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
   Sink_Source_Setup_Start();
   Sink_Source_Setup_FastSelect(MOISTURE_SENSOR_NUMBER) ;
   SIGMA_A_D_SelectConfiguration( 1,1);
   SIGMA_A_D_StartConvert();
   SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
   sigma_a_d_high  =   SIGMA_A_D_GetResult32();
   

   SIGMA_A_D_Sleep();
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
    moisture_interval_clock_Start();
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

int setup_measurement_channel(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int return_value;
    
   if( event== CF_INIT_EVENT )
   {
      return_value = CF_CONTINUE;
   }
   else
   {
      current_channel = data;
      reference_resistance = get_reference_resistor( current_channel );
      sensor_type = get_moisture_sensor_configuration( current_channel );
      if( sensor_type == NOT_POPULATED)
      {
         cf_send_event( CF_MOISTURE_CHANNEL_DONE,0 );
         moisture_meaurements[ current_channel ] = 0.0;
         return_value = CF_RESET;
      }
      else
      {
        return_value = CF_DISABLE;
      }
   }     
    return return_value;
}

int remove_power(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
     SIGMA_A_D_Sleep();
     Sink_Reg_Write(0);
     Source_Reg_Write( 0);
    
     return 0;
}


int set_source_channel(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   
    
    Sink_Reg_Write( 2 );
    Source_Reg_Write( 3 ) ;
   
    Sink_Source_Setup_FastSelect(current_channel) ;
    SIGMA_A_D_Wakeup();
    SIGMA_A_D_SelectConfiguration( 1,1);
    SIGMA_A_D_StartConvert();
    return 0;
}

int make_source_measurement(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

    SIGMA_A_D_IsEndConversion( SIGMA_A_D_WAIT_FOR_RESULT );  // conversion is 3000/sec  max wait time is no more than .3 millisecond
    source_voltage =   SIGMA_A_D_GetResult32();

    return 0;

}








int set_sink_channel(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   
    Sink_Reg_Write( 3 );
    Source_Reg_Write (2 );
    
    
    Sink_Source_Setup_FastSelect(current_channel);
    SIGMA_A_D_Wakeup();
    SIGMA_A_D_SelectConfiguration( 1,1);
    SIGMA_A_D_StartConvert();
    return 0;
}



/*
**
** Routines to store data
** resistance unknow resistance equals
** reference resistance is stored in modbus location REFERENECE_RESISTANCE
** i = ( sigma_v_rail)/known_resistance
** unknown resistance = v_measurement/i
*/


int store_moisture_data(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    float measurement;
    float source_current;
    float source_resistance;
    
    source_current = ((float) sigma_a_d_high -(float)source_voltage)/reference_resistance;
    source_resistance = source_voltage/source_current;
    switch( sensor_type )
    {
        case NOT_POPULATED:  // not connected sensor -- should not reach this poi
           CYASSERT(0);
           break;
        
        case RESISTIVE_ELEMENT:
            measurement = source_resistance;
            break;
            
        case WATER_MARK:
            measurement = 0; // call watermark function;
            break;
       default:
            CYASSERT(0);
    }
    
    moisture_meaurements[ current_channel ] = measurement;
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
