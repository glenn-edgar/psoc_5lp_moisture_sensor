/*******************************************************************************
* File Name: Sigma_A_D_MUX.h
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

#if !defined(CY_AMUX_Sigma_A_D_MUX_H)
#define CY_AMUX_Sigma_A_D_MUX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Sigma_A_D_MUX_Start(void) ;
#define Sigma_A_D_MUX_Init() Sigma_A_D_MUX_Start()
void Sigma_A_D_MUX_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Sigma_A_D_MUX_Stop(void); */
/* void Sigma_A_D_MUX_Select(uint8 channel); */
/* void Sigma_A_D_MUX_Connect(uint8 channel); */
/* void Sigma_A_D_MUX_Disconnect(uint8 channel); */
/* void Sigma_A_D_MUX_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Sigma_A_D_MUX_CHANNELS  4u
#define Sigma_A_D_MUX_MUXTYPE   2
#define Sigma_A_D_MUX_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Sigma_A_D_MUX_NULL_CHANNEL 0xFFu
#define Sigma_A_D_MUX_MUX_SINGLE   1
#define Sigma_A_D_MUX_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Sigma_A_D_MUX_MUXTYPE == Sigma_A_D_MUX_MUX_SINGLE
# if !Sigma_A_D_MUX_ATMOSTONE
#  define Sigma_A_D_MUX_Connect(channel) Sigma_A_D_MUX_Set(channel)
# endif
# define Sigma_A_D_MUX_Disconnect(channel) Sigma_A_D_MUX_Unset(channel)
#else
# if !Sigma_A_D_MUX_ATMOSTONE
void Sigma_A_D_MUX_Connect(uint8 channel) ;
# endif
void Sigma_A_D_MUX_Disconnect(uint8 channel) ;
#endif

#if Sigma_A_D_MUX_ATMOSTONE
# define Sigma_A_D_MUX_Stop() Sigma_A_D_MUX_DisconnectAll()
# define Sigma_A_D_MUX_Select(channel) Sigma_A_D_MUX_FastSelect(channel)
void Sigma_A_D_MUX_DisconnectAll(void) ;
#else
# define Sigma_A_D_MUX_Stop() Sigma_A_D_MUX_Start()
void Sigma_A_D_MUX_Select(uint8 channel) ;
# define Sigma_A_D_MUX_DisconnectAll() Sigma_A_D_MUX_Start()
#endif

#endif /* CY_AMUX_Sigma_A_D_MUX_H */


/* [] END OF FILE */
