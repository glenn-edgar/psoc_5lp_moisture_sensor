/*******************************************************************************
* File Name: AMux_4.h
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

#if !defined(CY_AMUX_AMux_4_H)
#define CY_AMUX_AMux_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void AMux_4_Start(void) ;
#define AMux_4_Init() AMux_4_Start()
void AMux_4_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_4_Stop(void); */
/* void AMux_4_Select(uint8 channel); */
/* void AMux_4_Connect(uint8 channel); */
/* void AMux_4_Disconnect(uint8 channel); */
/* void AMux_4_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_4_CHANNELS  2u
#define AMux_4_MUXTYPE   1
#define AMux_4_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMux_4_NULL_CHANNEL 0xFFu
#define AMux_4_MUX_SINGLE   1
#define AMux_4_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_4_MUXTYPE == AMux_4_MUX_SINGLE
# if !AMux_4_ATMOSTONE
#  define AMux_4_Connect(channel) AMux_4_Set(channel)
# endif
# define AMux_4_Disconnect(channel) AMux_4_Unset(channel)
#else
# if !AMux_4_ATMOSTONE
void AMux_4_Connect(uint8 channel) ;
# endif
void AMux_4_Disconnect(uint8 channel) ;
#endif

#if AMux_4_ATMOSTONE
# define AMux_4_Stop() AMux_4_DisconnectAll()
# define AMux_4_Select(channel) AMux_4_FastSelect(channel)
void AMux_4_DisconnectAll(void) ;
#else
# define AMux_4_Stop() AMux_4_Start()
void AMux_4_Select(uint8 channel) ;
# define AMux_4_DisconnectAll() AMux_4_Start()
#endif

#endif /* CY_AMUX_AMux_4_H */


/* [] END OF FILE */
