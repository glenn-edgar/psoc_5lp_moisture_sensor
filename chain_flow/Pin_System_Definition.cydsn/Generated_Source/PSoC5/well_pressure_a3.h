/*******************************************************************************
* File Name: well_pressure_a3.h  
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

#if !defined(CY_PINS_well_pressure_a3_H) /* Pins well_pressure_a3_H */
#define CY_PINS_well_pressure_a3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "well_pressure_a3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 well_pressure_a3__PORT == 15 && ((well_pressure_a3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    well_pressure_a3_Write(uint8 value);
void    well_pressure_a3_SetDriveMode(uint8 mode);
uint8   well_pressure_a3_ReadDataReg(void);
uint8   well_pressure_a3_Read(void);
void    well_pressure_a3_SetInterruptMode(uint16 position, uint16 mode);
uint8   well_pressure_a3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the well_pressure_a3_SetDriveMode() function.
     *  @{
     */
        #define well_pressure_a3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define well_pressure_a3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define well_pressure_a3_DM_RES_UP          PIN_DM_RES_UP
        #define well_pressure_a3_DM_RES_DWN         PIN_DM_RES_DWN
        #define well_pressure_a3_DM_OD_LO           PIN_DM_OD_LO
        #define well_pressure_a3_DM_OD_HI           PIN_DM_OD_HI
        #define well_pressure_a3_DM_STRONG          PIN_DM_STRONG
        #define well_pressure_a3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define well_pressure_a3_MASK               well_pressure_a3__MASK
#define well_pressure_a3_SHIFT              well_pressure_a3__SHIFT
#define well_pressure_a3_WIDTH              1u

/* Interrupt constants */
#if defined(well_pressure_a3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in well_pressure_a3_SetInterruptMode() function.
     *  @{
     */
        #define well_pressure_a3_INTR_NONE      (uint16)(0x0000u)
        #define well_pressure_a3_INTR_RISING    (uint16)(0x0001u)
        #define well_pressure_a3_INTR_FALLING   (uint16)(0x0002u)
        #define well_pressure_a3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define well_pressure_a3_INTR_MASK      (0x01u) 
#endif /* (well_pressure_a3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define well_pressure_a3_PS                     (* (reg8 *) well_pressure_a3__PS)
/* Data Register */
#define well_pressure_a3_DR                     (* (reg8 *) well_pressure_a3__DR)
/* Port Number */
#define well_pressure_a3_PRT_NUM                (* (reg8 *) well_pressure_a3__PRT) 
/* Connect to Analog Globals */                                                  
#define well_pressure_a3_AG                     (* (reg8 *) well_pressure_a3__AG)                       
/* Analog MUX bux enable */
#define well_pressure_a3_AMUX                   (* (reg8 *) well_pressure_a3__AMUX) 
/* Bidirectional Enable */                                                        
#define well_pressure_a3_BIE                    (* (reg8 *) well_pressure_a3__BIE)
/* Bit-mask for Aliased Register Access */
#define well_pressure_a3_BIT_MASK               (* (reg8 *) well_pressure_a3__BIT_MASK)
/* Bypass Enable */
#define well_pressure_a3_BYP                    (* (reg8 *) well_pressure_a3__BYP)
/* Port wide control signals */                                                   
#define well_pressure_a3_CTL                    (* (reg8 *) well_pressure_a3__CTL)
/* Drive Modes */
#define well_pressure_a3_DM0                    (* (reg8 *) well_pressure_a3__DM0) 
#define well_pressure_a3_DM1                    (* (reg8 *) well_pressure_a3__DM1)
#define well_pressure_a3_DM2                    (* (reg8 *) well_pressure_a3__DM2) 
/* Input Buffer Disable Override */
#define well_pressure_a3_INP_DIS                (* (reg8 *) well_pressure_a3__INP_DIS)
/* LCD Common or Segment Drive */
#define well_pressure_a3_LCD_COM_SEG            (* (reg8 *) well_pressure_a3__LCD_COM_SEG)
/* Enable Segment LCD */
#define well_pressure_a3_LCD_EN                 (* (reg8 *) well_pressure_a3__LCD_EN)
/* Slew Rate Control */
#define well_pressure_a3_SLW                    (* (reg8 *) well_pressure_a3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define well_pressure_a3_PRTDSI__CAPS_SEL       (* (reg8 *) well_pressure_a3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define well_pressure_a3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) well_pressure_a3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define well_pressure_a3_PRTDSI__OE_SEL0        (* (reg8 *) well_pressure_a3__PRTDSI__OE_SEL0) 
#define well_pressure_a3_PRTDSI__OE_SEL1        (* (reg8 *) well_pressure_a3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define well_pressure_a3_PRTDSI__OUT_SEL0       (* (reg8 *) well_pressure_a3__PRTDSI__OUT_SEL0) 
#define well_pressure_a3_PRTDSI__OUT_SEL1       (* (reg8 *) well_pressure_a3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define well_pressure_a3_PRTDSI__SYNC_OUT       (* (reg8 *) well_pressure_a3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(well_pressure_a3__SIO_CFG)
    #define well_pressure_a3_SIO_HYST_EN        (* (reg8 *) well_pressure_a3__SIO_HYST_EN)
    #define well_pressure_a3_SIO_REG_HIFREQ     (* (reg8 *) well_pressure_a3__SIO_REG_HIFREQ)
    #define well_pressure_a3_SIO_CFG            (* (reg8 *) well_pressure_a3__SIO_CFG)
    #define well_pressure_a3_SIO_DIFF           (* (reg8 *) well_pressure_a3__SIO_DIFF)
#endif /* (well_pressure_a3__SIO_CFG) */

/* Interrupt Registers */
#if defined(well_pressure_a3__INTSTAT)
    #define well_pressure_a3_INTSTAT            (* (reg8 *) well_pressure_a3__INTSTAT)
    #define well_pressure_a3_SNAP               (* (reg8 *) well_pressure_a3__SNAP)
    
	#define well_pressure_a3_0_INTTYPE_REG 		(* (reg8 *) well_pressure_a3__0__INTTYPE)
#endif /* (well_pressure_a3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_well_pressure_a3_H */


/* [] END OF FILE */
