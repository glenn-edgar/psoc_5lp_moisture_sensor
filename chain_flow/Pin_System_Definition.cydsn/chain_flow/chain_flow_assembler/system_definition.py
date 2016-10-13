from helper_functions import  Helper_Functions
from assembler          import  CF_Assembler

cf = CF_Assembler()
hf = Helper_Functions( cf )


cf.define_chain("initialization",True)

hf.one_step("initialize_die_temp_measurement")

hf.one_step("enable_timer_interrupt")
hf.one_step("initialize_modbus_rtu")
hf.one_step("enable_interrupts")
hf.one_step("start_watchdog")
hf.one_step("init_event_queue")
hf.one_step("init_rtc")
hf.one_step("set_modbus_reset_flag")
hf.one_step("initialize_callibration_variables")
hf.one_step("initialize_controller_wd_flag")
hf.one_step("clear_reset_flag")
hf.one_step("enable_eeprom")
hf.one_step("init_vdac")
hf.one_step("init_idac")
hf.terminate()  #initialization is done now disable the thread
cf.end_chain()



cf.define_chain("measure_die_temperature",True)
hf.one_step("meaure_die_temperature")
hf.wait_time(1000)
hf.reset()
cf.end_chain()




cf.define_chain("process_rtu_packet", True )
hf.wait_event( "CF_USB_RTU_EVENT")
hf.one_step("process_rtu_message")
hf.reset()
cf.end_chain()




#These chains are for actions every second 
cf.define_chain("second_tick_chain", True )
hf.wait_event("CF_SECOND_TICK")
hf.one_step("set_modbus_watch_dog_flag")
hf.one_step("update_modbus_rtc_values")
hf.one_step("meaure_die_temperature")
hf.one_step("update_soil_temperature_second")
hf.one_step("check_moisture_active_flag")
hf.one_step("check_logging_active_flag")
hf.reset()
cf.end_chain()

#These chains are for actions every minute
cf.define_chain("minute_tick_chain", True )
hf.wait_event("CF_MINUTE_TICK")
hf.one_step("update_soil_temperature_minute")
hf.one_step("check_for_moisture_measurement")
hf.reset()
cf.end_chain()

cf.define_chain("soil_measurement_calibration",True)
hf.wait_event("CF_MOISTURE_READING")
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",8)
hf.wait_event("CF_MOISTURE_CHANNEL_DONE")
hf.one_step("store_calibration_result")
hf.send_event("CF_MOISTURE_START_CHANNELS",0)
hf.reset()
cf.end_chain()

cf.define_chain("sequence_moisture_measurement",True)
hf.wait_event("CF_MOISTURE_START_CHANNELS",True)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",0)
hf.wait_event("CF_MOISTURE_CHANNEL_DONE")
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",1)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",2)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",3)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",4)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",5)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",6)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.send_event("CF_MEASURE_MOISTURE_CHANNEL",7)
hf.wait_event_count("CF_MOISTURE_CHANNEL_DONE",2)
hf.one_step("store_moisture_data")
hf.reset()
cf.end_chain()


cf.define_chain("measure_channel",True)
hf.wait_event("CF_MEASURE_MOISTURE_CHANNEL")
hf.code_step("setup_measurement_channel")
hf.wait_event("CF_60HZ_TICK")
hf.one_step("set_source_channel")
hf.wait_event_count("CF_60HZ_TICK",2)
hf.one_step("make_source_measurement")
hf.one_step("remove_power")
hf.wait_event_count("CF_60HZ_TICK",2)
hf.one_step("set_sink_channel",8)
hf.wait_event_count("CF_60HZ_TICK",2)
hf.one_step("make_sink_measurement")
hf.one_step("store_calibration_result")
hf.one_step("remove_power")
hf.send_event("CF_MOISTURE_CHANNEL_DONE",0)
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


