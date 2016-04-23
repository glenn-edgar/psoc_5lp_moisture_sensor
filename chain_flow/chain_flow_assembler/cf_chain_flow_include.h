#ifndef _CF_ASSEMBLER_H_
#define _CF_ASSEMBLER_H_



#define CHAIN_NUM   15
#define LINK_NUM    75



char  chain_state[15];
char  link_state[75];
unsigned link_data[75];
const unsigned start_state[]={1,1,1,1,1,1,1,0,0,0,0,1,1,1,1};



const LINK_CELL CHAIN_initialization_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)initialize_eeprom,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_die_temp_measurement,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_analog,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_timer_interrupt,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_pwms,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_counters,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_usb,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)initialize_modbus_rtu,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)enable_interrupts,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)start_watchdog,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_cap_sense,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_event_queue,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)init_rtc,(unsigned)0,(unsigned)0,(unsigned)0},
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
const LINK_CELL CHAIN_usb_cdc_establish_link_LINKS[]= 
{
{ disable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)usb_rx_packet,(unsigned)usb_process_packet,(unsigned)usb_tx_packet},
{ wait_condition_fn,(CF_FUN_AUX)usb_configuration_changed,(unsigned)0,(unsigned)0,(unsigned)0},
{ verify_condition_fn,(CF_FUN_AUX)usb_connection_still_active,(unsigned)0,(unsigned)0,(unsigned)0},
{ enable_chain_fn,(CF_FUN_AUX)NULL,(unsigned)usb_rx_packet,(unsigned)-1,(unsigned)-1},
{ halt_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_usb_rx_packet_LINKS[]= 
{
{ wait_condition_fn,(CF_FUN_AUX)usb_can_receive,(unsigned)0,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)process_usb_rx_packet,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_receive,(unsigned)0,(unsigned)0,(unsigned)32},
{ one_step_fn,(CF_FUN_AUX)process_usb_rx_packet,(unsigned)1,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_receive,(unsigned)0,(unsigned)0,(unsigned)32},
{ one_step_fn,(CF_FUN_AUX)process_usb_rx_packet,(unsigned)2,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_receive,(unsigned)0,(unsigned)0,(unsigned)32},
{ one_step_fn,(CF_FUN_AUX)process_usb_rx_packet,(unsigned)3,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_receive,(unsigned)0,(unsigned)0,(unsigned)32},
{ one_step_fn,(CF_FUN_AUX)process_usb_rx_packet,(unsigned)4,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_usb_process_packet_LINKS[]= 
{
{ one_step_fn,(CF_FUN_AUX)usb_process_modbus_message,(unsigned)0,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_usb_tx_packet_LINKS[]= 
{
{ wait_condition_fn,(CF_FUN_AUX)usb_can_transmit,(unsigned)0,(unsigned)0,(unsigned)100},
{ one_step_fn,(CF_FUN_AUX)usb_send_packet,(unsigned)0,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_transmit,(unsigned)0,(unsigned)0,(unsigned)100},
{ one_step_fn,(CF_FUN_AUX)usb_send_packet,(unsigned)1,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_transmit,(unsigned)0,(unsigned)0,(unsigned)100},
{ one_step_fn,(CF_FUN_AUX)usb_send_packet,(unsigned)2,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_transmit,(unsigned)0,(unsigned)0,(unsigned)100},
{ one_step_fn,(CF_FUN_AUX)usb_send_packet,(unsigned)3,(unsigned)0,(unsigned)0},
{ wait_condition_fn,(CF_FUN_AUX)usb_can_transmit,(unsigned)0,(unsigned)0,(unsigned)100},
{ one_step_fn,(CF_FUN_AUX)usb_send_packet,(unsigned)4,(unsigned)0,(unsigned)0},
{ terminate_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_process_rtu_packet_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_USB_RTU_EVENT,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)process_rtu_message,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_capsense_chain_LINKS[]= 
{
{ wait_time_fn,(CF_FUN_AUX)NULL,(unsigned)1000,(unsigned)0,(unsigned)0},
{ one_step_fn,(CF_FUN_AUX)process_capsense,(unsigned)0,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_second_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_SECOND_TICK,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_minute_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_MINUTE_TICK,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};
const LINK_CELL CHAIN_hour_tick_chain_LINKS[]= 
{
{ wait_event_fn,(CF_FUN_AUX)NULL,(unsigned)CF_HOUR_TICK,(unsigned)0,(unsigned)0},
{ reset_fn,(CF_FUN_AUX)NULL,(unsigned)0,(unsigned)0,(unsigned)0},
};



const CHAIN_LINK chain_control[] =
{
{ 0,0,14,CHAIN_initialization_LINKS},
{ 14,1,4,CHAIN_heart_beat_LINKS},
{ 18,2,3,CHAIN_measure_die_temperature_LINKS},
{ 21,3,3,CHAIN_update_eeprom_temperature_LINKS},
{ 24,4,3,CHAIN_read_counter_LINKS},
{ 27,5,7,CHAIN_sigma_mux_channel_control_LINKS},
{ 34,6,5,CHAIN_usb_cdc_establish_link_LINKS},
{ 39,7,11,CHAIN_usb_rx_packet_LINKS},
{ 50,8,2,CHAIN_usb_process_packet_LINKS},
{ 52,9,11,CHAIN_usb_tx_packet_LINKS},
{ 63,10,3,CHAIN_process_rtu_packet_LINKS},
{ 66,11,3,CHAIN_capsense_chain_LINKS},
{ 69,12,2,CHAIN_second_tick_chain_LINKS},
{ 71,13,2,CHAIN_minute_tick_chain_LINKS},
{ 73,14,2,CHAIN_hour_tick_chain_LINKS},
};
#endif
