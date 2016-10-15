/*
** Build Time: 2016-10-14 11:42:16.385000  
*/
#ifndef _CF_ASSEMBLER_H_
#define _CF_ASSEMBLER_H_



#define CHAIN_NUM   13
#define LINK_NUM    81



#include <device.h>

#include "cf_chain_flow_support.h" 
#include "cf_runtime_functions.h" 
#include "cf_external_functions.h" 
char  chain_state[13];
char  link_state[81];
unsigned link_data[81];
const unsigned start_state[]={1,1,1,1,1,1,1,1,1,1,0,0,1};



const LINK_CELL CHAIN_initialization_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)initialize_die_temp_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_modbus_rtu,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_event_queue,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_rtc,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_modbus_reset_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_controller_wd_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_eeprom,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)remove_power,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)store_default_temperature_calibration_values_to_modbus_registers,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)store_default_resistor_calibration_values_to_modbus_registers,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_up_moisture_interrupt,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)setup_soil_temperature_measurements,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_moisture_processing,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)start_watchdog,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_timer_interrupt,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_interrupts,(unsigned)0,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_second_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_SECOND_TICK,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_modbus_watch_dog_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_modbus_rtc_values,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)meaure_die_temperature,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)measure_soil_temperature,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_moisture_active_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_logging_active_flag,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)check_for_moisture_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_minute_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MINUTE_TICK,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_soil_temperature_minute,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_minute_rollover,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_measure_channel_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_START_MOISTURE_READING,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)turn_on_timer_clock,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_120HZ_TICK,(unsigned)1,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_source_channel,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_120HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)make_source_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)remove_power,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_120HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_sink_channel,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_event_count_fn,(CF_FUN_AUX)NULL,(unsigned)CF_120HZ_TICK,(unsigned)2,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)make_dummy_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)remove_power,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_new_measurement_available,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_reset_log_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_RESET_LOG,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)reset_eeprom_log,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_set_measurement_rate_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MEASUREMENT_RATE,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_measurement_rate,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_update_moisture_configuration_parameters_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_UPDATE_MOISTURE_CONFIGURATION,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_moisture_configuration,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_update_reference_resistor_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_UPDATE_REFERENCE_RESISTOR,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_reference_resistor_configuration,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_update_temperature_parameters_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_UPDATE_TEMPERATURE_PARAMETERS,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)update_temperature_configuration,(unsigned)0,(unsigned)0,(unsigned)0},
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
{ 0,0,17,CHAIN_initialization_LINKS},
{ 17,1,9,CHAIN_second_tick_chain_LINKS},
{ 26,2,4,CHAIN_minute_tick_chain_LINKS},
{ 30,3,14,CHAIN_measure_channel_LINKS},
{ 44,4,3,CHAIN_reset_log_LINKS},
{ 47,5,3,CHAIN_set_measurement_rate_LINKS},
{ 50,6,3,CHAIN_update_moisture_configuration_parameters_LINKS},
{ 53,7,3,CHAIN_update_reference_resistor_LINKS},
{ 56,8,3,CHAIN_update_temperature_parameters_LINKS},
{ 59,9,2,CHAIN_hour_tick_chain_LINKS},
{ 61,10,4,CHAIN_commissioning_heart_beat_LINKS},
{ 65,11,4,CHAIN_heart_beat_LINKS},
{ 69,12,12,CHAIN_handle_commissioning_LINKS},
};
#endif
