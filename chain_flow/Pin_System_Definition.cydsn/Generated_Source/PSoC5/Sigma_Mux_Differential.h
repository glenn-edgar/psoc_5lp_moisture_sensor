/*******************************************************************************
* File Name: Sigma_Mux_Differential.h
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

#if !defined(CY_AMUX_Sigma_Mux_Differential_H)
#define CY_AMUX_Sigma_Mux_Differential_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Sigma_Mux_Differential_Start(void) ;
#define Sigma_Mux_Differential_Init() Sigma_Mux_Differential_Start()
void Sigma_Mux_Differential_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Sigma_Mux_Differential_Stop(void); */
/* void Sigma_Mux_Differential_Select(uint8 channel); */
/* void Sigma_Mux_Differential_Connect(uint8 channel); */
/* void Sigma_Mux_Differential_Disconnect(uint8 channel); */
/* void Sigma_Mux_Differential_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Sigma_Mux_Differential_CHANNELS  4u
#define Sigma_Mux_Differential_MUXTYPE   2
#define Sigma_Mux_Differential_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Sigma_Mux_Differential_NULL_CHANNEL 0xFFu
#define Sigma_Mux_Differential_MUX_SINGLE   1
#define Sigma_Mux_Differential_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Sigma_Mux_Differential_MUXTYPE == Sigma_Mux_Differential_MUX_SINGLE
# if !Sigma_Mux_Differential_ATMOSTONE
#  define Sigma_Mux_Differential_Connect(channel) Sigma_Mux_Differential_Set(channel)
# endif
# define Sigma_Mux_Differential_Disconnect(channel) Sigma_Mux_Differential_Unset(channel)
#else
# if !Sigma_Mux_Differential_ATMOSTONE
void Sigma_Mux_Differential_Connect(uint8 channel) ;
# endif
void Sigma_Mux_Differential_Disconnect(uint8 channel) ;
#endif

#if Sigma_Mux_Differential_ATMOSTONE
# define Sigma_Mux_Differential_Stop() Sigma_Mux_Differential_DisconnectAll()
# define Sigma_Mux_Differential_Select(channel) Sigma_Mux_Differential_FastSelect(channel)
void Sigma_Mux_Differential_DisconnectAll(void) ;
#else
# define Sigma_Mux_Differential_Stop() Sigma_Mux_Differential_Start()
void Sigma_Mux_Differential_Select(uint8 channel) ;
# define Sigma_Mux_Differential_DisconnectAll() Sigma_Mux_Differential_Start()
#endif

#endif /* CY_AMUX_Sigma_Mux_Differential_H */


/* [] END OF FILE */
