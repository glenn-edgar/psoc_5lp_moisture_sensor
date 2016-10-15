# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\glenn\OneDrive\PSOC\moisture_sensor\USB_UART01.cydsn\USB_UART01.cyprj
# Date: Fri, 14 Oct 2016 21:08:37 GMT
#set_units -time ns
create_clock -name {SIGMA_A_D_Ext_CP_Clk(routed)} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {ADC_SAR_Seq_1_IntClock(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {AD_CLOCK(routed)} -period 500000 -waveform {0 250000} [list [get_pins {ClockBlock/dclk_3}]]
create_clock -name {modbus_symbol_clock(routed)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/dclk_4}]]
create_clock -name {moisture_interval_clock(routed)} -period 8331298.828125 -waveform {0 4165649.4140625} [list [get_pins {ClockBlock/dclk_5}]]
create_clock -name {CyXTAL_32kHz} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/clk_32k_xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {SIGMA_A_D_Ext_CP_Clk} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {SIGMA_A_D_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 21 43} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {SIGMA_A_D_theACLK(fixed-function)} -period 328.125 -waveform {0 164.0625} [get_pins {ClockBlock/aclk_glb_ff_0}]
create_generated_clock -name {ADC_SAR_Seq_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 41 81} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {moisture_interval_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 531251 1066407} -nominal_period 8331298.828125 [list [get_pins {ClockBlock/dclk_glb_5}]]
create_generated_clock -name {SWITCH_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 1277345 2558593} -nominal_period 19989013.671875 [list [get_pins {ClockBlock/dclk_glb_6}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 209 417} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {AD_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 32001 64001} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {modbus_symbol_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 64001 128001} [list [get_pins {ClockBlock/dclk_glb_4}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\glenn\OneDrive\PSOC\moisture_sensor\USB_UART01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\glenn\OneDrive\PSOC\moisture_sensor\USB_UART01.cydsn\USB_UART01.cyprj
# Date: Fri, 14 Oct 2016 21:08:23 GMT
