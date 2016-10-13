/*******************************************************************************
* File Name: Active_Pin.h  
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

#if !defined(CY_PINS_Active_Pin_H) /* Pins Active_Pin_H */
#define CY_PINS_Active_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Active_Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Active_Pin__PORT == 15 && ((Active_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Active_Pin_Write(uint8 value);
void    Active_Pin_SetDriveMode(uint8 mode);
uint8   Active_Pin_ReadDataReg(void);
uint8   Active_Pin_Read(void);
void    Active_Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   Active_Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Active_Pin_SetDriveMode() function.
     *  @{
     */
        #define Active_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Active_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Active_Pin_DM_RES_UP          PIN_DM_RES_UP
        #define Active_Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define Active_Pin_DM_OD_LO           PIN_DM_OD_LO
        #define Active_Pin_DM_OD_HI           PIN_DM_OD_HI
        #define Active_Pin_DM_STRONG          PIN_DM_STRONG
        #define Active_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Active_Pin_MASK               Active_Pin__MASK
#define Active_Pin_SHIFT              Active_Pin__SHIFT
#define Active_Pin_WIDTH              1u

/* Interrupt constants */
#if defined(Active_Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Active_Pin_SetInterruptMode() function.
     *  @{
     */
        #define Active_Pin_INTR_NONE      (uint16)(0x0000u)
        #define Active_Pin_INTR_RISING    (uint16)(0x0001u)
        #define Active_Pin_INTR_FALLING   (uint16)(0x0002u)
        #define Active_Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Active_Pin_INTR_MASK      (0x01u) 
#endif /* (Active_Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Active_Pin_PS                     (* (reg8 *) Active_Pin__PS)
/* Data Register */
#define Active_Pin_DR                     (* (reg8 *) Active_Pin__DR)
/* Port Number */
#define Active_Pin_PRT_NUM                (* (reg8 *) Active_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define Active_Pin_AG                     (* (reg8 *) Active_Pin__AG)                       
/* Analog MUX bux enable */
#define Active_Pin_AMUX                   (* (reg8 *) Active_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define Active_Pin_BIE                    (* (reg8 *) Active_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define Active_Pin_BIT_MASK               (* (reg8 *) Active_Pin__BIT_MASK)
/* Bypass Enable */
#define Active_Pin_BYP                    (* (reg8 *) Active_Pin__BYP)
/* Port wide control signals */                                                   
#define Active_Pin_CTL                    (* (reg8 *) Active_Pin__CTL)
/* Drive Modes */
#define Active_Pin_DM0                    (* (reg8 *) Active_Pin__DM0) 
#define Active_Pin_DM1                    (* (reg8 *) Active_Pin__DM1)
#define Active_Pin_DM2                    (* (reg8 *) Active_Pin__DM2) 
/* Input Buffer Disable Override */
#define Active_Pin_INP_DIS                (* (reg8 *) Active_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define Active_Pin_LCD_COM_SEG            (* (reg8 *) Active_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define Active_Pin_LCD_EN                 (* (reg8 *) Active_Pin__LCD_EN)
/* Slew Rate Control */
#define Active_Pin_SLW                    (* (reg8 *) Active_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Active_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) Active_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Active_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Active_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Active_Pin_PRTDSI__OE_SEL0        (* (reg8 *) Active_Pin__PRTDSI__OE_SEL0) 
#define Active_Pin_PRTDSI__OE_SEL1        (* (reg8 *) Active_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Active_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) Active_Pin__PRTDSI__OUT_SEL0) 
#define Active_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) Active_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Active_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) Active_Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Active_Pin__SIO_CFG)
    #define Active_Pin_SIO_HYST_EN        (* (reg8 *) Active_Pin__SIO_HYST_EN)
    #define Active_Pin_SIO_REG_HIFREQ     (* (reg8 *) Active_Pin__SIO_REG_HIFREQ)
    #define Active_Pin_SIO_CFG            (* (reg8 *) Active_Pin__SIO_CFG)
    #define Active_Pin_SIO_DIFF           (* (reg8 *) Active_Pin__SIO_DIFF)
#endif /* (Active_Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(Active_Pin__INTSTAT)
    #define Active_Pin_INTSTAT            (* (reg8 *) Active_Pin__INTSTAT)
    #define Active_Pin_SNAP               (* (reg8 *) Active_Pin__SNAP)
    
	#define Active_Pin_0_INTTYPE_REG 		(* (reg8 *) Active_Pin__0__INTTYPE)
#endif /* (Active_Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Active_Pin_H */


/* [] END OF FILE */
