/*******************************************************************************
* File Name: wave_form_dac_input.h  
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

#if !defined(CY_PINS_wave_form_dac_input_ALIASES_H) /* Pins wave_form_dac_input_ALIASES_H */
#define CY_PINS_wave_form_dac_input_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define wave_form_dac_input_0			(wave_form_dac_input__0__PC)
#define wave_form_dac_input_0_INTR	((uint16)((uint16)0x0001u << wave_form_dac_input__0__SHIFT))

#define wave_form_dac_input_INTR_ALL	 ((uint16)(wave_form_dac_input_0_INTR))

#endif /* End Pins wave_form_dac_input_ALIASES_H */


/* [] END OF FILE */
