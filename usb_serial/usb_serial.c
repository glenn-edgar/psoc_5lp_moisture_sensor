/*
**
** File: usb_serial.c
**
**
*/


#include <device.h>
#include "cf_chain_flow_support.h"
#include "cf_external_functions.h"
#include "usb_serial.h"

#define USB_MODBUS_ADDRESS        25



int initialize_usb(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    USBUART_1_Start(0u, USBUART_1_5V_OPERATION);
    return CF_DISABLE;
}

// this is a wait condition
int usb_configuration_changed(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int return_value;
    if( USBUART_1_IsConfigurationChanged() != 0u )
    {
        if(USBUART_1_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
            {
                /* Enumeration is done, enable OUT endpoint for receive data from Host */
                USBUART_1_CDC_Init();
                return_value = 1;
                cf_enable_chain( usb_rx_packet );
            }
    }
    else
    {
        return_value =  0;
    }
    return return_value;
    
}

// this is a verify condition
int usb_connection_still_active(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
  int return_value;
  if( USBUART_1_IsConfigurationChanged() != 0 ) 
  {
    return_value = 0; // verify function will reset
  }
  else
  {
    return_value = 1; // link has not changed
  }
  return return_value;
}
    
   


int usb_can_receive(unsigned link_id, unsigned time_out,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
     int return_value;
    
     if( event == CF_INIT_EVENT )
     {
       cf_store_cell_value( link_id , 0 );
       return CF_CONTINUE;

     }
     if(USBUART_1_DataIsReady() != 0u)               /* Check for input data from PC */
     {
        return_value =  1 ; // wait condition is meet
     }
     else 
     {
        return_value = 0;
     }
     return return_value;    
     
   
}
static unsigned usb_rx_count;
static unsigned char usb_rx_buffer[ MODBUS_PACKET_SIZE];

int process_usb_rx_packet(unsigned link_id, unsigned usb_block,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int done_flag;
    done_flag = 0;
    switch( usb_block)
    {
        case 0: usb_rx_count = 0;
                usb_rx_count += USBUART_1_GetAll(&usb_rx_buffer[0]);
                if( usb_rx_count == 0 ) // empty packet
                {
                    cf_reset_chain(usb_rx_packet);
                }    
                else if( usb_rx_count < 64 )
                {
                    done_flag = 1;
                }

                break;
        case 1:
                usb_rx_count = 64;
                usb_rx_count += USBUART_1_GetAll(&usb_rx_buffer[0]);
                if( usb_rx_count < 128 )
                {
                    done_flag = 1;
                }
                
                break;
        case 2: 
                usb_rx_count = 128;
                usb_rx_count += USBUART_1_GetAll(&usb_rx_buffer[0]); 
                if( usb_rx_count < 196 )
                {
                    done_flag = 1;
                }

                break;
        case 3:
                
                usb_rx_count = 192;
                usb_rx_count += USBUART_1_GetAll(&usb_rx_buffer[192]);
                if( usb_rx_count < 256 )
                {
                    done_flag = 1;
                }
                break;
        case 4: 
                // this is the empty packet at modbus message 256
                usb_rx_count = 256;
                done_flag = 0;
                break;
        default:
                ; // should not happen
     }   
     if( done_flag != 0 )
     {
         cf_disable_chain(  usb_rx_packet );
         cf_enable_chain( usb_process_packet );
     }
          
    
    return CF_TERMINATE;
}

static unsigned usb_tx_count;
static unsigned char usb_tx_buffer[ MODBUS_PACKET_SIZE];

int usb_process_modbus_message(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    usb_tx_count = 256; // tbd      
    cf_enable_chain( usb_tx_packet );

    return CF_TERMINATE; //  will disable current chain
}


int usb_can_transmit(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int return_value;
    if( USBUART_1_CDCIsReady() == 1)    /* Wait till component is ready to send more data to the PC */
    {
        return_value = 1;
    }
    else
    {
        return_value = 0;
    }
    return return_value;
}

int usb_send_packet(unsigned link_id, unsigned tx_state,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int done_flag = 0;
    unsigned tx_count;
    
    done_flag = 0;
    switch( tx_state )
    {
        case 0:
               if( usb_tx_count < 64 )
               {
                  tx_count = usb_tx_count;
                  done_flag = 1;
               }
               else
               {
                  tx_count = 64;
                }
               USBUART_1_PutData(&usb_tx_buffer[0], tx_count);
               break;
        
        case 1:
               if( usb_tx_count < 128 )
               {
                  tx_count = usb_tx_count-64;
                  done_flag = 1;
               }
               else
               {
                  tx_count = 64;
                }
               USBUART_1_PutData(&usb_tx_buffer[64], tx_count);

               break;
        
        case 2:
               if( usb_tx_count < 192 )
               {
                  tx_count = usb_tx_count-128;
                  done_flag = 1;
               }
               else
               {
                  tx_count = 64;
                }
               USBUART_1_PutData(&usb_tx_buffer[128], tx_count);

              break;
        
        case 3:
               if( usb_tx_count < 255 )
               {
                  tx_count = usb_tx_count-192;
                  done_flag = 1;
               }
               else
               {
                  tx_count = 64;
                }
               USBUART_1_PutData(&usb_tx_buffer[196], tx_count);

            break;
        
        case 4:
               USBUART_1_PutData(&usb_tx_buffer[0], 0);
               done_flag = 1;
               break;
    }
    if( done_flag == 1 )
    {
         cf_enable_chain(  usb_rx_packet );
         cf_disable_chain( usb_tx_packet );
        
    }
    
    return CF_DISABLE;
}

#if 0
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
#endif