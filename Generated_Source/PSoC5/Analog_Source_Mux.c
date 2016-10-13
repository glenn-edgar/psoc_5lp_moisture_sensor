/*******************************************************************************
* File Name: Analog_Source_Mux.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Analog_Source_Mux.h"

static uint8 Analog_Source_Mux_lastChannel = Analog_Source_Mux_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Analog_Source_Mux_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Analog_Source_Mux_CHANNELS ; chan++)
    {
#if (Analog_Source_Mux_MUXTYPE == Analog_Source_Mux_MUX_SINGLE)
        Analog_Source_Mux_Unset(chan);
#else
        Analog_Source_Mux_CYAMUXSIDE_A_Unset(chan);
        Analog_Source_Mux_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Analog_Source_Mux_lastChannel = Analog_Source_Mux_NULL_CHANNEL;
}


#if (!Analog_Source_Mux_ATMOSTONE)
/*******************************************************************************
* Function Name: Analog_Source_Mux_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_Select(uint8 channel) 
{
    Analog_Source_Mux_DisconnectAll();        /* Disconnect all previous connections */
    Analog_Source_Mux_Connect(channel);       /* Make the given selection */
    Analog_Source_Mux_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Analog_Source_Mux_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Analog_Source_Mux_lastChannel != Analog_Source_Mux_NULL_CHANNEL)
    {
        Analog_Source_Mux_Disconnect(Analog_Source_Mux_lastChannel);
    }

    /* Make the new channel connection */
#if (Analog_Source_Mux_MUXTYPE == Analog_Source_Mux_MUX_SINGLE)
    Analog_Source_Mux_Set(channel);
#else
    Analog_Source_Mux_CYAMUXSIDE_A_Set(channel);
    Analog_Source_Mux_CYAMUXSIDE_B_Set(channel);
#endif


    Analog_Source_Mux_lastChannel = channel;   /* Update last channel */
}


#if (Analog_Source_Mux_MUXTYPE == Analog_Source_Mux_MUX_DIFF)
#if (!Analog_Source_Mux_ATMOSTONE)
/*******************************************************************************
* Function Name: Analog_Source_Mux_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_Connect(uint8 channel) 
{
    Analog_Source_Mux_CYAMUXSIDE_A_Set(channel);
    Analog_Source_Mux_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Analog_Source_Mux_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_Disconnect(uint8 channel) 
{
    Analog_Source_Mux_CYAMUXSIDE_A_Unset(channel);
    Analog_Source_Mux_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Analog_Source_Mux_ATMOSTONE)
/*******************************************************************************
* Function Name: Analog_Source_Mux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Analog_Source_Mux_DisconnectAll(void) 
{
    if(Analog_Source_Mux_lastChannel != Analog_Source_Mux_NULL_CHANNEL) 
    {
        Analog_Source_Mux_Disconnect(Analog_Source_Mux_lastChannel);
        Analog_Source_Mux_lastChannel = Analog_Source_Mux_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
