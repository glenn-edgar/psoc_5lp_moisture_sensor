from helper_functions import  Helper_Functions
from assembler          import  CF_Assembler

cf = CF_Assembler()
hf = Helper_Functions( cf )


cf.define_chain("initialization",True)
hf.one_step("initialize_eeprom")
hf.one_step("initialize_die_temp_measurement")
hf.one_step("initialize_analog")
hf.one_step("enable_timer_interrupt")
hf.one_step("enable_pwms")
hf.one_step("enable_counters")
hf.one_step("enable_interrupts")
hf.one_step("start_watchdog")
hf.terminate()  #initialization is done now disable the thread
cf.end_chain()


cf.define_chain( "heart_beat",True)
hf.wait_time(500)
hf.one_step(" toggle_heart_beat")
hf.one_step("pat_watch_dog")
hf.reset()
cf.end_chain()

cf.define_chain("measure_die_temperature",True)
hf.one_step("meaure_die_temperature")
hf.wait_time(1000)
hf.reset()
cf.end_chain()

cf.define_chain("update_eeprom_temperature",True)
hf.one_step("update_eeprom_temp")
hf.wait_time(60000) #update every minute
hf.reset()
cf.end_chain()

# actual production would use RTC time ticks
cf.define_chain("read_counter",True)
hf.one_step("read_counter_register")
hf.wait_time(10000) #update every second
hf.reset()
cf.end_chain()

cf.define_chain("sigma_mux_channel_control",True )
hf.one_step("set_mux_channel", 0,1) #mux ch -- a/d configuration
hf.wait_time(10000) # wait 10 seconds
hf.one_step("sigma_store_value",0)
hf.one_step("set_mux_channel",1,1)
hf.wait_time(10000)#wait 10 seconds
hf.one_step("sigma_store_value",1 )
hf.reset()
cf.end_chain()

cf.define_chain("usb_cdc_establish_link",True)
hf.reset()
cf.end_chain()

cf.define_chain("usb_rx_packets, False)
hf.reset()
cf.end_chain()

cf.define_chain("usb_tx_packets, False)
hf.reset()
cf.end_chain()

cf.define_chain("usb_tx_packets, False )
cf.end_chain()

cf.generate_c_header()


