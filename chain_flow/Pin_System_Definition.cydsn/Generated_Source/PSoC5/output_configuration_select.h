/*******************************************************************************
* File Name: output_configuration_select.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_output_configuration_select_H) /* Pins output_configuration_select_H */
#define CY_PINS_output_configuration_select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "output_configuration_select_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 output_configuration_select__PORT == 15 && ((output_configuration_select__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    output_configuration_select_Write(uint8 value);
void    output_configuration_select_SetDriveMode(uint8 mode);
uint8   output_configuration_select_ReadDataReg(void);
uint8   output_configuration_select_Read(void);
void    output_configuration_select_SetInterruptMode(uint16 position, uint16 mode);
uint8   output_configuration_select_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the output_configuration_select_SetDriveMode() function.
     *  @{
     */
        #define output_configuration_select_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define output_configuration_select_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define output_configuration_select_DM_RES_UP          PIN_DM_RES_UP
        #define output_configuration_select_DM_RES_DWN         PIN_DM_RES_DWN
        #define output_configuration_select_DM_OD_LO           PIN_DM_OD_LO
        #define output_configuration_select_DM_OD_HI           PIN_DM_OD_HI
        #define output_configuration_select_DM_STRONG          PIN_DM_STRONG
        #define output_configuration_select_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define output_configuration_select_MASK               output_configuration_select__MASK
#define output_configuration_select_SHIFT              output_configuration_select__SHIFT
#define output_configuration_select_WIDTH              4u

/* Interrupt constants */
#if defined(output_configuration_select__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in output_configuration_select_SetInterruptMode() function.
     *  @{
     */
        #define output_configuration_select_INTR_NONE      (uint16)(0x0000u)
        #define output_configuration_select_INTR_RISING    (uint16)(0x0001u)
        #define output_configuration_select_INTR_FALLING   (uint16)(0x0002u)
        #define output_configuration_select_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define output_configuration_select_INTR_MASK      (0x01u) 
#endif /* (output_configuration_select__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define output_configuration_select_PS                     (* (reg8 *) output_configuration_select__PS)
/* Data Register */
#define output_configuration_select_DR                     (* (reg8 *) output_configuration_select__DR)
/* Port Number */
#define output_configuration_select_PRT_NUM                (* (reg8 *) output_configuration_select__PRT) 
/* Connect to Analog Globals */                                                  
#define output_configuration_select_AG                     (* (reg8 *) output_configuration_select__AG)                       
/* Analog MUX bux enable */
#define output_configuration_select_AMUX                   (* (reg8 *) output_configuration_select__AMUX) 
/* Bidirectional Enable */                                                        
#define output_configuration_select_BIE                    (* (reg8 *) output_configuration_select__BIE)
/* Bit-mask for Aliased Register Access */
#define output_configuration_select_BIT_MASK               (* (reg8 *) output_configuration_select__BIT_MASK)
/* Bypass Enable */
#define output_configuration_select_BYP                    (* (reg8 *) output_configuration_select__BYP)
/* Port wide control signals */                                                   
#define output_configuration_select_CTL                    (* (reg8 *) output_configuration_select__CTL)
/* Drive Modes */
#define output_configuration_select_DM0                    (* (reg8 *) output_configuration_select__DM0) 
#define output_configuration_select_DM1                    (* (reg8 *) output_configuration_select__DM1)
#define output_configuration_select_DM2                    (* (reg8 *) output_configuration_select__DM2) 
/* Input Buffer Disable Override */
#define output_configuration_select_INP_DIS                (* (reg8 *) output_configuration_select__INP_DIS)
/* LCD Common or Segment Drive */
#define output_configuration_select_LCD_COM_SEG            (* (reg8 *) output_configuration_select__LCD_COM_SEG)
/* Enable Segment LCD */
#define output_configuration_select_LCD_EN                 (* (reg8 *) output_configuration_select__LCD_EN)
/* Slew Rate Control */
#define output_configuration_select_SLW                    (* (reg8 *) output_configuration_select__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define output_configuration_select_PRTDSI__CAPS_SEL       (* (reg8 *) output_configuration_select__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define output_configuration_select_PRTDSI__DBL_SYNC_IN    (* (reg8 *) output_configuration_select__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define output_configuration_select_PRTDSI__OE_SEL0        (* (reg8 *) output_configuration_select__PRTDSI__OE_SEL0) 
#define output_configuration_select_PRTDSI__OE_SEL1        (* (reg8 *) output_configuration_select__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define output_configuration_select_PRTDSI__OUT_SEL0       (* (reg8 *) output_configuration_select__PRTDSI__OUT_SEL0) 
#define output_configuration_select_PRTDSI__OUT_SEL1       (* (reg8 *) output_configuration_select__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define output_configuration_select_PRTDSI__SYNC_OUT       (* (reg8 *) output_configuration_select__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(output_configuration_select__SIO_CFG)
    #define output_configuration_select_SIO_HYST_EN        (* (reg8 *) output_configuration_select__SIO_HYST_EN)
    #define output_configuration_select_SIO_REG_HIFREQ     (* (reg8 *) output_configuration_select__SIO_REG_HIFREQ)
    #define output_configuration_select_SIO_CFG            (* (reg8 *) output_configuration_select__SIO_CFG)
    #define output_configuration_select_SIO_DIFF           (* (reg8 *) output_configuration_select__SIO_DIFF)
#endif /* (output_configuration_select__SIO_CFG) */

/* Interrupt Registers */
#if defined(output_configuration_select__INTSTAT)
    #define output_configuration_select_INTSTAT            (* (reg8 *) output_configuration_select__INTSTAT)
    #define output_configuration_select_SNAP               (* (reg8 *) output_configuration_select__SNAP)
    
	#define output_configuration_select_0_INTTYPE_REG 		(* (reg8 *) output_configuration_select__0__INTTYPE)
	#define output_configuration_select_1_INTTYPE_REG 		(* (reg8 *) output_configuration_select__1__INTTYPE)
	#define output_configuration_select_2_INTTYPE_REG 		(* (reg8 *) output_configuration_select__2__INTTYPE)
	#define output_configuration_select_3_INTTYPE_REG 		(* (reg8 *) output_configuration_select__3__INTTYPE)
#endif /* (output_configuration_select__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_output_configuration_select_H */


/* [] END OF FILE */
