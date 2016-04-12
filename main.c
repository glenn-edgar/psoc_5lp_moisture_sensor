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



#include "cf_chain_flow_support.h"
#include "a_to_d_functions.h"
#include "cf_events.h"
#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define HEART_BEAT_INTERVAL 500







static inline int  process_high_priority_events( int event_id, int event_data)
{
    int return_value;
    
    switch( event_id)   
    {
        case CF_PROCESS_AD_RESULTS:
           ad_process_se();  // process single ended
           ad_process_de();
           ad_process_sigma_delta();
           return_value = 1;  // prevent event from being passed throug
        
        
        
        default:
            return_value = 0;
    }
    return return_value;
    
}

static int event_number;
static unsigned event_id;
static unsigned event_data;

int main()
{
                            
    cf_initialize_event_manager();
    initialize_cf_system(  );
    /* Enable Global Interrupts */
    
    /* Start USBFS Operation with 5V operation */
    USBUART_1_Start(0u, USBUART_1_5V_OPERATION);
    
    
    //CyWdtStart( CYWDT_1024_TICKS, CYWDT_LPMODE_NOCHANGE ); // 2 -3 second interval
    
    cf_process_cf_event( CF_SYSTEM_INIT , 0);
    for(;;)
    {
        event_number = cf_rx_event( &event_id, &event_data );
        if( event_number > 0 )
        {
           if( process_high_priority_events( event_id, event_data ) == 0 )
           {
              cf_process_cf_event( event_id, event_data);
           }
           else
           {
              ; //  process_high_priority_events absorbed the results
           }
            
          //process_usb_serial( input_event );
   
        }  
    }   
}



