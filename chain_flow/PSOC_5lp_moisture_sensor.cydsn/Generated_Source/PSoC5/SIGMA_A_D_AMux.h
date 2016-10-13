/*******************************************************************************
* File Name: SIGMA_A_D_AMux.h
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

#if !defined(CY_AMUX_SIGMA_A_D_AMux_H)
#define CY_AMUX_SIGMA_A_D_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void SIGMA_A_D_AMux_Start(void) ;
#define SIGMA_A_D_AMux_Init() SIGMA_A_D_AMux_Start()
void SIGMA_A_D_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void SIGMA_A_D_AMux_Stop(void); */
/* void SIGMA_A_D_AMux_Select(uint8 channel); */
/* void SIGMA_A_D_AMux_Connect(uint8 channel); */
/* void SIGMA_A_D_AMux_Disconnect(uint8 channel); */
/* void SIGMA_A_D_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define SIGMA_A_D_AMux_CHANNELS  2u
#define SIGMA_A_D_AMux_MUXTYPE   1
#define SIGMA_A_D_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define SIGMA_A_D_AMux_NULL_CHANNEL 0xFFu
#define SIGMA_A_D_AMux_MUX_SINGLE   1
#define SIGMA_A_D_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if SIGMA_A_D_AMux_MUXTYPE == SIGMA_A_D_AMux_MUX_SINGLE
# if !SIGMA_A_D_AMux_ATMOSTONE
#  define SIGMA_A_D_AMux_Connect(channel) SIGMA_A_D_AMux_Set(channel)
# endif
# define SIGMA_A_D_AMux_Disconnect(channel) SIGMA_A_D_AMux_Unset(channel)
#else
# if !SIGMA_A_D_AMux_ATMOSTONE
void SIGMA_A_D_AMux_Connect(uint8 channel) ;
# endif
void SIGMA_A_D_AMux_Disconnect(uint8 channel) ;
#endif

#if SIGMA_A_D_AMux_ATMOSTONE
# define SIGMA_A_D_AMux_Stop() SIGMA_A_D_AMux_DisconnectAll()
# define SIGMA_A_D_AMux_Select(channel) SIGMA_A_D_AMux_FastSelect(channel)
void SIGMA_A_D_AMux_DisconnectAll(void) ;
#else
# define SIGMA_A_D_AMux_Stop() SIGMA_A_D_AMux_Start()
void SIGMA_A_D_AMux_Select(uint8 channel) ;
# define SIGMA_A_D_AMux_DisconnectAll() SIGMA_A_D_AMux_Start()
#endif

#endif /* CY_AMUX_SIGMA_A_D_AMux_H */


/* [] END OF FILE */
