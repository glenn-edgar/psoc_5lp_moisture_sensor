/*
** Build Time: 2016-09-22 10:54:19.869000  
*/
#ifndef _CF_ASSEMBLER_H_
#define _CF_ASSEMBLER_H_



#define CHAIN_NUM   12
#define LINK_NUM    95



#include <device.h>

#include "cf_chain_flow_support.h" 
#include "cf_runtime_functions.h" 
#include "cf_external_functions.h" 
char  chain_state[12];
char  link_state[95];
unsigned link_data[95];
const unsigned start_state[]={1,1,1,1,1,1,1,1,1,0,0,1};



const LINK_CELL CHAIN_initialization_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)initialize_die_temp_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_timer_interrupt,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_modbus_rtu,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_interrupts,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)start_watchdog,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_event_queue,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_rtc,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_modbus_reset_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_callibration_variables,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_controller_wd_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)clear_reset_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_eeprom,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_vdac,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_idac,(unsigned)0,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_measure_die_temperature_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)meaure_die_temperature,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)1000,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_process_rtu_packet_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_USB_RTU_EVENT,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)process_rtu_message,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_second_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_SECOND_TICK,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_modbus_watch_dog_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_modbus_rtc_values,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)meaure_die_temperature,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_soil_temperature_second,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_moisture_active_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_logging_active_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_minute_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MINUTE_TICK,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_soil_temperature_minute,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_for_moisture_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_soil_measurement_calibration_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_READING,(unsigned)0,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)8,(unsigned)0},
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)store_calibration_result,(unsigned)0,(unsigned)0,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_START_CHANNELS,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_sequence_moisture_measurement_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_START_CHANNELS,(unsigned)True,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)0,(unsigned)0},
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)0,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)1,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)2,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)3,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)4,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)5,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)6,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)7,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)store_moisture_data,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_measure_channel_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASURE_MOISTURE_CHANNEL,(unsigned)0,(unsigned)0},
{ code_step_fn,(CF_FUN_AUX)setup_measurement_channel,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_60HZ_TICK,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_source_channel,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_60HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)make_source_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)remove_power,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_60HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_sink_channel,(unsigned)8,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_60HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)make_sink_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)store_calibration_result,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)remove_power,(unsigned)0,(unsigned)0,(unsigned)0},
{ send_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MOISTURE_CHANNEL_DONE,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_hour_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_HOUR_TICK,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_commissioning_heart_beat_LINKS[]= 
{
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)100,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX) toggle_heart_beat,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)pat_watch_dog,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_heart_beat_LINKS[]= 
{
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)1000,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX) toggle_heart_beat,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)pat_watch_dog,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_handle_commissioning_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)set_normal_modbus_address,(unsigned)0,(unsigned)0,(unsigned)0},
{ disable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)commissioning_heart_beat,(unsigned)-1,(unsigned)-1},
{ enable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)heart_beat,(unsigned)-1,(unsigned)-1},
{ wait_condition_fn,(CF_FUN_AUX)switch_off_fn,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)switch_on_fn,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)switch_off_fn,(unsigned)0,(unsigned)0,(unsigned)0},
{ disable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)heart_beat,(unsigned)-1,(unsigned)-1},
{ enable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)commissioning_heart_beat,(unsigned)-1,(unsigned)-1},
{ one_step_fn,(CF_FUN_AUX)set_commissiong_address,(unsigned)0,(unsigned)0,(unsigned)0},
{ verify_condition_fn,(CF_FUN_AUX)switch_off_fn,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_COMMISSIONING_DONE,(unsigned)300000,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};



const CHAIN_LINK chain_control[] =
{
{ 0,0,15,CHAIN_initialization_LINKS},
{ 15,1,3,CHAIN_measure_die_temperature_LINKS},
{ 18,2,3,CHAIN_process_rtu_packet_LINKS},
{ 21,3,8,CHAIN_second_tick_chain_LINKS},
{ 29,4,4,CHAIN_minute_tick_chain_LINKS},
{ 33,5,6,CHAIN_soil_measurement_calibration_LINKS},
{ 39,6,19,CHAIN_sequence_moisture_measurement_LINKS},
{ 58,7,15,CHAIN_measure_channel_LINKS},
{ 73,8,2,CHAIN_hour_tick_chain_LINKS},
{ 75,9,4,CHAIN_commissioning_heart_beat_LINKS},
{ 79,10,4,CHAIN_heart_beat_LINKS},
{ 83,11,12,CHAIN_handle_commissioning_LINKS},
};
#endif
