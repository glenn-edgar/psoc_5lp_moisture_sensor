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

#define Reference_Pin_9			(Reference_Pin__9__PC)
#define Reference_Pin_9_INTR	((uint16)((uint16)0x0001u << Reference_Pin__9__SHIFT))

#define Reference_Pin_10			(Reference_Pin__10__PC)
#define Reference_Pin_10_INTR	((uint16)((uint16)0x0001u << Reference_Pin__10__SHIFT))

#define Reference_Pin_11			(Reference_Pin__11__PC)
#define Reference_Pin_11_INTR	((uint16)((uint16)0x0001u << Reference_Pin__11__SHIFT))

#define Reference_Pin_12			(Reference_Pin__12__PC)
#define Reference_Pin_12_INTR	((uint16)((uint16)0x0001u << Reference_Pin__12__SHIFT))

#define Reference_Pin_13			(Reference_Pin__13__PC)
#define Reference_Pin_13_INTR	((uint16)((uint16)0x0001u << Reference_Pin__13__SHIFT))

#define Reference_Pin_14			(Reference_Pin__14__PC)
#define Reference_Pin_14_INTR	((uint16)((uint16)0x0001u << Reference_Pin__14__SHIFT))

#define Reference_Pin_15			(Reference_Pin__15__PC)
#define Reference_Pin_15_INTR	((uint16)((uint16)0x0001u << Reference_Pin__15__SHIFT))

#define Reference_Pin_INTR_ALL	 ((uint16)(Reference_Pin_0_INTR| Reference_Pin_1_INTR| Reference_Pin_2_INTR| Reference_Pin_3_INTR| Reference_Pin_4_INTR| Reference_Pin_5_INTR| Reference_Pin_6_INTR| Reference_Pin_7_INTR| Reference_Pin_8_INTR| Reference_Pin_9_INTR| Reference_Pin_10_INTR| Reference_Pin_11_INTR| Reference_Pin_12_INTR| Reference_Pin_13_INTR| Reference_Pin_14_INTR| Reference_Pin_15_INTR))

#endif /* End Pins Reference_Pin_ALIASES_H */


/* [] END OF FILE */
