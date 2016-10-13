/*******************************************************************************
* File Name: Sigma_A_D_MUX.c
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

#include "Sigma_A_D_MUX.h"

static uint8 Sigma_A_D_MUX_lastChannel = Sigma_A_D_MUX_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Sigma_A_D_MUX_Start
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
void Sigma_A_D_MUX_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Sigma_A_D_MUX_CHANNELS ; chan++)
    {
#if (Sigma_A_D_MUX_MUXTYPE == Sigma_A_D_MUX_MUX_SINGLE)
        Sigma_A_D_MUX_Unset(chan);
#else
        Sigma_A_D_MUX_CYAMUXSIDE_A_Unset(chan);
        Sigma_A_D_MUX_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Sigma_A_D_MUX_lastChannel = Sigma_A_D_MUX_NULL_CHANNEL;
}


#if (!Sigma_A_D_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_A_D_MUX_Select
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
void Sigma_A_D_MUX_Select(uint8 channel) 
{
    Sigma_A_D_MUX_DisconnectAll();        /* Disconnect all previous connections */
    Sigma_A_D_MUX_Connect(channel);       /* Make the given selection */
    Sigma_A_D_MUX_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Sigma_A_D_MUX_FastSelect
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
void Sigma_A_D_MUX_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Sigma_A_D_MUX_lastChannel != Sigma_A_D_MUX_NULL_CHANNEL)
    {
        Sigma_A_D_MUX_Disconnect(Sigma_A_D_MUX_lastChannel);
    }

    /* Make the new channel connection */
#if (Sigma_A_D_MUX_MUXTYPE == Sigma_A_D_MUX_MUX_SINGLE)
    Sigma_A_D_MUX_Set(channel);
#else
    Sigma_A_D_MUX_CYAMUXSIDE_A_Set(channel);
    Sigma_A_D_MUX_CYAMUXSIDE_B_Set(channel);
#endif


    Sigma_A_D_MUX_lastChannel = channel;   /* Update last channel */
}


#if (Sigma_A_D_MUX_MUXTYPE == Sigma_A_D_MUX_MUX_DIFF)
#if (!Sigma_A_D_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_A_D_MUX_Connect
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
void Sigma_A_D_MUX_Connect(uint8 channel) 
{
    Sigma_A_D_MUX_CYAMUXSIDE_A_Set(channel);
    Sigma_A_D_MUX_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Sigma_A_D_MUX_Disconnect
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
void Sigma_A_D_MUX_Disconnect(uint8 channel) 
{
    Sigma_A_D_MUX_CYAMUXSIDE_A_Unset(channel);
    Sigma_A_D_MUX_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Sigma_A_D_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: Sigma_A_D_MUX_DisconnectAll
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
void Sigma_A_D_MUX_DisconnectAll(void) 
{
    if(Sigma_A_D_MUX_lastChannel != Sigma_A_D_MUX_NULL_CHANNEL) 
    {
        Sigma_A_D_MUX_Disconnect(Sigma_A_D_MUX_lastChannel);
        Sigma_A_D_MUX_lastChannel = Sigma_A_D_MUX_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
