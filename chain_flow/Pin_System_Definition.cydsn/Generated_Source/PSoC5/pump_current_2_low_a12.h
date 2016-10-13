/*******************************************************************************
* File Name: pump_current_2_low_a12.h  
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

#if !defined(CY_PINS_pump_current_2_low_a12_H) /* Pins pump_current_2_low_a12_H */
#define CY_PINS_pump_current_2_low_a12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pump_current_2_low_a12_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pump_current_2_low_a12__PORT == 15 && ((pump_current_2_low_a12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pump_current_2_low_a12_Write(uint8 value);
void    pump_current_2_low_a12_SetDriveMode(uint8 mode);
uint8   pump_current_2_low_a12_ReadDataReg(void);
uint8   pump_current_2_low_a12_Read(void);
void    pump_current_2_low_a12_SetInterruptMode(uint16 position, uint16 mode);
uint8   pump_current_2_low_a12_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pump_current_2_low_a12_SetDriveMode() function.
     *  @{
     */
        #define pump_current_2_low_a12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pump_current_2_low_a12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pump_current_2_low_a12_DM_RES_UP          PIN_DM_RES_UP
        #define pump_current_2_low_a12_DM_RES_DWN         PIN_DM_RES_DWN
        #define pump_current_2_low_a12_DM_OD_LO           PIN_DM_OD_LO
        #define pump_current_2_low_a12_DM_OD_HI           PIN_DM_OD_HI
        #define pump_current_2_low_a12_DM_STRONG          PIN_DM_STRONG
        #define pump_current_2_low_a12_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pump_current_2_low_a12_MASK               pump_current_2_low_a12__MASK
#define pump_current_2_low_a12_SHIFT              pump_current_2_low_a12__SHIFT
#define pump_current_2_low_a12_WIDTH              1u

/* Interrupt constants */
#if defined(pump_current_2_low_a12__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pump_current_2_low_a12_SetInterruptMode() function.
     *  @{
     */
        #define pump_current_2_low_a12_INTR_NONE      (uint16)(0x0000u)
        #define pump_current_2_low_a12_INTR_RISING    (uint16)(0x0001u)
        #define pump_current_2_low_a12_INTR_FALLING   (uint16)(0x0002u)
        #define pump_current_2_low_a12_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pump_current_2_low_a12_INTR_MASK      (0x01u) 
#endif /* (pump_current_2_low_a12__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pump_current_2_low_a12_PS                     (* (reg8 *) pump_current_2_low_a12__PS)
/* Data Register */
#define pump_current_2_low_a12_DR                     (* (reg8 *) pump_current_2_low_a12__DR)
/* Port Number */
#define pump_current_2_low_a12_PRT_NUM                (* (reg8 *) pump_current_2_low_a12__PRT) 
/* Connect to Analog Globals */                                                  
#define pump_current_2_low_a12_AG                     (* (reg8 *) pump_current_2_low_a12__AG)                       
/* Analog MUX bux enable */
#define pump_current_2_low_a12_AMUX                   (* (reg8 *) pump_current_2_low_a12__AMUX) 
/* Bidirectional Enable */                                                        
#define pump_current_2_low_a12_BIE                    (* (reg8 *) pump_current_2_low_a12__BIE)
/* Bit-mask for Aliased Register Access */
#define pump_current_2_low_a12_BIT_MASK               (* (reg8 *) pump_current_2_low_a12__BIT_MASK)
/* Bypass Enable */
#define pump_current_2_low_a12_BYP                    (* (reg8 *) pump_current_2_low_a12__BYP)
/* Port wide control signals */                                                   
#define pump_current_2_low_a12_CTL                    (* (reg8 *) pump_current_2_low_a12__CTL)
/* Drive Modes */
#define pump_current_2_low_a12_DM0                    (* (reg8 *) pump_current_2_low_a12__DM0) 
#define pump_current_2_low_a12_DM1                    (* (reg8 *) pump_current_2_low_a12__DM1)
#define pump_current_2_low_a12_DM2                    (* (reg8 *) pump_current_2_low_a12__DM2) 
/* Input Buffer Disable Override */
#define pump_current_2_low_a12_INP_DIS                (* (reg8 *) pump_current_2_low_a12__INP_DIS)
/* LCD Common or Segment Drive */
#define pump_current_2_low_a12_LCD_COM_SEG            (* (reg8 *) pump_current_2_low_a12__LCD_COM_SEG)
/* Enable Segment LCD */
#define pump_current_2_low_a12_LCD_EN                 (* (reg8 *) pump_current_2_low_a12__LCD_EN)
/* Slew Rate Control */
#define pump_current_2_low_a12_SLW                    (* (reg8 *) pump_current_2_low_a12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pump_current_2_low_a12_PRTDSI__CAPS_SEL       (* (reg8 *) pump_current_2_low_a12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pump_current_2_low_a12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pump_current_2_low_a12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pump_current_2_low_a12_PRTDSI__OE_SEL0        (* (reg8 *) pump_current_2_low_a12__PRTDSI__OE_SEL0) 
#define pump_current_2_low_a12_PRTDSI__OE_SEL1        (* (reg8 *) pump_current_2_low_a12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pump_current_2_low_a12_PRTDSI__OUT_SEL0       (* (reg8 *) pump_current_2_low_a12__PRTDSI__OUT_SEL0) 
#define pump_current_2_low_a12_PRTDSI__OUT_SEL1       (* (reg8 *) pump_current_2_low_a12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pump_current_2_low_a12_PRTDSI__SYNC_OUT       (* (reg8 *) pump_current_2_low_a12__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pump_current_2_low_a12__SIO_CFG)
    #define pump_current_2_low_a12_SIO_HYST_EN        (* (reg8 *) pump_current_2_low_a12__SIO_HYST_EN)
    #define pump_current_2_low_a12_SIO_REG_HIFREQ     (* (reg8 *) pump_current_2_low_a12__SIO_REG_HIFREQ)
    #define pump_current_2_low_a12_SIO_CFG            (* (reg8 *) pump_current_2_low_a12__SIO_CFG)
    #define pump_current_2_low_a12_SIO_DIFF           (* (reg8 *) pump_current_2_low_a12__SIO_DIFF)
#endif /* (pump_current_2_low_a12__SIO_CFG) */

/* Interrupt Registers */
#if defined(pump_current_2_low_a12__INTSTAT)
    #define pump_current_2_low_a12_INTSTAT            (* (reg8 *) pump_current_2_low_a12__INTSTAT)
    #define pump_current_2_low_a12_SNAP               (* (reg8 *) pump_current_2_low_a12__SNAP)
    
	#define pump_current_2_low_a12_0_INTTYPE_REG 		(* (reg8 *) pump_current_2_low_a12__0__INTTYPE)
#endif /* (pump_current_2_low_a12__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pump_current_2_low_a12_H */


/* [] END OF FILE */
