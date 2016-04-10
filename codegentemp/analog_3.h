/*******************************************************************************
* File Name: analog_3.h  
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

#if !defined(CY_PINS_analog_3_H) /* Pins analog_3_H */
#define CY_PINS_analog_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "analog_3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 analog_3__PORT == 15 && ((analog_3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    analog_3_Write(uint8 value);
void    analog_3_SetDriveMode(uint8 mode);
uint8   analog_3_ReadDataReg(void);
uint8   analog_3_Read(void);
void    analog_3_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the analog_3_SetDriveMode() function.
     *  @{
     */
        #define analog_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define analog_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define analog_3_DM_RES_UP          PIN_DM_RES_UP
        #define analog_3_DM_RES_DWN         PIN_DM_RES_DWN
        #define analog_3_DM_OD_LO           PIN_DM_OD_LO
        #define analog_3_DM_OD_HI           PIN_DM_OD_HI
        #define analog_3_DM_STRONG          PIN_DM_STRONG
        #define analog_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define analog_3_MASK               analog_3__MASK
#define analog_3_SHIFT              analog_3__SHIFT
#define analog_3_WIDTH              1u

/* Interrupt constants */
#if defined(analog_3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_3_SetInterruptMode() function.
     *  @{
     */
        #define analog_3_INTR_NONE      (uint16)(0x0000u)
        #define analog_3_INTR_RISING    (uint16)(0x0001u)
        #define analog_3_INTR_FALLING   (uint16)(0x0002u)
        #define analog_3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define analog_3_INTR_MASK      (0x01u) 
#endif /* (analog_3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define analog_3_PS                     (* (reg8 *) analog_3__PS)
/* Data Register */
#define analog_3_DR                     (* (reg8 *) analog_3__DR)
/* Port Number */
#define analog_3_PRT_NUM                (* (reg8 *) analog_3__PRT) 
/* Connect to Analog Globals */                                                  
#define analog_3_AG                     (* (reg8 *) analog_3__AG)                       
/* Analog MUX bux enable */
#define analog_3_AMUX                   (* (reg8 *) analog_3__AMUX) 
/* Bidirectional Enable */                                                        
#define analog_3_BIE                    (* (reg8 *) analog_3__BIE)
/* Bit-mask for Aliased Register Access */
#define analog_3_BIT_MASK               (* (reg8 *) analog_3__BIT_MASK)
/* Bypass Enable */
#define analog_3_BYP                    (* (reg8 *) analog_3__BYP)
/* Port wide control signals */                                                   
#define analog_3_CTL                    (* (reg8 *) analog_3__CTL)
/* Drive Modes */
#define analog_3_DM0                    (* (reg8 *) analog_3__DM0) 
#define analog_3_DM1                    (* (reg8 *) analog_3__DM1)
#define analog_3_DM2                    (* (reg8 *) analog_3__DM2) 
/* Input Buffer Disable Override */
#define analog_3_INP_DIS                (* (reg8 *) analog_3__INP_DIS)
/* LCD Common or Segment Drive */
#define analog_3_LCD_COM_SEG            (* (reg8 *) analog_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define analog_3_LCD_EN                 (* (reg8 *) analog_3__LCD_EN)
/* Slew Rate Control */
#define analog_3_SLW                    (* (reg8 *) analog_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define analog_3_PRTDSI__CAPS_SEL       (* (reg8 *) analog_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define analog_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) analog_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define analog_3_PRTDSI__OE_SEL0        (* (reg8 *) analog_3__PRTDSI__OE_SEL0) 
#define analog_3_PRTDSI__OE_SEL1        (* (reg8 *) analog_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define analog_3_PRTDSI__OUT_SEL0       (* (reg8 *) analog_3__PRTDSI__OUT_SEL0) 
#define analog_3_PRTDSI__OUT_SEL1       (* (reg8 *) analog_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define analog_3_PRTDSI__SYNC_OUT       (* (reg8 *) analog_3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(analog_3__SIO_CFG)
    #define analog_3_SIO_HYST_EN        (* (reg8 *) analog_3__SIO_HYST_EN)
    #define analog_3_SIO_REG_HIFREQ     (* (reg8 *) analog_3__SIO_REG_HIFREQ)
    #define analog_3_SIO_CFG            (* (reg8 *) analog_3__SIO_CFG)
    #define analog_3_SIO_DIFF           (* (reg8 *) analog_3__SIO_DIFF)
#endif /* (analog_3__SIO_CFG) */

/* Interrupt Registers */
#if defined(analog_3__INTSTAT)
    #define analog_3_INTSTAT            (* (reg8 *) analog_3__INTSTAT)
    #define analog_3_SNAP               (* (reg8 *) analog_3__SNAP)
    
	#define analog_3_0_INTTYPE_REG 		(* (reg8 *) analog_3__0__INTTYPE)
#endif /* (analog_3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_analog_3_H */


/* [] END OF FILE */
