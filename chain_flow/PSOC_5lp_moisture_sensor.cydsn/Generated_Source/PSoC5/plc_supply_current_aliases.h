/*******************************************************************************
* File Name: plc_supply_current.h  
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

#if !defined(CY_PINS_plc_supply_current_ALIASES_H) /* Pins plc_supply_current_ALIASES_H */
#define CY_PINS_plc_supply_current_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define plc_supply_current_0			(plc_supply_current__0__PC)
#define plc_supply_current_0_INTR	((uint16)((uint16)0x0001u << plc_supply_current__0__SHIFT))

#define plc_supply_current_INTR_ALL	 ((uint16)(plc_supply_current_0_INTR))

#endif /* End Pins plc_supply_current_ALIASES_H */


/* [] END OF FILE */
