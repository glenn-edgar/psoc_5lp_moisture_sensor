/*******************************************************************************
* File Name: Digital_4.h  
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

#if !defined(CY_PINS_Digital_4_H) /* Pins Digital_4_H */
#define CY_PINS_Digital_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Digital_4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Digital_4__PORT == 15 && ((Digital_4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Digital_4_Write(uint8 value);
void    Digital_4_SetDriveMode(uint8 mode);
uint8   Digital_4_ReadDataReg(void);
uint8   Digital_4_Read(void);
void    Digital_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Digital_4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Digital_4_SetDriveMode() function.
     *  @{
     */
        #define Digital_4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Digital_4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Digital_4_DM_RES_UP          PIN_DM_RES_UP
        #define Digital_4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Digital_4_DM_OD_LO           PIN_DM_OD_LO
        #define Digital_4_DM_OD_HI           PIN_DM_OD_HI
        #define Digital_4_DM_STRONG          PIN_DM_STRONG
        #define Digital_4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Digital_4_MASK               Digital_4__MASK
#define Digital_4_SHIFT              Digital_4__SHIFT
#define Digital_4_WIDTH              1u

/* Interrupt constants */
#if defined(Digital_4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Digital_4_SetInterruptMode() function.
     *  @{
     */
        #define Digital_4_INTR_NONE      (uint16)(0x0000u)
        #define Digital_4_INTR_RISING    (uint16)(0x0001u)
        #define Digital_4_INTR_FALLING   (uint16)(0x0002u)
        #define Digital_4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Digital_4_INTR_MASK      (0x01u) 
#endif /* (Digital_4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Digital_4_PS                     (* (reg8 *) Digital_4__PS)
/* Data Register */
#define Digital_4_DR                     (* (reg8 *) Digital_4__DR)
/* Port Number */
#define Digital_4_PRT_NUM                (* (reg8 *) Digital_4__PRT) 
/* Connect to Analog Globals */                                                  
#define Digital_4_AG                     (* (reg8 *) Digital_4__AG)                       
/* Analog MUX bux enable */
#define Digital_4_AMUX                   (* (reg8 *) Digital_4__AMUX) 
/* Bidirectional Enable */                                                        
#define Digital_4_BIE                    (* (reg8 *) Digital_4__BIE)
/* Bit-mask for Aliased Register Access */
#define Digital_4_BIT_MASK               (* (reg8 *) Digital_4__BIT_MASK)
/* Bypass Enable */
#define Digital_4_BYP                    (* (reg8 *) Digital_4__BYP)
/* Port wide control signals */                                                   
#define Digital_4_CTL                    (* (reg8 *) Digital_4__CTL)
/* Drive Modes */
#define Digital_4_DM0                    (* (reg8 *) Digital_4__DM0) 
#define Digital_4_DM1                    (* (reg8 *) Digital_4__DM1)
#define Digital_4_DM2                    (* (reg8 *) Digital_4__DM2) 
/* Input Buffer Disable Override */
#define Digital_4_INP_DIS                (* (reg8 *) Digital_4__INP_DIS)
/* LCD Common or Segment Drive */
#define Digital_4_LCD_COM_SEG            (* (reg8 *) Digital_4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Digital_4_LCD_EN                 (* (reg8 *) Digital_4__LCD_EN)
/* Slew Rate Control */
#define Digital_4_SLW                    (* (reg8 *) Digital_4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Digital_4_PRTDSI__CAPS_SEL       (* (reg8 *) Digital_4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Digital_4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Digital_4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Digital_4_PRTDSI__OE_SEL0        (* (reg8 *) Digital_4__PRTDSI__OE_SEL0) 
#define Digital_4_PRTDSI__OE_SEL1        (* (reg8 *) Digital_4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Digital_4_PRTDSI__OUT_SEL0       (* (reg8 *) Digital_4__PRTDSI__OUT_SEL0) 
#define Digital_4_PRTDSI__OUT_SEL1       (* (reg8 *) Digital_4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Digital_4_PRTDSI__SYNC_OUT       (* (reg8 *) Digital_4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Digital_4__SIO_CFG)
    #define Digital_4_SIO_HYST_EN        (* (reg8 *) Digital_4__SIO_HYST_EN)
    #define Digital_4_SIO_REG_HIFREQ     (* (reg8 *) Digital_4__SIO_REG_HIFREQ)
    #define Digital_4_SIO_CFG            (* (reg8 *) Digital_4__SIO_CFG)
    #define Digital_4_SIO_DIFF           (* (reg8 *) Digital_4__SIO_DIFF)
#endif /* (Digital_4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Digital_4__INTSTAT)
    #define Digital_4_INTSTAT            (* (reg8 *) Digital_4__INTSTAT)
    #define Digital_4_SNAP               (* (reg8 *) Digital_4__SNAP)
    
	#define Digital_4_0_INTTYPE_REG 		(* (reg8 *) Digital_4__0__INTTYPE)
#endif /* (Digital_4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Digital_4_H */


/* [] END OF FILE */
