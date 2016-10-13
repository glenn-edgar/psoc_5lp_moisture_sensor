/*******************************************************************************
* File Name: Pin_Group_1.h  
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

#if !defined(CY_PINS_Pin_Group_1_ALIASES_H) /* Pins Pin_Group_1_ALIASES_H */
#define CY_PINS_Pin_Group_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_Group_1_0			(Pin_Group_1__0__PC)
#define Pin_Group_1_0_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__0__SHIFT))

#define Pin_Group_1_1			(Pin_Group_1__1__PC)
#define Pin_Group_1_1_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__1__SHIFT))

#define Pin_Group_1_2			(Pin_Group_1__2__PC)
#define Pin_Group_1_2_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__2__SHIFT))

#define Pin_Group_1_3			(Pin_Group_1__3__PC)
#define Pin_Group_1_3_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__3__SHIFT))

#define Pin_Group_1_4			(Pin_Group_1__4__PC)
#define Pin_Group_1_4_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__4__SHIFT))

#define Pin_Group_1_5			(Pin_Group_1__5__PC)
#define Pin_Group_1_5_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__5__SHIFT))

#define Pin_Group_1_6			(Pin_Group_1__6__PC)
#define Pin_Group_1_6_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__6__SHIFT))

#define Pin_Group_1_7			(Pin_Group_1__7__PC)
#define Pin_Group_1_7_INTR	((uint16)((uint16)0x0001u << Pin_Group_1__7__SHIFT))

#define Pin_Group_1_INTR_ALL	 ((uint16)(Pin_Group_1_0_INTR| Pin_Group_1_1_INTR| Pin_Group_1_2_INTR| Pin_Group_1_3_INTR| Pin_Group_1_4_INTR| Pin_Group_1_5_INTR| Pin_Group_1_6_INTR| Pin_Group_1_7_INTR))

#endif /* End Pins Pin_Group_1_ALIASES_H */


/* [] END OF FILE */
