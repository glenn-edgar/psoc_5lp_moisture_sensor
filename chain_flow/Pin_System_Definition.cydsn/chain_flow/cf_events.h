/*
**
** File cf_events.h
**
*/

#ifndef _CF_EVENTS_H_
#define _CF_EVENTS_H_

#define CF_SYSTEM_INIT         0
#define CF_INIT_EVENT          1
#define CF_TIME_TICK_EVENT     2
#define CF_PROCESS_AD_RESULTS  3
#define CF_USB_RTU_EVENT       4
#define CF_SECOND_TICK         5
#define CF_MINUTE_TICK         6
#define CF_HOUR_TICK           7
#define CF_COMMISSIONING_DONE  8
#define CF_MOISTURE_READING    9
#define CF_60HZ_TICK          10
#define CF_MEASURE_MOISTURE_CHANNEL 12
#define CF_MOISTURE_CHANNEL_DONE    13
#define CF_MOISTURE_START_CHANNELS  14

   
    

void cf_initialize_event_manager( void );
void cf_send_interrupt_event( unsigned event, unsigned data);
void cf_send_event( unsigned event, unsigned data );
int cf_rx_event( unsigned *event, unsigned *event_data );

#endif
