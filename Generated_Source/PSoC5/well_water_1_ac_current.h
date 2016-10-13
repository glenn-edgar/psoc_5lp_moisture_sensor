/*******************************************************************************
* File Name: well_water_1_ac_current.h  
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

#if !defined(CY_PINS_well_water_1_ac_current_H) /* Pins well_water_1_ac_current_H */
#define CY_PINS_well_water_1_ac_current_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "well_water_1_ac_current_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 well_water_1_ac_current__PORT == 15 && ((well_water_1_ac_current__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    well_water_1_ac_current_Write(uint8 value);
void    well_water_1_ac_current_SetDriveMode(uint8 mode);
uint8   well_water_1_ac_current_ReadDataReg(void);
uint8   well_water_1_ac_current_Read(void);
void    well_water_1_ac_current_SetInterruptMode(uint16 position, uint16 mode);
uint8   well_water_1_ac_current_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the well_water_1_ac_current_SetDriveMode() function.
     *  @{
     */
        #define well_water_1_ac_current_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define well_water_1_ac_current_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define well_water_1_ac_current_DM_RES_UP          PIN_DM_RES_UP
        #define well_water_1_ac_current_DM_RES_DWN         PIN_DM_RES_DWN
        #define well_water_1_ac_current_DM_OD_LO           PIN_DM_OD_LO
        #define well_water_1_ac_current_DM_OD_HI           PIN_DM_OD_HI
        #define well_water_1_ac_current_DM_STRONG          PIN_DM_STRONG
        #define well_water_1_ac_current_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define well_water_1_ac_current_MASK               well_water_1_ac_current__MASK
#define well_water_1_ac_current_SHIFT              well_water_1_ac_current__SHIFT
#define well_water_1_ac_current_WIDTH              1u

/* Interrupt constants */
#if defined(well_water_1_ac_current__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in well_water_1_ac_current_SetInterruptMode() function.
     *  @{
     */
        #define well_water_1_ac_current_INTR_NONE      (uint16)(0x0000u)
        #define well_water_1_ac_current_INTR_RISING    (uint16)(0x0001u)
        #define well_water_1_ac_current_INTR_FALLING   (uint16)(0x0002u)
        #define well_water_1_ac_current_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define well_water_1_ac_current_INTR_MASK      (0x01u) 
#endif /* (well_water_1_ac_current__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define well_water_1_ac_current_PS                     (* (reg8 *) well_water_1_ac_current__PS)
/* Data Register */
#define well_water_1_ac_current_DR                     (* (reg8 *) well_water_1_ac_current__DR)
/* Port Number */
#define well_water_1_ac_current_PRT_NUM                (* (reg8 *) well_water_1_ac_current__PRT) 
/* Connect to Analog Globals */                                                  
#define well_water_1_ac_current_AG                     (* (reg8 *) well_water_1_ac_current__AG)                       
/* Analog MUX bux enable */
#define well_water_1_ac_current_AMUX                   (* (reg8 *) well_water_1_ac_current__AMUX) 
/* Bidirectional Enable */                                                        
#define well_water_1_ac_current_BIE                    (* (reg8 *) well_water_1_ac_current__BIE)
/* Bit-mask for Aliased Register Access */
#define well_water_1_ac_current_BIT_MASK               (* (reg8 *) well_water_1_ac_current__BIT_MASK)
/* Bypass Enable */
#define well_water_1_ac_current_BYP                    (* (reg8 *) well_water_1_ac_current__BYP)
/* Port wide control signals */                                                   
#define well_water_1_ac_current_CTL                    (* (reg8 *) well_water_1_ac_current__CTL)
/* Drive Modes */
#define well_water_1_ac_current_DM0                    (* (reg8 *) well_water_1_ac_current__DM0) 
#define well_water_1_ac_current_DM1                    (* (reg8 *) well_water_1_ac_current__DM1)
#define well_water_1_ac_current_DM2                    (* (reg8 *) well_water_1_ac_current__DM2) 
/* Input Buffer Disable Override */
#define well_water_1_ac_current_INP_DIS                (* (reg8 *) well_water_1_ac_current__INP_DIS)
/* LCD Common or Segment Drive */
#define well_water_1_ac_current_LCD_COM_SEG            (* (reg8 *) well_water_1_ac_current__LCD_COM_SEG)
/* Enable Segment LCD */
#define well_water_1_ac_current_LCD_EN                 (* (reg8 *) well_water_1_ac_current__LCD_EN)
/* Slew Rate Control */
#define well_water_1_ac_current_SLW                    (* (reg8 *) well_water_1_ac_current__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define well_water_1_ac_current_PRTDSI__CAPS_SEL       (* (reg8 *) well_water_1_ac_current__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define well_water_1_ac_current_PRTDSI__DBL_SYNC_IN    (* (reg8 *) well_water_1_ac_current__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define well_water_1_ac_current_PRTDSI__OE_SEL0        (* (reg8 *) well_water_1_ac_current__PRTDSI__OE_SEL0) 
#define well_water_1_ac_current_PRTDSI__OE_SEL1        (* (reg8 *) well_water_1_ac_current__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define well_water_1_ac_current_PRTDSI__OUT_SEL0       (* (reg8 *) well_water_1_ac_current__PRTDSI__OUT_SEL0) 
#define well_water_1_ac_current_PRTDSI__OUT_SEL1       (* (reg8 *) well_water_1_ac_current__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define well_water_1_ac_current_PRTDSI__SYNC_OUT       (* (reg8 *) well_water_1_ac_current__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(well_water_1_ac_current__SIO_CFG)
    #define well_water_1_ac_current_SIO_HYST_EN        (* (reg8 *) well_water_1_ac_current__SIO_HYST_EN)
    #define well_water_1_ac_current_SIO_REG_HIFREQ     (* (reg8 *) well_water_1_ac_current__SIO_REG_HIFREQ)
    #define well_water_1_ac_current_SIO_CFG            (* (reg8 *) well_water_1_ac_current__SIO_CFG)
    #define well_water_1_ac_current_SIO_DIFF           (* (reg8 *) well_water_1_ac_current__SIO_DIFF)
#endif /* (well_water_1_ac_current__SIO_CFG) */

/* Interrupt Registers */
#if defined(well_water_1_ac_current__INTSTAT)
    #define well_water_1_ac_current_INTSTAT            (* (reg8 *) well_water_1_ac_current__INTSTAT)
    #define well_water_1_ac_current_SNAP               (* (reg8 *) well_water_1_ac_current__SNAP)
    
	#define well_water_1_ac_current_0_INTTYPE_REG 		(* (reg8 *) well_water_1_ac_current__0__INTTYPE)
#endif /* (well_water_1_ac_current__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_well_water_1_ac_current_H */


/* [] END OF FILE */
