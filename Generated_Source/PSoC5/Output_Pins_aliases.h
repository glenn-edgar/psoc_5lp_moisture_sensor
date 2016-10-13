/*******************************************************************************
* File Name: Output_Pins.h  
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

#if !defined(CY_PINS_Output_Pins_ALIASES_H) /* Pins Output_Pins_ALIASES_H */
#define CY_PINS_Output_Pins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Output_Pins_0			(Output_Pins__0__PC)
#define Output_Pins_0_INTR	((uint16)((uint16)0x0001u << Output_Pins__0__SHIFT))

#define Output_Pins_1			(Output_Pins__1__PC)
#define Output_Pins_1_INTR	((uint16)((uint16)0x0001u << Output_Pins__1__SHIFT))

#define Output_Pins_2			(Output_Pins__2__PC)
#define Output_Pins_2_INTR	((uint16)((uint16)0x0001u << Output_Pins__2__SHIFT))

#define Output_Pins_3			(Output_Pins__3__PC)
#define Output_Pins_3_INTR	((uint16)((uint16)0x0001u << Output_Pins__3__SHIFT))

#define Output_Pins_INTR_ALL	 ((uint16)(Output_Pins_0_INTR| Output_Pins_1_INTR| Output_Pins_2_INTR| Output_Pins_3_INTR))

#endif /* End Pins Output_Pins_ALIASES_H */


/* [] END OF FILE */
