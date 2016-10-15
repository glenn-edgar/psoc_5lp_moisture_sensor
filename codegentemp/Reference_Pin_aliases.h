/*******************************************************************************
* File Name: Reference_Pin.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Reference_Pin_ALIASES_H) /* Pins Reference_Pin_ALIASES_H */
#define CY_PINS_Reference_Pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Reference_Pin_0			(Reference_Pin__0__PC)
#define Reference_Pin_0_INTR	((uint16)((uint16)0x0001u << Reference_Pin__0__SHIFT))

#define Reference_Pin_1			(Reference_Pin__1__PC)
#define Reference_Pin_1_INTR	((uint16)((uint16)0x0001u << Reference_Pin__1__SHIFT))

#define Reference_Pin_2			(Reference_Pin__2__PC)
#define Reference_Pin_2_INTR	((uint16)((uint16)0x0001u << Reference_Pin__2__SHIFT))

#define Reference_Pin_3			(Reference_Pin__3__PC)
#define Reference_Pin_3_INTR	((uint16)((uint16)0x0001u << Reference_Pin__3__SHIFT))

#define Reference_Pin_4			(Reference_Pin__4__PC)
#define Reference_Pin_4_INTR	((uint16)((uint16)0x0001u << Reference_Pin__4__SHIFT))

#define Reference_Pin_5			(Reference_Pin__5__PC)
#define Reference_Pin_5_INTR	((uint16)((uint16)0x0001u << Reference_Pin__5__SHIFT))

#define Reference_Pin_6			(Reference_Pin__6__PC)
#define Reference_Pin_6_INTR	((uint16)((uint16)0x0001u << Reference_Pin__6__SHIFT))

#define Reference_Pin_7			(Reference_Pin__7__PC)
#define Reference_Pin_7_INTR	((uint16)((uint16)0x0001u << Reference_Pin__7__SHIFT))

#define Reference_Pin_8			(Reference_Pin__8__PC)
#define Reference_Pin_8_INTR	((uint16)((uint16)0x0001u << Reference_Pin__8__SHIFT))

#define Reference_Pin_INTR_ALL	 ((uint16)(Reference_Pin_0_INTR| Reference_Pin_1_INTR| Reference_Pin_2_INTR| Reference_Pin_3_INTR| Reference_Pin_4_INTR| Reference_Pin_5_INTR| Reference_Pin_6_INTR| Reference_Pin_7_INTR| Reference_Pin_8_INTR))

#endif /* End Pins Reference_Pin_ALIASES_H */


/* [] END OF FILE */
