/*******************************************************************************
* File Name: analog_14.h  
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

#if !defined(CY_PINS_analog_14_H) /* Pins analog_14_H */
#define CY_PINS_analog_14_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "analog_14_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 analog_14__PORT == 15 && ((analog_14__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    analog_14_Write(uint8 value);
void    analog_14_SetDriveMode(uint8 mode);
uint8   analog_14_ReadDataReg(void);
uint8   analog_14_Read(void);
void    analog_14_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_14_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the analog_14_SetDriveMode() function.
     *  @{
     */
        #define analog_14_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define analog_14_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define analog_14_DM_RES_UP          PIN_DM_RES_UP
        #define analog_14_DM_RES_DWN         PIN_DM_RES_DWN
        #define analog_14_DM_OD_LO           PIN_DM_OD_LO
        #define analog_14_DM_OD_HI           PIN_DM_OD_HI
        #define analog_14_DM_STRONG          PIN_DM_STRONG
        #define analog_14_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define analog_14_MASK               analog_14__MASK
#define analog_14_SHIFT              analog_14__SHIFT
#define analog_14_WIDTH              1u

/* Interrupt constants */
#if defined(analog_14__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_14_SetInterruptMode() function.
     *  @{
     */
        #define analog_14_INTR_NONE      (uint16)(0x0000u)
        #define analog_14_INTR_RISING    (uint16)(0x0001u)
        #define analog_14_INTR_FALLING   (uint16)(0x0002u)
        #define analog_14_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define analog_14_INTR_MASK      (0x01u) 
#endif /* (analog_14__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define analog_14_PS                     (* (reg8 *) analog_14__PS)
/* Data Register */
#define analog_14_DR                     (* (reg8 *) analog_14__DR)
/* Port Number */
#define analog_14_PRT_NUM                (* (reg8 *) analog_14__PRT) 
/* Connect to Analog Globals */                                                  
#define analog_14_AG                     (* (reg8 *) analog_14__AG)                       
/* Analog MUX bux enable */
#define analog_14_AMUX                   (* (reg8 *) analog_14__AMUX) 
/* Bidirectional Enable */                                                        
#define analog_14_BIE                    (* (reg8 *) analog_14__BIE)
/* Bit-mask for Aliased Register Access */
#define analog_14_BIT_MASK               (* (reg8 *) analog_14__BIT_MASK)
/* Bypass Enable */
#define analog_14_BYP                    (* (reg8 *) analog_14__BYP)
/* Port wide control signals */                                                   
#define analog_14_CTL                    (* (reg8 *) analog_14__CTL)
/* Drive Modes */
#define analog_14_DM0                    (* (reg8 *) analog_14__DM0) 
#define analog_14_DM1                    (* (reg8 *) analog_14__DM1)
#define analog_14_DM2                    (* (reg8 *) analog_14__DM2) 
/* Input Buffer Disable Override */
#define analog_14_INP_DIS                (* (reg8 *) analog_14__INP_DIS)
/* LCD Common or Segment Drive */
#define analog_14_LCD_COM_SEG            (* (reg8 *) analog_14__LCD_COM_SEG)
/* Enable Segment LCD */
#define analog_14_LCD_EN                 (* (reg8 *) analog_14__LCD_EN)
/* Slew Rate Control */
#define analog_14_SLW                    (* (reg8 *) analog_14__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define analog_14_PRTDSI__CAPS_SEL       (* (reg8 *) analog_14__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define analog_14_PRTDSI__DBL_SYNC_IN    (* (reg8 *) analog_14__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define analog_14_PRTDSI__OE_SEL0        (* (reg8 *) analog_14__PRTDSI__OE_SEL0) 
#define analog_14_PRTDSI__OE_SEL1        (* (reg8 *) analog_14__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define analog_14_PRTDSI__OUT_SEL0       (* (reg8 *) analog_14__PRTDSI__OUT_SEL0) 
#define analog_14_PRTDSI__OUT_SEL1       (* (reg8 *) analog_14__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define analog_14_PRTDSI__SYNC_OUT       (* (reg8 *) analog_14__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(analog_14__SIO_CFG)
    #define analog_14_SIO_HYST_EN        (* (reg8 *) analog_14__SIO_HYST_EN)
    #define analog_14_SIO_REG_HIFREQ     (* (reg8 *) analog_14__SIO_REG_HIFREQ)
    #define analog_14_SIO_CFG            (* (reg8 *) analog_14__SIO_CFG)
    #define analog_14_SIO_DIFF           (* (reg8 *) analog_14__SIO_DIFF)
#endif /* (analog_14__SIO_CFG) */

/* Interrupt Registers */
#if defined(analog_14__INTSTAT)
    #define analog_14_INTSTAT            (* (reg8 *) analog_14__INTSTAT)
    #define analog_14_SNAP               (* (reg8 *) analog_14__SNAP)
    
	#define analog_14_0_INTTYPE_REG 		(* (reg8 *) analog_14__0__INTTYPE)
#endif /* (analog_14__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_analog_14_H */


/* [] END OF FILE */
