#ifndef _CF_ASSEMBLER_H_
#define _CF_ASSEMBLER_H_



#define CHAIN_NUM   6
#define LINK_NUM    29



char  chain_state[6];
char  link_state[29];
unsigned link_data[29];
const unsigned start_state[]={1,1,1,1,1,1};



const LINK_CELL CHAIN_initialization_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)initialize_eeprom,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_die_temp_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_analog,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_timer_interrupt,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_pwms,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_counters,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_interrupts,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)start_watchdog,(unsigned)0,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_heart_beat_LINKS[]= 
{
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)500,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX) toggle_heart_beat,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)pat_watch_dog,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_measure_die_temperature_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)meaure_die_temperature,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)1000,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_update_eeprom_temperature_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)update_eeprom_temp,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)60000,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_read_counter_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)read_counter_register,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)10000,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_sigma_mux_channel_control_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)set_mux_channel,(unsigned)0,(unsigned)1,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)10000,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)sigma_store_value,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)set_mux_channel,(unsigned)1,(unsigned)1,(unsigned)0},
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)10000,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)sigma_store_value,(unsigned)1,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};



const CHAIN_LINK chain_control[] =
{
{ 0,0,9,CHAIN_initialization_LINKS},
{ 9,1,4,CHAIN_heart_beat_LINKS},
{ 13,2,3,CHAIN_measure_die_temperature_LINKS},
{ 16,3,3,CHAIN_update_eeprom_temperature_LINKS},
{ 19,4,3,CHAIN_read_counter_LINKS},
{ 22,5,7,CHAIN_sigma_mux_channel_control_LINKS},
};
#endif
