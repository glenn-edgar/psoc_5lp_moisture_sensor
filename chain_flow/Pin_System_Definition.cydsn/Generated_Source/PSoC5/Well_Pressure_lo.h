/*******************************************************************************
* File Name: Well_Pressure_lo.h  
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

#if !defined(CY_PINS_Well_Pressure_lo_H) /* Pins Well_Pressure_lo_H */
#define CY_PINS_Well_Pressure_lo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Well_Pressure_lo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Well_Pressure_lo__PORT == 15 && ((Well_Pressure_lo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Well_Pressure_lo_Write(uint8 value);
void    Well_Pressure_lo_SetDriveMode(uint8 mode);
uint8   Well_Pressure_lo_ReadDataReg(void);
uint8   Well_Pressure_lo_Read(void);
void    Well_Pressure_lo_SetInterruptMode(uint16 position, uint16 mode);
uint8   Well_Pressure_lo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Well_Pressure_lo_SetDriveMode() function.
     *  @{
     */
        #define Well_Pressure_lo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Well_Pressure_lo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Well_Pressure_lo_DM_RES_UP          PIN_DM_RES_UP
        #define Well_Pressure_lo_DM_RES_DWN         PIN_DM_RES_DWN
        #define Well_Pressure_lo_DM_OD_LO           PIN_DM_OD_LO
        #define Well_Pressure_lo_DM_OD_HI           PIN_DM_OD_HI
        #define Well_Pressure_lo_DM_STRONG          PIN_DM_STRONG
        #define Well_Pressure_lo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Well_Pressure_lo_MASK               Well_Pressure_lo__MASK
#define Well_Pressure_lo_SHIFT              Well_Pressure_lo__SHIFT
#define Well_Pressure_lo_WIDTH              1u

/* Interrupt constants */
#if defined(Well_Pressure_lo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Well_Pressure_lo_SetInterruptMode() function.
     *  @{
     */
        #define Well_Pressure_lo_INTR_NONE      (uint16)(0x0000u)
        #define Well_Pressure_lo_INTR_RISING    (uint16)(0x0001u)
        #define Well_Pressure_lo_INTR_FALLING   (uint16)(0x0002u)
        #define Well_Pressure_lo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Well_Pressure_lo_INTR_MASK      (0x01u) 
#endif /* (Well_Pressure_lo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Well_Pressure_lo_PS                     (* (reg8 *) Well_Pressure_lo__PS)
/* Data Register */
#define Well_Pressure_lo_DR                     (* (reg8 *) Well_Pressure_lo__DR)
/* Port Number */
#define Well_Pressure_lo_PRT_NUM                (* (reg8 *) Well_Pressure_lo__PRT) 
/* Connect to Analog Globals */                                                  
#define Well_Pressure_lo_AG                     (* (reg8 *) Well_Pressure_lo__AG)                       
/* Analog MUX bux enable */
#define Well_Pressure_lo_AMUX                   (* (reg8 *) Well_Pressure_lo__AMUX) 
/* Bidirectional Enable */                                                        
#define Well_Pressure_lo_BIE                    (* (reg8 *) Well_Pressure_lo__BIE)
/* Bit-mask for Aliased Register Access */
#define Well_Pressure_lo_BIT_MASK               (* (reg8 *) Well_Pressure_lo__BIT_MASK)
/* Bypass Enable */
#define Well_Pressure_lo_BYP                    (* (reg8 *) Well_Pressure_lo__BYP)
/* Port wide control signals */                                                   
#define Well_Pressure_lo_CTL                    (* (reg8 *) Well_Pressure_lo__CTL)
/* Drive Modes */
#define Well_Pressure_lo_DM0                    (* (reg8 *) Well_Pressure_lo__DM0) 
#define Well_Pressure_lo_DM1                    (* (reg8 *) Well_Pressure_lo__DM1)
#define Well_Pressure_lo_DM2                    (* (reg8 *) Well_Pressure_lo__DM2) 
/* Input Buffer Disable Override */
#define Well_Pressure_lo_INP_DIS                (* (reg8 *) Well_Pressure_lo__INP_DIS)
/* LCD Common or Segment Drive */
#define Well_Pressure_lo_LCD_COM_SEG            (* (reg8 *) Well_Pressure_lo__LCD_COM_SEG)
/* Enable Segment LCD */
#define Well_Pressure_lo_LCD_EN                 (* (reg8 *) Well_Pressure_lo__LCD_EN)
/* Slew Rate Control */
#define Well_Pressure_lo_SLW                    (* (reg8 *) Well_Pressure_lo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Well_Pressure_lo_PRTDSI__CAPS_SEL       (* (reg8 *) Well_Pressure_lo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Well_Pressure_lo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Well_Pressure_lo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Well_Pressure_lo_PRTDSI__OE_SEL0        (* (reg8 *) Well_Pressure_lo__PRTDSI__OE_SEL0) 
#define Well_Pressure_lo_PRTDSI__OE_SEL1        (* (reg8 *) Well_Pressure_lo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Well_Pressure_lo_PRTDSI__OUT_SEL0       (* (reg8 *) Well_Pressure_lo__PRTDSI__OUT_SEL0) 
#define Well_Pressure_lo_PRTDSI__OUT_SEL1       (* (reg8 *) Well_Pressure_lo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Well_Pressure_lo_PRTDSI__SYNC_OUT       (* (reg8 *) Well_Pressure_lo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Well_Pressure_lo__SIO_CFG)
    #define Well_Pressure_lo_SIO_HYST_EN        (* (reg8 *) Well_Pressure_lo__SIO_HYST_EN)
    #define Well_Pressure_lo_SIO_REG_HIFREQ     (* (reg8 *) Well_Pressure_lo__SIO_REG_HIFREQ)
    #define Well_Pressure_lo_SIO_CFG            (* (reg8 *) Well_Pressure_lo__SIO_CFG)
    #define Well_Pressure_lo_SIO_DIFF           (* (reg8 *) Well_Pressure_lo__SIO_DIFF)
#endif /* (Well_Pressure_lo__SIO_CFG) */

/* Interrupt Registers */
#if defined(Well_Pressure_lo__INTSTAT)
    #define Well_Pressure_lo_INTSTAT            (* (reg8 *) Well_Pressure_lo__INTSTAT)
    #define Well_Pressure_lo_SNAP               (* (reg8 *) Well_Pressure_lo__SNAP)
    
	#define Well_Pressure_lo_0_INTTYPE_REG 		(* (reg8 *) Well_Pressure_lo__0__INTTYPE)
#endif /* (Well_Pressure_lo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Well_Pressure_lo_H */


/* [] END OF FILE */
