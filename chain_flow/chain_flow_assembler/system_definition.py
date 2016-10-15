from helper_functions import  Helper_Functions
from assembler          import  CF_Assembler

cf = CF_Assembler()
hf = Helper_Functions( cf )


cf.define_chain("initialization",True)
hf.one_step("initialize_die_temp_measurement")
hf.one_step("initialize_modbus_rtu")
hf.one_step("init_event_queue")
hf.one_step("init_rtc")
hf.one_step("set_modbus_reset_flag")
hf.one_step("initialize_controller_wd_flag")
hf.one_step("enable_eeprom")
hf.one_step("remove_power")
hf.one_step("store_default_temperature_calibration_values_to_modbus_registers")
hf.one_step("store_default_resistor_calibration_values_to_modbus_registers")
hf.one_step("set_up_moisture_interrupt")
hf.one_step("setup_soil_temperature_measurements")
hf.one_step("init_moisture_processing")
hf.one_step("start_watchdog")
hf.one_step("enable_timer_interrupt")
hf.one_step("enable_interrupts")
hf.terminate()  #initialization is done now disable the chain
cf.end_chain()







#These chains are for actions every second 
cf.define_chain("second_tick_chain", True )
hf.wait_event("CF_SECOND_TICK")
hf.one_step("set_modbus_watch_dog_flag")
hf.one_step("update_modbus_rtc_values")
hf.one_step("meaure_die_temperature")
hf.one_step("measure_soil_temperature")
hf.one_step("check_moisture_active_flag")
hf.one_step("check_logging_active_flag")
hf.one_step("check_for_moisture_measurement")  #### temp move
hf.reset()
cf.end_chain()

#These chains are for actions every minute
cf.define_chain("minute_tick_chain", True )
hf.wait_event("CF_MINUTE_TICK")
hf.one_step("update_soil_temperature_minute")
#hf.one_step("check_for_moisture_measurement")
hf.one_step("set_minute_rollover")
hf.reset()
cf.end_chain()




cf.define_chain("measure_channel",True)
hf.wait_event("CF_START_MOISTURE_READING")
hf.one_step("turn_on_timer_clock")
hf.wait_event_count("CF_120HZ_TICK",1)
hf.one_step("set_source_channel")
hf.wait_event_count("CF_120HZ_TICK",2)
hf.one_step("make_source_measurement")
hf.one_step("remove_power")
hf.wait_event_count("CF_120HZ_TICK",2)
hf.one_step("set_sink_channel")
hf.wait_event_count("CF_120HZ_TICK",2)
hf.one_step("make_dummy_measurement")
hf.one_step("remove_power")
hf.one_step("update_new_measurement_available")
hf.reset()
cf.end_chain()

cf.define_chain("reset_log",True)
hf.wait_event("CF_RESET_LOG")
hf.one_step("reset_eeprom_log")
hf.reset()
cf.end_chain()

cf.define_chain("set_measurement_rate",True)
hf.wait_event("CF_MEASUREMENT_RATE")
hf.one_step("update_measurement_rate")
hf.reset()
cf.end_chain()

cf.define_chain("update_moisture_configuration_parameters", True)
hf.wait_event("CF_UPDATE_MOISTURE_CONFIGURATION")
hf.one_step("update_moisture_configuration")
hf.reset()
cf.end_chain()


cf.define_chain("update_reference_resistor", True)
hf.wait_event("CF_UPDATE_REFERENCE_RESISTOR")
hf.one_step("update_reference_resistor_configuration")
hf.reset()
cf.end_chain()



cf.define_chain("update_temperature_parameters", True)
hf.wait_event("CF_UPDATE_TEMPERATURE_PARAMETERS")
hf.one_step("update_temperature_configuration")
hf.reset()
cf.end_chain()





#These chains are for actions every hour
cf.define_chain("hour_tick_chain", True )
hf.wait_event("CF_HOUR_TICK")
hf.reset()
cf.end_chain()


cf.define_chain( "commissioning_heart_beat",False)
hf.wait_time(100)  # 100 ms
hf.one_step(" toggle_heart_beat")
hf.one_step("pat_watch_dog")
hf.reset()
cf.end_chain()

cf.define_chain( "heart_beat",False)
hf.wait_time(1000)  #500 ms
hf.one_step(" toggle_heart_beat")
hf.one_step("pat_watch_dog")
hf.reset()
cf.end_chain()

#this chain is for commisisioning activities for modbus serial
cf.define_chain("handle_commissioning",True)
hf.one_step("set_normal_modbus_address")
hf.disable_chain("commissioning_heart_beat")
hf.enable_chain("heart_beat")
hf.wait(  "switch_off_fn" )
hf.wait(  "switch_on_fn" )
hf.wait(  "switch_off_fn" )
hf.disable_chain("heart_beat")
hf.enable_chain("commissioning_heart_beat")
hf.one_step("set_commissiong_address")
hf.verify( "switch_off_fn")
hf.wait_event("CF_COMMISSIONING_DONE",300000) # 5 minutes
hf.reset()
cf.end_chain()


cf.generate_c_header()


