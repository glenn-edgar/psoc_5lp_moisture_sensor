/*******************************************************************************
* File Name: Sink_Source_Setup.c
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

#include "Sink_Source_Setup.h"

static uint8 Sink_Source_Setup_lastChannel = Sink_Source_Setup_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Sink_Source_Setup_Start
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
void Sink_Source_Setup_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Sink_Source_Setup_CHANNELS ; chan++)
    {
#if (Sink_Source_Setup_MUXTYPE == Sink_Source_Setup_MUX_SINGLE)
        Sink_Source_Setup_Unset(chan);
#else
        Sink_Source_Setup_CYAMUXSIDE_A_Unset(chan);
        Sink_Source_Setup_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Sink_Source_Setup_lastChannel = Sink_Source_Setup_NULL_CHANNEL;
}


#if (!Sink_Source_Setup_ATMOSTONE)
/*******************************************************************************
* Function Name: Sink_Source_Setup_Select
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
void Sink_Source_Setup_Select(uint8 channel) 
{
    Sink_Source_Setup_DisconnectAll();        /* Disconnect all previous connections */
    Sink_Source_Setup_Connect(channel);       /* Make the given selection */
    Sink_Source_Setup_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Sink_Source_Setup_FastSelect
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
void Sink_Source_Setup_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Sink_Source_Setup_lastChannel != Sink_Source_Setup_NULL_CHANNEL)
    {
        Sink_Source_Setup_Disconnect(Sink_Source_Setup_lastChannel);
    }

    /* Make the new channel connection */
#if (Sink_Source_Setup_MUXTYPE == Sink_Source_Setup_MUX_SINGLE)
    Sink_Source_Setup_Set(channel);
#else
    Sink_Source_Setup_CYAMUXSIDE_A_Set(channel);
    Sink_Source_Setup_CYAMUXSIDE_B_Set(channel);
#endif


    Sink_Source_Setup_lastChannel = channel;   /* Update last channel */
}


#if (Sink_Source_Setup_MUXTYPE == Sink_Source_Setup_MUX_DIFF)
#if (!Sink_Source_Setup_ATMOSTONE)
/*******************************************************************************
* Function Name: Sink_Source_Setup_Connect
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
void Sink_Source_Setup_Connect(uint8 channel) 
{
    Sink_Source_Setup_CYAMUXSIDE_A_Set(channel);
    Sink_Source_Setup_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Sink_Source_Setup_Disconnect
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
void Sink_Source_Setup_Disconnect(uint8 channel) 
{
    Sink_Source_Setup_CYAMUXSIDE_A_Unset(channel);
    Sink_Source_Setup_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Sink_Source_Setup_ATMOSTONE)
/*******************************************************************************
* Function Name: Sink_Source_Setup_DisconnectAll
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
void Sink_Source_Setup_DisconnectAll(void) 
{
    if(Sink_Source_Setup_lastChannel != Sink_Source_Setup_NULL_CHANNEL) 
    {
        Sink_Source_Setup_Disconnect(Sink_Source_Setup_lastChannel);
        Sink_Source_Setup_lastChannel = Sink_Source_Setup_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
