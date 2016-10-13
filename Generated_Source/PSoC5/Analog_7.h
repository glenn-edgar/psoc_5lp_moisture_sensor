/*******************************************************************************
* File Name: analog_7.h  
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

#if !defined(CY_PINS_analog_7_H) /* Pins analog_7_H */
#define CY_PINS_analog_7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "analog_7_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 analog_7__PORT == 15 && ((analog_7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    analog_7_Write(uint8 value);
void    analog_7_SetDriveMode(uint8 mode);
uint8   analog_7_ReadDataReg(void);
uint8   analog_7_Read(void);
void    analog_7_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_7_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the analog_7_SetDriveMode() function.
     *  @{
     */
        #define analog_7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define analog_7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define analog_7_DM_RES_UP          PIN_DM_RES_UP
        #define analog_7_DM_RES_DWN         PIN_DM_RES_DWN
        #define analog_7_DM_OD_LO           PIN_DM_OD_LO
        #define analog_7_DM_OD_HI           PIN_DM_OD_HI
        #define analog_7_DM_STRONG          PIN_DM_STRONG
        #define analog_7_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define analog_7_MASK               analog_7__MASK
#define analog_7_SHIFT              analog_7__SHIFT
#define analog_7_WIDTH              1u

/* Interrupt constants */
#if defined(analog_7__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_7_SetInterruptMode() function.
     *  @{
     */
        #define analog_7_INTR_NONE      (uint16)(0x0000u)
        #define analog_7_INTR_RISING    (uint16)(0x0001u)
        #define analog_7_INTR_FALLING   (uint16)(0x0002u)
        #define analog_7_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define analog_7_INTR_MASK      (0x01u) 
#endif /* (analog_7__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define analog_7_PS                     (* (reg8 *) analog_7__PS)
/* Data Register */
#define analog_7_DR                     (* (reg8 *) analog_7__DR)
/* Port Number */
#define analog_7_PRT_NUM                (* (reg8 *) analog_7__PRT) 
/* Connect to Analog Globals */                                                  
#define analog_7_AG                     (* (reg8 *) analog_7__AG)                       
/* Analog MUX bux enable */
#define analog_7_AMUX                   (* (reg8 *) analog_7__AMUX) 
/* Bidirectional Enable */                                                        
#define analog_7_BIE                    (* (reg8 *) analog_7__BIE)
/* Bit-mask for Aliased Register Access */
#define analog_7_BIT_MASK               (* (reg8 *) analog_7__BIT_MASK)
/* Bypass Enable */
#define analog_7_BYP                    (* (reg8 *) analog_7__BYP)
/* Port wide control signals */                                                   
#define analog_7_CTL                    (* (reg8 *) analog_7__CTL)
/* Drive Modes */
#define analog_7_DM0                    (* (reg8 *) analog_7__DM0) 
#define analog_7_DM1                    (* (reg8 *) analog_7__DM1)
#define analog_7_DM2                    (* (reg8 *) analog_7__DM2) 
/* Input Buffer Disable Override */
#define analog_7_INP_DIS                (* (reg8 *) analog_7__INP_DIS)
/* LCD Common or Segment Drive */
#define analog_7_LCD_COM_SEG            (* (reg8 *) analog_7__LCD_COM_SEG)
/* Enable Segment LCD */
#define analog_7_LCD_EN                 (* (reg8 *) analog_7__LCD_EN)
/* Slew Rate Control */
#define analog_7_SLW                    (* (reg8 *) analog_7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define analog_7_PRTDSI__CAPS_SEL       (* (reg8 *) analog_7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define analog_7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) analog_7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define analog_7_PRTDSI__OE_SEL0        (* (reg8 *) analog_7__PRTDSI__OE_SEL0) 
#define analog_7_PRTDSI__OE_SEL1        (* (reg8 *) analog_7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define analog_7_PRTDSI__OUT_SEL0       (* (reg8 *) analog_7__PRTDSI__OUT_SEL0) 
#define analog_7_PRTDSI__OUT_SEL1       (* (reg8 *) analog_7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define analog_7_PRTDSI__SYNC_OUT       (* (reg8 *) analog_7__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(analog_7__SIO_CFG)
    #define analog_7_SIO_HYST_EN        (* (reg8 *) analog_7__SIO_HYST_EN)
    #define analog_7_SIO_REG_HIFREQ     (* (reg8 *) analog_7__SIO_REG_HIFREQ)
    #define analog_7_SIO_CFG            (* (reg8 *) analog_7__SIO_CFG)
    #define analog_7_SIO_DIFF           (* (reg8 *) analog_7__SIO_DIFF)
#endif /* (analog_7__SIO_CFG) */

/* Interrupt Registers */
#if defined(analog_7__INTSTAT)
    #define analog_7_INTSTAT            (* (reg8 *) analog_7__INTSTAT)
    #define analog_7_SNAP               (* (reg8 *) analog_7__SNAP)
    
	#define analog_7_0_INTTYPE_REG 		(* (reg8 *) analog_7__0__INTTYPE)
#endif /* (analog_7__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_analog_7_H */


/* [] END OF FILE */
