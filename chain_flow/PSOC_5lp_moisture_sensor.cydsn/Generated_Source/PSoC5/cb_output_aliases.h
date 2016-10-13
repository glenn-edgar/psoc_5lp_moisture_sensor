/*******************************************************************************
* File Name: cb_output.h  
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

#if !defined(CY_PINS_cb_output_ALIASES_H) /* Pins cb_output_ALIASES_H */
#define CY_PINS_cb_output_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define cb_output_0			(cb_output__0__PC)
#define cb_output_0_INTR	((uint16)((uint16)0x0001u << cb_output__0__SHIFT))

#define cb_output_INTR_ALL	 ((uint16)(cb_output_0_INTR))

#endif /* End Pins cb_output_ALIASES_H */


/* [] END OF FILE */
