/*******************************************************************************
* File Name: Sigma_Mux_Differential.c
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

#include "Sigma_Mux_Differential.h"

static uint8 Sigma_Mux_Differential_lastChannel = Sigma_Mux_Differential_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Sigma_Mux_Differential_Start
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
void Sigma_Mux_Differential_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Sigma_Mux_Differential_CHANNELS ; chan++)
    {
#if (Sigma_Mux_Differential_MUXTYPE == Sigma_Mux_Differential_MUX_SINGLE)
        Sigma_Mux_Differential_Unset(chan);
#else
        Sigma_Mux_Differential_CYAMUXSIDE_A_Unset(chan);
        Sigma_Mux_Differential_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Sigma_Mux_Differential_lastChannel = Sigma_Mux_Differential_NULL_CHANNEL;
}


#if (!Sigma_Mux_Differential_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_Mux_Differential_Select
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
void Sigma_Mux_Differential_Select(uint8 channel) 
{
    Sigma_Mux_Differential_DisconnectAll();        /* Disconnect all previous connections */
    Sigma_Mux_Differential_Connect(channel);       /* Make the given selection */
    Sigma_Mux_Differential_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Sigma_Mux_Differential_FastSelect
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
void Sigma_Mux_Differential_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Sigma_Mux_Differential_lastChannel != Sigma_Mux_Differential_NULL_CHANNEL)
    {
        Sigma_Mux_Differential_Disconnect(Sigma_Mux_Differential_lastChannel);
    }

    /* Make the new channel connection */
#if (Sigma_Mux_Differential_MUXTYPE == Sigma_Mux_Differential_MUX_SINGLE)
    Sigma_Mux_Differential_Set(channel);
#else
    Sigma_Mux_Differential_CYAMUXSIDE_A_Set(channel);
    Sigma_Mux_Differential_CYAMUXSIDE_B_Set(channel);
#endif


    Sigma_Mux_Differential_lastChannel = channel;   /* Update last channel */
}


#if (Sigma_Mux_Differential_MUXTYPE == Sigma_Mux_Differential_MUX_DIFF)
#if (!Sigma_Mux_Differential_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_Mux_Differential_Connect
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
void Sigma_Mux_Differential_Connect(uint8 channel) 
{
    Sigma_Mux_Differential_CYAMUXSIDE_A_Set(channel);
    Sigma_Mux_Differential_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Sigma_Mux_Differential_Disconnect
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
void Sigma_Mux_Differential_Disconnect(uint8 channel) 
{
    Sigma_Mux_Differential_CYAMUXSIDE_A_Unset(channel);
    Sigma_Mux_Differential_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Sigma_Mux_Differential_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_Mux_Differential_DisconnectAll
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
void Sigma_Mux_Differential_DisconnectAll(void) 
{
    if(Sigma_Mux_Differential_lastChannel != Sigma_Mux_Differential_NULL_CHANNEL) 
    {
        Sigma_Mux_Differential_Disconnect(Sigma_Mux_Differential_lastChannel);
        Sigma_Mux_Differential_lastChannel = Sigma_Mux_Differential_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
