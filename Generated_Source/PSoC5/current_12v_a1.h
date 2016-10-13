/*******************************************************************************
* File Name: current_12v_a1.h  
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

#if !defined(CY_PINS_current_12v_a1_H) /* Pins current_12v_a1_H */
#define CY_PINS_current_12v_a1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "current_12v_a1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 current_12v_a1__PORT == 15 && ((current_12v_a1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    current_12v_a1_Write(uint8 value);
void    current_12v_a1_SetDriveMode(uint8 mode);
uint8   current_12v_a1_ReadDataReg(void);
uint8   current_12v_a1_Read(void);
void    current_12v_a1_SetInterruptMode(uint16 position, uint16 mode);
uint8   current_12v_a1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the current_12v_a1_SetDriveMode() function.
     *  @{
     */
        #define current_12v_a1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define current_12v_a1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define current_12v_a1_DM_RES_UP          PIN_DM_RES_UP
        #define current_12v_a1_DM_RES_DWN         PIN_DM_RES_DWN
        #define current_12v_a1_DM_OD_LO           PIN_DM_OD_LO
        #define current_12v_a1_DM_OD_HI           PIN_DM_OD_HI
        #define current_12v_a1_DM_STRONG          PIN_DM_STRONG
        #define current_12v_a1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define current_12v_a1_MASK               current_12v_a1__MASK
#define current_12v_a1_SHIFT              current_12v_a1__SHIFT
#define current_12v_a1_WIDTH              1u

/* Interrupt constants */
#if defined(current_12v_a1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in current_12v_a1_SetInterruptMode() function.
     *  @{
     */
        #define current_12v_a1_INTR_NONE      (uint16)(0x0000u)
        #define current_12v_a1_INTR_RISING    (uint16)(0x0001u)
        #define current_12v_a1_INTR_FALLING   (uint16)(0x0002u)
        #define current_12v_a1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define current_12v_a1_INTR_MASK      (0x01u) 
#endif /* (current_12v_a1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define current_12v_a1_PS                     (* (reg8 *) current_12v_a1__PS)
/* Data Register */
#define current_12v_a1_DR                     (* (reg8 *) current_12v_a1__DR)
/* Port Number */
#define current_12v_a1_PRT_NUM                (* (reg8 *) current_12v_a1__PRT) 
/* Connect to Analog Globals */                                                  
#define current_12v_a1_AG                     (* (reg8 *) current_12v_a1__AG)                       
/* Analog MUX bux enable */
#define current_12v_a1_AMUX                   (* (reg8 *) current_12v_a1__AMUX) 
/* Bidirectional Enable */                                                        
#define current_12v_a1_BIE                    (* (reg8 *) current_12v_a1__BIE)
/* Bit-mask for Aliased Register Access */
#define current_12v_a1_BIT_MASK               (* (reg8 *) current_12v_a1__BIT_MASK)
/* Bypass Enable */
#define current_12v_a1_BYP                    (* (reg8 *) current_12v_a1__BYP)
/* Port wide control signals */                                                   
#define current_12v_a1_CTL                    (* (reg8 *) current_12v_a1__CTL)
/* Drive Modes */
#define current_12v_a1_DM0                    (* (reg8 *) current_12v_a1__DM0) 
#define current_12v_a1_DM1                    (* (reg8 *) current_12v_a1__DM1)
#define current_12v_a1_DM2                    (* (reg8 *) current_12v_a1__DM2) 
/* Input Buffer Disable Override */
#define current_12v_a1_INP_DIS                (* (reg8 *) current_12v_a1__INP_DIS)
/* LCD Common or Segment Drive */
#define current_12v_a1_LCD_COM_SEG            (* (reg8 *) current_12v_a1__LCD_COM_SEG)
/* Enable Segment LCD */
#define current_12v_a1_LCD_EN                 (* (reg8 *) current_12v_a1__LCD_EN)
/* Slew Rate Control */
#define current_12v_a1_SLW                    (* (reg8 *) current_12v_a1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define current_12v_a1_PRTDSI__CAPS_SEL       (* (reg8 *) current_12v_a1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define current_12v_a1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) current_12v_a1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define current_12v_a1_PRTDSI__OE_SEL0        (* (reg8 *) current_12v_a1__PRTDSI__OE_SEL0) 
#define current_12v_a1_PRTDSI__OE_SEL1        (* (reg8 *) current_12v_a1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define current_12v_a1_PRTDSI__OUT_SEL0       (* (reg8 *) current_12v_a1__PRTDSI__OUT_SEL0) 
#define current_12v_a1_PRTDSI__OUT_SEL1       (* (reg8 *) current_12v_a1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define current_12v_a1_PRTDSI__SYNC_OUT       (* (reg8 *) current_12v_a1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(current_12v_a1__SIO_CFG)
    #define current_12v_a1_SIO_HYST_EN        (* (reg8 *) current_12v_a1__SIO_HYST_EN)
    #define current_12v_a1_SIO_REG_HIFREQ     (* (reg8 *) current_12v_a1__SIO_REG_HIFREQ)
    #define current_12v_a1_SIO_CFG            (* (reg8 *) current_12v_a1__SIO_CFG)
    #define current_12v_a1_SIO_DIFF           (* (reg8 *) current_12v_a1__SIO_DIFF)
#endif /* (current_12v_a1__SIO_CFG) */

/* Interrupt Registers */
#if defined(current_12v_a1__INTSTAT)
    #define current_12v_a1_INTSTAT            (* (reg8 *) current_12v_a1__INTSTAT)
    #define current_12v_a1_SNAP               (* (reg8 *) current_12v_a1__SNAP)
    
	#define current_12v_a1_0_INTTYPE_REG 		(* (reg8 *) current_12v_a1__0__INTTYPE)
#endif /* (current_12v_a1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_current_12v_a1_H */


/* [] END OF FILE */
