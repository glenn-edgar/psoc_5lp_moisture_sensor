/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*   Enumerates as a Virtual Com port.  Receives data from hyper terminal, then 
*   send received data backward. LCD shows the Line settings.
*   
*  To test project:
*   1. Build the project and program the hex file on to the target device.
*   2. Select 3.3V in SW3 and plug-in power to the CY8CKIT-001
*   3. Connect USB cable from the computer to the CY8CKIT-001.
*   4. Select the USB_UART.inf file from the project directory, as the driver 
*      for this example once Windows asks for it.
*   5. Open "Device Manager" and note the COM port number for "Example Project"
*      device.
*   6. Open "HyperTerminal" application and make new connection to noted COM port
*   7. Type the message, observe echo data received.
*
* Related Document:
*  Universal Serial Bus Specification Revision 2.0 
*  Universal Serial Bus Class Definitions for Communications Devices 
*  Revision 1.2
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>
#include "stdio.h"

// software reset
// CySoftwareReset();


#include "cf_chain_flow_support.h"
#include "a_to_d_functions.h"
#include "cf_events.h"
#include "sigma_mux.h"
#include "cf_status_bit.h"
#include "modbus_serial_ctrl.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define HEART_BEAT_INTERVAL 500







static inline void  process_status_data( unsigned status_data)
{

    
    if( status_data & CF_PROCESS_AD_RESULTS )
    {
        ad_process_se();
    }
    if( status_data & CF_PROCESS_MODBUS )
    {
      process_rx_modbus_rtu_message( );
    }
    
}

// static varibles to save stack space
static int event_number;
static unsigned event_id;
static unsigned event_data;
static unsigned status_data;

int main()
{
    cf_initialize_status_manager();             
    cf_initialize_event_manager();
    initialize_cf_system(  );
    CyGlobalIntDisable;  // Chain Global Interrupts  initialization chain will enable interrupts 
    
    
    
    
    
    
    cf_process_cf_event( CF_SYSTEM_INIT , 0);
    for(;;)
    {
        status_data = cf_get_status();
        if( status_data != 0 )
        {
            process_status_data( status_data);
        }
        else
        {
           event_number = cf_rx_event( &event_id, &event_data );
           if( event_number > 0 )
           {
              cf_process_cf_event( event_id, event_data);
           }
           else
           {
             ; // add sleep for low power apps
           }
        }  
    }   
}



