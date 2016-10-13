/*******************************************************************************
* File Name: Analog_Source_Mux.h
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

#if !defined(CY_AMUX_Analog_Source_Mux_H)
#define CY_AMUX_Analog_Source_Mux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Analog_Source_Mux_Start(void) ;
#define Analog_Source_Mux_Init() Analog_Source_Mux_Start()
void Analog_Source_Mux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Analog_Source_Mux_Stop(void); */
/* void Analog_Source_Mux_Select(uint8 channel); */
/* void Analog_Source_Mux_Connect(uint8 channel); */
/* void Analog_Source_Mux_Disconnect(uint8 channel); */
/* void Analog_Source_Mux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Analog_Source_Mux_CHANNELS  9u
#define Analog_Source_Mux_MUXTYPE   1
#define Analog_Source_Mux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Analog_Source_Mux_NULL_CHANNEL 0xFFu
#define Analog_Source_Mux_MUX_SINGLE   1
#define Analog_Source_Mux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Analog_Source_Mux_MUXTYPE == Analog_Source_Mux_MUX_SINGLE
# if !Analog_Source_Mux_ATMOSTONE
#  define Analog_Source_Mux_Connect(channel) Analog_Source_Mux_Set(channel)
# endif
# define Analog_Source_Mux_Disconnect(channel) Analog_Source_Mux_Unset(channel)
#else
# if !Analog_Source_Mux_ATMOSTONE
void Analog_Source_Mux_Connect(uint8 channel) ;
# endif
void Analog_Source_Mux_Disconnect(uint8 channel) ;
#endif

#if Analog_Source_Mux_ATMOSTONE
# define Analog_Source_Mux_Stop() Analog_Source_Mux_DisconnectAll()
# define Analog_Source_Mux_Select(channel) Analog_Source_Mux_FastSelect(channel)
void Analog_Source_Mux_DisconnectAll(void) ;
#else
# define Analog_Source_Mux_Stop() Analog_Source_Mux_Start()
void Analog_Source_Mux_Select(uint8 channel) ;
# define Analog_Source_Mux_DisconnectAll() Analog_Source_Mux_Start()
#endif

#endif /* CY_AMUX_Analog_Source_Mux_H */


/* [] END OF FILE */
