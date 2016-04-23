/*
**
** File Name: i2c_master.h
**
**
*/

#ifndef _RTC_FUNCTIONS_H_
#define _RTC_FUNCTIONS_H_

#include <device.h>


    
// routine in RTC interupt handler
void rtc_second_tick( void );

// routine in RTC interupt handler
void rtc_minute_tick( void );


void rtc_hour_tick( void );



#endif
