/*******************************************************************************
* File Name: pump_current_2_hign_a11.h  
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

#if !defined(CY_PINS_pump_current_2_hign_a11_H) /* Pins pump_current_2_hign_a11_H */
#define CY_PINS_pump_current_2_hign_a11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pump_current_2_hign_a11_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pump_current_2_hign_a11__PORT == 15 && ((pump_current_2_hign_a11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pump_current_2_hign_a11_Write(uint8 value);
void    pump_current_2_hign_a11_SetDriveMode(uint8 mode);
uint8   pump_current_2_hign_a11_ReadDataReg(void);
uint8   pump_current_2_hign_a11_Read(void);
void    pump_current_2_hign_a11_SetInterruptMode(uint16 position, uint16 mode);
uint8   pump_current_2_hign_a11_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pump_current_2_hign_a11_SetDriveMode() function.
     *  @{
     */
        #define pump_current_2_hign_a11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pump_current_2_hign_a11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pump_current_2_hign_a11_DM_RES_UP          PIN_DM_RES_UP
        #define pump_current_2_hign_a11_DM_RES_DWN         PIN_DM_RES_DWN
        #define pump_current_2_hign_a11_DM_OD_LO           PIN_DM_OD_LO
        #define pump_current_2_hign_a11_DM_OD_HI           PIN_DM_OD_HI
        #define pump_current_2_hign_a11_DM_STRONG          PIN_DM_STRONG
        #define pump_current_2_hign_a11_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pump_current_2_hign_a11_MASK               pump_current_2_hign_a11__MASK
#define pump_current_2_hign_a11_SHIFT              pump_current_2_hign_a11__SHIFT
#define pump_current_2_hign_a11_WIDTH              1u

/* Interrupt constants */
#if defined(pump_current_2_hign_a11__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pump_current_2_hign_a11_SetInterruptMode() function.
     *  @{
     */
        #define pump_current_2_hign_a11_INTR_NONE      (uint16)(0x0000u)
        #define pump_current_2_hign_a11_INTR_RISING    (uint16)(0x0001u)
        #define pump_current_2_hign_a11_INTR_FALLING   (uint16)(0x0002u)
        #define pump_current_2_hign_a11_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pump_current_2_hign_a11_INTR_MASK      (0x01u) 
#endif /* (pump_current_2_hign_a11__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pump_current_2_hign_a11_PS                     (* (reg8 *) pump_current_2_hign_a11__PS)
/* Data Register */
#define pump_current_2_hign_a11_DR                     (* (reg8 *) pump_current_2_hign_a11__DR)
/* Port Number */
#define pump_current_2_hign_a11_PRT_NUM                (* (reg8 *) pump_current_2_hign_a11__PRT) 
/* Connect to Analog Globals */                                                  
#define pump_current_2_hign_a11_AG                     (* (reg8 *) pump_current_2_hign_a11__AG)                       
/* Analog MUX bux enable */
#define pump_current_2_hign_a11_AMUX                   (* (reg8 *) pump_current_2_hign_a11__AMUX) 
/* Bidirectional Enable */                                                        
#define pump_current_2_hign_a11_BIE                    (* (reg8 *) pump_current_2_hign_a11__BIE)
/* Bit-mask for Aliased Register Access */
#define pump_current_2_hign_a11_BIT_MASK               (* (reg8 *) pump_current_2_hign_a11__BIT_MASK)
/* Bypass Enable */
#define pump_current_2_hign_a11_BYP                    (* (reg8 *) pump_current_2_hign_a11__BYP)
/* Port wide control signals */                                                   
#define pump_current_2_hign_a11_CTL                    (* (reg8 *) pump_current_2_hign_a11__CTL)
/* Drive Modes */
#define pump_current_2_hign_a11_DM0                    (* (reg8 *) pump_current_2_hign_a11__DM0) 
#define pump_current_2_hign_a11_DM1                    (* (reg8 *) pump_current_2_hign_a11__DM1)
#define pump_current_2_hign_a11_DM2                    (* (reg8 *) pump_current_2_hign_a11__DM2) 
/* Input Buffer Disable Override */
#define pump_current_2_hign_a11_INP_DIS                (* (reg8 *) pump_current_2_hign_a11__INP_DIS)
/* LCD Common or Segment Drive */
#define pump_current_2_hign_a11_LCD_COM_SEG            (* (reg8 *) pump_current_2_hign_a11__LCD_COM_SEG)
/* Enable Segment LCD */
#define pump_current_2_hign_a11_LCD_EN                 (* (reg8 *) pump_current_2_hign_a11__LCD_EN)
/* Slew Rate Control */
#define pump_current_2_hign_a11_SLW                    (* (reg8 *) pump_current_2_hign_a11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pump_current_2_hign_a11_PRTDSI__CAPS_SEL       (* (reg8 *) pump_current_2_hign_a11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pump_current_2_hign_a11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pump_current_2_hign_a11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pump_current_2_hign_a11_PRTDSI__OE_SEL0        (* (reg8 *) pump_current_2_hign_a11__PRTDSI__OE_SEL0) 
#define pump_current_2_hign_a11_PRTDSI__OE_SEL1        (* (reg8 *) pump_current_2_hign_a11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pump_current_2_hign_a11_PRTDSI__OUT_SEL0       (* (reg8 *) pump_current_2_hign_a11__PRTDSI__OUT_SEL0) 
#define pump_current_2_hign_a11_PRTDSI__OUT_SEL1       (* (reg8 *) pump_current_2_hign_a11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pump_current_2_hign_a11_PRTDSI__SYNC_OUT       (* (reg8 *) pump_current_2_hign_a11__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pump_current_2_hign_a11__SIO_CFG)
    #define pump_current_2_hign_a11_SIO_HYST_EN        (* (reg8 *) pump_current_2_hign_a11__SIO_HYST_EN)
    #define pump_current_2_hign_a11_SIO_REG_HIFREQ     (* (reg8 *) pump_current_2_hign_a11__SIO_REG_HIFREQ)
    #define pump_current_2_hign_a11_SIO_CFG            (* (reg8 *) pump_current_2_hign_a11__SIO_CFG)
    #define pump_current_2_hign_a11_SIO_DIFF           (* (reg8 *) pump_current_2_hign_a11__SIO_DIFF)
#endif /* (pump_current_2_hign_a11__SIO_CFG) */

/* Interrupt Registers */
#if defined(pump_current_2_hign_a11__INTSTAT)
    #define pump_current_2_hign_a11_INTSTAT            (* (reg8 *) pump_current_2_hign_a11__INTSTAT)
    #define pump_current_2_hign_a11_SNAP               (* (reg8 *) pump_current_2_hign_a11__SNAP)
    
	#define pump_current_2_hign_a11_0_INTTYPE_REG 		(* (reg8 *) pump_current_2_hign_a11__0__INTTYPE)
#endif /* (pump_current_2_hign_a11__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pump_current_2_hign_a11_H */


/* [] END OF FILE */
