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
hf.one_step("initialize_usb")
hf.one_step("initialize_modbus_rtu")
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
hf.disable_chain("usb_rx_packet","usb_process_packet","usb_tx_packet")
hf.wait("usb_configuration_changed" )
hf.verify("usb_connection_still_active")
hf.enable_chain("usb_rx_packet")
hf.halt()
cf.end_chain()

# a modbus packet has a max length 0f 256 bytes  -- should get at most 4 usb packets + 1 empty packet
cf.define_chain("usb_rx_packet", False)
hf.wait("usb_can_receive")
hf.one_step("process_usb_rx_packet",0)  # first usb packet bytes 1- 64
hf.wait("usb_can_receive",time_out = 32) #wait 4 8 msec tick
hf.one_step("process_usb_rx_packet",1)  # second usb packet bytes 65 - 128
hf.wait("usb_can_receive", time_out=32) #wait 4 8 msec tick
hf.one_step("process_usb_rx_packet",2)  # third usb packet bytes 129 - 192
hf.wait("usb_can_receive", time_out=32) #wait 4 8 msec tick
hf.one_step("process_usb_rx_packet",3)  # fourth usb packet  bytes 193 -- 256
hf.wait("usb_can_receive", time_out =32) #wait 4 8 msec tick 
hf.one_step("process_usb_rx_packet",4)  # fifth packet should be empty usb packet
hf.terminate()
cf.end_chain()

cf.define_chain("usb_process_packet", False)
hf.one_step("usb_process_modbus_message")
hf.terminate()
cf.end_chain()

cf.define_chain("usb_tx_packet", False )
hf.wait( "usb_can_transmit",time_out=100)  # wait approximately 100 ms
hf.one_step("usb_send_packet", 0)
hf.wait("usb_can_transmit",time_out = 100)
hf.one_step("usb_send_packet",1)
hf.wait("usb_can_transmit",time_out=100)
hf.one_step("usb_send_packet",2)
hf.wait("usb_can_transmit",time_out = 100)
hf.one_step("usb_send_packet",3)
hf.wait("usb_can_transmit",time_out= 100)
hf.one_step("usb_send_packet",4)
hf.terminate()
cf.end_chain()



cf.define_chain("process_rtu_packet", False )
hf.wait_event( "CF_USB_RTU_EVENT")
hf.one_step("process_rtu_message")
hf.reset()
cf.end_chain()

cf.generate_c_header()


