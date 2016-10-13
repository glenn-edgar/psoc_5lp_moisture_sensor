/*******************************************************************************
* File Name: valve_current_12v_plus.h  
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

#if !defined(CY_PINS_valve_current_12v_plus_H) /* Pins valve_current_12v_plus_H */
#define CY_PINS_valve_current_12v_plus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "valve_current_12v_plus_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 valve_current_12v_plus__PORT == 15 && ((valve_current_12v_plus__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    valve_current_12v_plus_Write(uint8 value);
void    valve_current_12v_plus_SetDriveMode(uint8 mode);
uint8   valve_current_12v_plus_ReadDataReg(void);
uint8   valve_current_12v_plus_Read(void);
void    valve_current_12v_plus_SetInterruptMode(uint16 position, uint16 mode);
uint8   valve_current_12v_plus_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the valve_current_12v_plus_SetDriveMode() function.
     *  @{
     */
        #define valve_current_12v_plus_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define valve_current_12v_plus_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define valve_current_12v_plus_DM_RES_UP          PIN_DM_RES_UP
        #define valve_current_12v_plus_DM_RES_DWN         PIN_DM_RES_DWN
        #define valve_current_12v_plus_DM_OD_LO           PIN_DM_OD_LO
        #define valve_current_12v_plus_DM_OD_HI           PIN_DM_OD_HI
        #define valve_current_12v_plus_DM_STRONG          PIN_DM_STRONG
        #define valve_current_12v_plus_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define valve_current_12v_plus_MASK               valve_current_12v_plus__MASK
#define valve_current_12v_plus_SHIFT              valve_current_12v_plus__SHIFT
#define valve_current_12v_plus_WIDTH              1u

/* Interrupt constants */
#if defined(valve_current_12v_plus__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in valve_current_12v_plus_SetInterruptMode() function.
     *  @{
     */
        #define valve_current_12v_plus_INTR_NONE      (uint16)(0x0000u)
        #define valve_current_12v_plus_INTR_RISING    (uint16)(0x0001u)
        #define valve_current_12v_plus_INTR_FALLING   (uint16)(0x0002u)
        #define valve_current_12v_plus_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define valve_current_12v_plus_INTR_MASK      (0x01u) 
#endif /* (valve_current_12v_plus__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define valve_current_12v_plus_PS                     (* (reg8 *) valve_current_12v_plus__PS)
/* Data Register */
#define valve_current_12v_plus_DR                     (* (reg8 *) valve_current_12v_plus__DR)
/* Port Number */
#define valve_current_12v_plus_PRT_NUM                (* (reg8 *) valve_current_12v_plus__PRT) 
/* Connect to Analog Globals */                                                  
#define valve_current_12v_plus_AG                     (* (reg8 *) valve_current_12v_plus__AG)                       
/* Analog MUX bux enable */
#define valve_current_12v_plus_AMUX                   (* (reg8 *) valve_current_12v_plus__AMUX) 
/* Bidirectional Enable */                                                        
#define valve_current_12v_plus_BIE                    (* (reg8 *) valve_current_12v_plus__BIE)
/* Bit-mask for Aliased Register Access */
#define valve_current_12v_plus_BIT_MASK               (* (reg8 *) valve_current_12v_plus__BIT_MASK)
/* Bypass Enable */
#define valve_current_12v_plus_BYP                    (* (reg8 *) valve_current_12v_plus__BYP)
/* Port wide control signals */                                                   
#define valve_current_12v_plus_CTL                    (* (reg8 *) valve_current_12v_plus__CTL)
/* Drive Modes */
#define valve_current_12v_plus_DM0                    (* (reg8 *) valve_current_12v_plus__DM0) 
#define valve_current_12v_plus_DM1                    (* (reg8 *) valve_current_12v_plus__DM1)
#define valve_current_12v_plus_DM2                    (* (reg8 *) valve_current_12v_plus__DM2) 
/* Input Buffer Disable Override */
#define valve_current_12v_plus_INP_DIS                (* (reg8 *) valve_current_12v_plus__INP_DIS)
/* LCD Common or Segment Drive */
#define valve_current_12v_plus_LCD_COM_SEG            (* (reg8 *) valve_current_12v_plus__LCD_COM_SEG)
/* Enable Segment LCD */
#define valve_current_12v_plus_LCD_EN                 (* (reg8 *) valve_current_12v_plus__LCD_EN)
/* Slew Rate Control */
#define valve_current_12v_plus_SLW                    (* (reg8 *) valve_current_12v_plus__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define valve_current_12v_plus_PRTDSI__CAPS_SEL       (* (reg8 *) valve_current_12v_plus__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define valve_current_12v_plus_PRTDSI__DBL_SYNC_IN    (* (reg8 *) valve_current_12v_plus__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define valve_current_12v_plus_PRTDSI__OE_SEL0        (* (reg8 *) valve_current_12v_plus__PRTDSI__OE_SEL0) 
#define valve_current_12v_plus_PRTDSI__OE_SEL1        (* (reg8 *) valve_current_12v_plus__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define valve_current_12v_plus_PRTDSI__OUT_SEL0       (* (reg8 *) valve_current_12v_plus__PRTDSI__OUT_SEL0) 
#define valve_current_12v_plus_PRTDSI__OUT_SEL1       (* (reg8 *) valve_current_12v_plus__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define valve_current_12v_plus_PRTDSI__SYNC_OUT       (* (reg8 *) valve_current_12v_plus__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(valve_current_12v_plus__SIO_CFG)
    #define valve_current_12v_plus_SIO_HYST_EN        (* (reg8 *) valve_current_12v_plus__SIO_HYST_EN)
    #define valve_current_12v_plus_SIO_REG_HIFREQ     (* (reg8 *) valve_current_12v_plus__SIO_REG_HIFREQ)
    #define valve_current_12v_plus_SIO_CFG            (* (reg8 *) valve_current_12v_plus__SIO_CFG)
    #define valve_current_12v_plus_SIO_DIFF           (* (reg8 *) valve_current_12v_plus__SIO_DIFF)
#endif /* (valve_current_12v_plus__SIO_CFG) */

/* Interrupt Registers */
#if defined(valve_current_12v_plus__INTSTAT)
    #define valve_current_12v_plus_INTSTAT            (* (reg8 *) valve_current_12v_plus__INTSTAT)
    #define valve_current_12v_plus_SNAP               (* (reg8 *) valve_current_12v_plus__SNAP)
    
	#define valve_current_12v_plus_0_INTTYPE_REG 		(* (reg8 *) valve_current_12v_plus__0__INTTYPE)
#endif /* (valve_current_12v_plus__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_valve_current_12v_plus_H */


/* [] END OF FILE */
