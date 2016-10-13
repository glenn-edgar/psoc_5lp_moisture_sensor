/*******************************************************************************
* File Name: pump_drive_current.h  
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

#if !defined(CY_PINS_pump_drive_current_ALIASES_H) /* Pins pump_drive_current_ALIASES_H */
#define CY_PINS_pump_drive_current_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define pump_drive_current_0			(pump_drive_current__0__PC)
#define pump_drive_current_0_INTR	((uint16)((uint16)0x0001u << pump_drive_current__0__SHIFT))

#define pump_drive_current_INTR_ALL	 ((uint16)(pump_drive_current_0_INTR))

#endif /* End Pins pump_drive_current_ALIASES_H */


/* [] END OF FILE */
