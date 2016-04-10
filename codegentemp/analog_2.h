/*******************************************************************************
* File Name: analog_2.h  
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

#if !defined(CY_PINS_analog_2_H) /* Pins analog_2_H */
#define CY_PINS_analog_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "analog_2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 analog_2__PORT == 15 && ((analog_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    analog_2_Write(uint8 value);
void    analog_2_SetDriveMode(uint8 mode);
uint8   analog_2_ReadDataReg(void);
uint8   analog_2_Read(void);
void    analog_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the analog_2_SetDriveMode() function.
     *  @{
     */
        #define analog_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define analog_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define analog_2_DM_RES_UP          PIN_DM_RES_UP
        #define analog_2_DM_RES_DWN         PIN_DM_RES_DWN
        #define analog_2_DM_OD_LO           PIN_DM_OD_LO
        #define analog_2_DM_OD_HI           PIN_DM_OD_HI
        #define analog_2_DM_STRONG          PIN_DM_STRONG
        #define analog_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define analog_2_MASK               analog_2__MASK
#define analog_2_SHIFT              analog_2__SHIFT
#define analog_2_WIDTH              1u

/* Interrupt constants */
#if defined(analog_2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_2_SetInterruptMode() function.
     *  @{
     */
        #define analog_2_INTR_NONE      (uint16)(0x0000u)
        #define analog_2_INTR_RISING    (uint16)(0x0001u)
        #define analog_2_INTR_FALLING   (uint16)(0x0002u)
        #define analog_2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define analog_2_INTR_MASK      (0x01u) 
#endif /* (analog_2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define analog_2_PS                     (* (reg8 *) analog_2__PS)
/* Data Register */
#define analog_2_DR                     (* (reg8 *) analog_2__DR)
/* Port Number */
#define analog_2_PRT_NUM                (* (reg8 *) analog_2__PRT) 
/* Connect to Analog Globals */                                                  
#define analog_2_AG                     (* (reg8 *) analog_2__AG)                       
/* Analog MUX bux enable */
#define analog_2_AMUX                   (* (reg8 *) analog_2__AMUX) 
/* Bidirectional Enable */                                                        
#define analog_2_BIE                    (* (reg8 *) analog_2__BIE)
/* Bit-mask for Aliased Register Access */
#define analog_2_BIT_MASK               (* (reg8 *) analog_2__BIT_MASK)
/* Bypass Enable */
#define analog_2_BYP                    (* (reg8 *) analog_2__BYP)
/* Port wide control signals */                                                   
#define analog_2_CTL                    (* (reg8 *) analog_2__CTL)
/* Drive Modes */
#define analog_2_DM0                    (* (reg8 *) analog_2__DM0) 
#define analog_2_DM1                    (* (reg8 *) analog_2__DM1)
#define analog_2_DM2                    (* (reg8 *) analog_2__DM2) 
/* Input Buffer Disable Override */
#define analog_2_INP_DIS                (* (reg8 *) analog_2__INP_DIS)
/* LCD Common or Segment Drive */
#define analog_2_LCD_COM_SEG            (* (reg8 *) analog_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define analog_2_LCD_EN                 (* (reg8 *) analog_2__LCD_EN)
/* Slew Rate Control */
#define analog_2_SLW                    (* (reg8 *) analog_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define analog_2_PRTDSI__CAPS_SEL       (* (reg8 *) analog_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define analog_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) analog_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define analog_2_PRTDSI__OE_SEL0        (* (reg8 *) analog_2__PRTDSI__OE_SEL0) 
#define analog_2_PRTDSI__OE_SEL1        (* (reg8 *) analog_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define analog_2_PRTDSI__OUT_SEL0       (* (reg8 *) analog_2__PRTDSI__OUT_SEL0) 
#define analog_2_PRTDSI__OUT_SEL1       (* (reg8 *) analog_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define analog_2_PRTDSI__SYNC_OUT       (* (reg8 *) analog_2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(analog_2__SIO_CFG)
    #define analog_2_SIO_HYST_EN        (* (reg8 *) analog_2__SIO_HYST_EN)
    #define analog_2_SIO_REG_HIFREQ     (* (reg8 *) analog_2__SIO_REG_HIFREQ)
    #define analog_2_SIO_CFG            (* (reg8 *) analog_2__SIO_CFG)
    #define analog_2_SIO_DIFF           (* (reg8 *) analog_2__SIO_DIFF)
#endif /* (analog_2__SIO_CFG) */

/* Interrupt Registers */
#if defined(analog_2__INTSTAT)
    #define analog_2_INTSTAT            (* (reg8 *) analog_2__INTSTAT)
    #define analog_2_SNAP               (* (reg8 *) analog_2__SNAP)
    
	#define analog_2_0_INTTYPE_REG 		(* (reg8 *) analog_2__0__INTTYPE)
#endif /* (analog_2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_analog_2_H */


/* [] END OF FILE */
