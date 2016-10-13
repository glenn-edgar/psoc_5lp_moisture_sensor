/*******************************************************************************
* File Name: Sigma_Mux.h
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

#if !defined(CY_AMUX_Sigma_Mux_H)
#define CY_AMUX_Sigma_Mux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Sigma_Mux_Start(void) ;
#define Sigma_Mux_Init() Sigma_Mux_Start()
void Sigma_Mux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Sigma_Mux_Stop(void); */
/* void Sigma_Mux_Select(uint8 channel); */
/* void Sigma_Mux_Connect(uint8 channel); */
/* void Sigma_Mux_Disconnect(uint8 channel); */
/* void Sigma_Mux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Sigma_Mux_CHANNELS  4u
#define Sigma_Mux_MUXTYPE   2
#define Sigma_Mux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Sigma_Mux_NULL_CHANNEL 0xFFu
#define Sigma_Mux_MUX_SINGLE   1
#define Sigma_Mux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Sigma_Mux_MUXTYPE == Sigma_Mux_MUX_SINGLE
# if !Sigma_Mux_ATMOSTONE
#  define Sigma_Mux_Connect(channel) Sigma_Mux_Set(channel)
# endif
# define Sigma_Mux_Disconnect(channel) Sigma_Mux_Unset(channel)
#else
# if !Sigma_Mux_ATMOSTONE
void Sigma_Mux_Connect(uint8 channel) ;
# endif
void Sigma_Mux_Disconnect(uint8 channel) ;
#endif

#if Sigma_Mux_ATMOSTONE
# define Sigma_Mux_Stop() Sigma_Mux_DisconnectAll()
# define Sigma_Mux_Select(channel) Sigma_Mux_FastSelect(channel)
void Sigma_Mux_DisconnectAll(void) ;
#else
# define Sigma_Mux_Stop() Sigma_Mux_Start()
void Sigma_Mux_Select(uint8 channel) ;
# define Sigma_Mux_DisconnectAll() Sigma_Mux_Start()
#endif

#endif /* CY_AMUX_Sigma_Mux_H */


/* [] END OF FILE */
