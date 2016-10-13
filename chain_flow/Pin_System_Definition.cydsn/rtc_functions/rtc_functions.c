/*
**
**
** File Name: rtc_functions.c
**
**
*/

#include <device.h>
#include "rtc_functions.h"
#include "cf_external_functions.h"
#include "cf_chain_flow_support.h"
#include "cf_events.h"
#define CF_HOUR_TICK           7
    

int init_rtc(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    
    RTC_1_Start();
    RTC_1_EnableInt();
    RTC_1_WriteIntervalMask(RTC_1_ALARM_SEC_MASK
                            |RTC_1_ALARM_MIN_MASK
                            |RTC_1_ALARM_HOUR_MASK );
    
    return CF_DISABLE;
}



void rtc_second_tick( void )
{
    cf_send_interrupt_event( CF_SECOND_TICK, 1);
}

void rtc_minute_tick( void )
{
    cf_send_interrupt_event( CF_MINUTE_TICK, 1);
}

void rtc_hour_tick( void )
{
    cf_send_interrupt_event( CF_HOUR_TICK, 1);
}