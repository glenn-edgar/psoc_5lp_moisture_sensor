/*******************************************************************************
* File Name: output_configuration_select.h  
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

#if !defined(CY_PINS_output_configuration_select_ALIASES_H) /* Pins output_configuration_select_ALIASES_H */
#define CY_PINS_output_configuration_select_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define output_configuration_select_0			(output_configuration_select__0__PC)
#define output_configuration_select_0_INTR	((uint16)((uint16)0x0001u << output_configuration_select__0__SHIFT))

#define output_configuration_select_1			(output_configuration_select__1__PC)
#define output_configuration_select_1_INTR	((uint16)((uint16)0x0001u << output_configuration_select__1__SHIFT))

#define output_configuration_select_2			(output_configuration_select__2__PC)
#define output_configuration_select_2_INTR	((uint16)((uint16)0x0001u << output_configuration_select__2__SHIFT))

#define output_configuration_select_3			(output_configuration_select__3__PC)
#define output_configuration_select_3_INTR	((uint16)((uint16)0x0001u << output_configuration_select__3__SHIFT))

#define output_configuration_select_INTR_ALL	 ((uint16)(output_configuration_select_0_INTR| output_configuration_select_1_INTR| output_configuration_select_2_INTR| output_configuration_select_3_INTR))

#endif /* End Pins output_configuration_select_ALIASES_H */


/* [] END OF FILE */
