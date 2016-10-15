/*******************************************************************************
* File Name: Sink_Source_Setup.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Sink_Source_Setup_H)
#define CY_AMUX_Sink_Source_Setup_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Sink_Source_Setup_Start(void) ;
#define Sink_Source_Setup_Init() Sink_Source_Setup_Start()
void Sink_Source_Setup_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Sink_Source_Setup_Stop(void); */
/* void Sink_Source_Setup_Select(uint8 channel); */
/* void Sink_Source_Setup_Connect(uint8 channel); */
/* void Sink_Source_Setup_Disconnect(uint8 channel); */
/* void Sink_Source_Setup_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Sink_Source_Setup_CHANNELS  11u
#define Sink_Source_Setup_MUXTYPE   1
#define Sink_Source_Setup_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Sink_Source_Setup_NULL_CHANNEL 0xFFu
#define Sink_Source_Setup_MUX_SINGLE   1
#define Sink_Source_Setup_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Sink_Source_Setup_MUXTYPE == Sink_Source_Setup_MUX_SINGLE
# if !Sink_Source_Setup_ATMOSTONE
#  define Sink_Source_Setup_Connect(channel) Sink_Source_Setup_Set(channel)
# endif
# define Sink_Source_Setup_Disconnect(channel) Sink_Source_Setup_Unset(channel)
#else
# if !Sink_Source_Setup_ATMOSTONE
void Sink_Source_Setup_Connect(uint8 channel) ;
# endif
void Sink_Source_Setup_Disconnect(uint8 channel) ;
#endif

#if Sink_Source_Setup_ATMOSTONE
# define Sink_Source_Setup_Stop() Sink_Source_Setup_DisconnectAll()
# define Sink_Source_Setup_Select(channel) Sink_Source_Setup_FastSelect(channel)
void Sink_Source_Setup_DisconnectAll(void) ;
#else
# define Sink_Source_Setup_Stop() Sink_Source_Setup_Start()
void Sink_Source_Setup_Select(uint8 channel) ;
# define Sink_Source_Setup_DisconnectAll() Sink_Source_Setup_Start()
#endif

#endif /* CY_AMUX_Sink_Source_Setup_H */


/* [] END OF FILE */
