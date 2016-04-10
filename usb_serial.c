/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "device.h"
#include "cf_events.h"
#include "modbus_slave.h"

#define MODBUS_WAIT_FOR_CDC_INIT    0
#define MODBUS_WAIT                 1
#define MODBUS_IDLE                 2
#define MODBUS_RX                   3
#define MODBUS_PROCESS              4
#define MODBUS_TX                   5

#define BUFFER_LEN  64u
static void check_configuration( void );
static void check_read_data( void );


static uint8 input_buffer[BUFFER_LEN];
static uint8 output_buffer[BUFFER_LEN];
static int  usb_state;
static int  input_count;
static int output_count;
static int modbus_address;



void initialize_usb_serial( int address )
{
    modbus_address = address;
    initialize_modbus_slave();
    usb_state = MODBUS_WAIT_FOR_CDC_INIT;
    /* Start USBFS Operation with 5V operation */
    USBUART_1_Start(0u, USBUART_1_5V_OPERATION);
}

void process_usb_serial( int event )
{
    if( event & CF_TIME_TICK_EVENT )
    {
        check_configuration();
        check_read_data();
     }
}

static void check_configuration( void )
{

       if(USBUART_1_IsConfigurationChanged() != 0u) /* Host could send double SET_INTERFACE request */
        {
            usb_state = MODBUS_WAIT_FOR_CDC_INIT;
            if(USBUART_1_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
            {
                /* Enumeration is done, enable OUT endpoint for receive data from Host */
                USBUART_1_CDC_Init();
                usb_state = MODBUS_WAIT;
            }
        }         
 }

static void check_read_data( void )
{
    if((USBUART_1_GetConfiguration() == 0u) && (usb_state != MODBUS_WAIT ) &&(usb_state != MODBUS_WAIT_FOR_CDC_INIT ))    /* Service USB CDC when device configured */
    {
        usb_state = MODBUS_WAIT;
        return;
    }

    switch( usb_state)
    {
        case  MODBUS_WAIT_FOR_CDC_INIT:
             break;
        
        case MODBUS_WAIT:
          if(USBUART_1_GetConfiguration() == 1u)    /* Service USB CDC when device configured */
          {
                usb_state = MODBUS_IDLE;
       
          }
          break;

        case MODBUS_IDLE:
            if(USBUART_1_DataIsReady() != 0u)               /* Check for input data from PC */
            {   
                input_count = USBUART_1_GetAll(input_buffer);           /* Read received data and re-enable OUT endpoint */
                if( input_count > 0 )
                {
                    usb_state = MODBUS_PROCESS;
                }
            }
                
           break;
        
        case MODBUS_RX:
           break;
        
        case MODBUS_PROCESS:
           output_count = process_modbus_message( MODBUS_ALL_ADDRESSES, modbus_address, input_count, input_buffer, sizeof(output_buffer), output_buffer );
           if( output_count > 0 )
           {
              usb_state = MODBUS_TX;
           }
           else
           {
             usb_state = MODBUS_IDLE;
           }
           break;
        
        case MODBUS_TX:
             if( USBUART_1_CDCIsReady() == 1)    /* Wait till component is ready to send more data to the PC */
             {
                    USBUART_1_PutData(output_buffer, output_count);       /* Send data back to PC */
                    if( output_count == BUFFER_LEN )
                    {
                        while(USBUART_1_CDCIsReady() == 0u); /* Wait till component is ready to send more data to the PC */ 
                        USBUART_1_PutData(NULL, 0u);         /* Send zero-length packet to PC */
                    }
                    usb_state = MODBUS_IDLE; 
                    
             }
           break;

    }
 }





/* [] END OF FILE */
