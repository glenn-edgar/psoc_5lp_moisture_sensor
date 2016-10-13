/*
**
** File: cf_external_functions.c
** This file is manually generated
** 
**
*/
#include <device.h>
#include "cf_events.h"
#include "moving_average.h"
#include "cf_external_functions.h"
#include "a_to_d_functions.h"
#include "sigma_mux.h"
#include "event_fifo.h"
#include "digitial_io.h"
#include "process_modbus_message.h"

static uint32 reset_flag;

#define TICK_INTERVAL          16

int toggle_heart_beat(unsigned link_id, unsigned param_1,
                      unsigned param_2, unsigned param_3, 
			          unsigned event, unsigned data)
{
	
           
   heart_beat_pin_Write( !heart_beat_pin_Read() );
   return CF_DISABLE;       

}

int  pat_watch_dog(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    CyWdtClear();
    return CF_DISABLE;
}



/*
** Die Temperature functions
**
*/





/*
**
** Initialize Function
**
**
*/
CY_ISR_PROTO( sleep_timer_interrupt )
{
    SleepTimer_1_GetStatus();
    cf_send_interrupt_event(  CF_TIME_TICK_EVENT, TICK_INTERVAL );
    
}



int start_watchdog(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    //CyWdtStart( CYWDT_1024_TICKS, CYWDT_LPMODE_NOCHANGE ); // 2 -3 second interval
    return CF_DISABLE;
}






int enable_timer_interrupt(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

    isr_1_StartEx(sleep_timer_interrupt); 
    SleepTimer_1_Start();
    return CF_DISABLE;
}

int enable_interrupts(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   CyGlobalIntEnable;
   return CF_DISABLE;
}







 
    
int init_event_queue(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
  
    EF_initialize();
    return CF_DISABLE;
    
}  






int switch_on_fn(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   return 0;
}

int switch_off_fn(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    return 0;
}


int initialize_callibration_variables(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    return 0;
}

int set_modbus_watch_dog_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    uint16 temp;
    temp = 1;
    store_modbus_data_registers( MOD_RTU_WATCH_DOG_FLAG, 1, &temp);
    return 0;
}

int set_minute_rollover(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   uint16 temp;
    temp = 1;
    store_modbus_data_registers(MOD_MINUTE_ROLLOVER , 1, &temp);
    return 0;
}
       
 
int update_modbus_rtc_values(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    uint16 temp;
    temp =   RTC_1_ReadSecond();                     
    store_modbus_data_registers( MOD_SECOND, 1, &temp );
    temp =   RTC_1_ReadMinute();                     
    store_modbus_data_registers(  MOD_MINUTE,  1, &temp);
    temp =  RTC_1_ReadHour();                     ;
    store_modbus_data_registers( MOD_HOUR,  1, &temp);
    temp = RTC_1_ReadDayOfMonth();                
    store_modbus_data_registers( MOD_DAY,  1, &temp);
    temp = RTC_1_ReadMonth();                      
    store_modbus_data_registers(  MOD_MONTH,  1, &temp);
    temp =  RTC_1_ReadYear();                      
    store_modbus_data_registers( MOD_YEAR, 1, &temp);
    return 0;
}


int set_modbus_reset_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
   uint16 temp;
    temp = 1;
    store_modbus_data_registers( MOD_POWER_UP_EVENT, 1, &temp);
    return 0;
}




int initialize_controller_wd_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
     uint16 temp;
    
     temp = 0;
     
     store_modbus_data_registers( MOD_CONTROLLER_WATCH_DOG_FLAG, 1, &temp );
     return 0;
}



 
void set_reset_flag( void )
{
    reset_flag = 1;
}
    
int clear_reset_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    reset_flag = 0;
    return 0;
}


int check_reset_flag(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    if( reset_flag != 0 )
    {
        CySoftwareReset();
    }
    return 0;
}
