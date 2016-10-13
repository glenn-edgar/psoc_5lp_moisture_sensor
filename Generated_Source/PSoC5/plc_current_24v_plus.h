/*******************************************************************************
* File Name: plc_current_24v_plus.h  
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

#if !defined(CY_PINS_plc_current_24v_plus_H) /* Pins plc_current_24v_plus_H */
#define CY_PINS_plc_current_24v_plus_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "plc_current_24v_plus_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 plc_current_24v_plus__PORT == 15 && ((plc_current_24v_plus__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    plc_current_24v_plus_Write(uint8 value);
void    plc_current_24v_plus_SetDriveMode(uint8 mode);
uint8   plc_current_24v_plus_ReadDataReg(void);
uint8   plc_current_24v_plus_Read(void);
void    plc_current_24v_plus_SetInterruptMode(uint16 position, uint16 mode);
uint8   plc_current_24v_plus_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the plc_current_24v_plus_SetDriveMode() function.
     *  @{
     */
        #define plc_current_24v_plus_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define plc_current_24v_plus_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define plc_current_24v_plus_DM_RES_UP          PIN_DM_RES_UP
        #define plc_current_24v_plus_DM_RES_DWN         PIN_DM_RES_DWN
        #define plc_current_24v_plus_DM_OD_LO           PIN_DM_OD_LO
        #define plc_current_24v_plus_DM_OD_HI           PIN_DM_OD_HI
        #define plc_current_24v_plus_DM_STRONG          PIN_DM_STRONG
        #define plc_current_24v_plus_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define plc_current_24v_plus_MASK               plc_current_24v_plus__MASK
#define plc_current_24v_plus_SHIFT              plc_current_24v_plus__SHIFT
#define plc_current_24v_plus_WIDTH              1u

/* Interrupt constants */
#if defined(plc_current_24v_plus__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in plc_current_24v_plus_SetInterruptMode() function.
     *  @{
     */
        #define plc_current_24v_plus_INTR_NONE      (uint16)(0x0000u)
        #define plc_current_24v_plus_INTR_RISING    (uint16)(0x0001u)
        #define plc_current_24v_plus_INTR_FALLING   (uint16)(0x0002u)
        #define plc_current_24v_plus_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define plc_current_24v_plus_INTR_MASK      (0x01u) 
#endif /* (plc_current_24v_plus__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define plc_current_24v_plus_PS                     (* (reg8 *) plc_current_24v_plus__PS)
/* Data Register */
#define plc_current_24v_plus_DR                     (* (reg8 *) plc_current_24v_plus__DR)
/* Port Number */
#define plc_current_24v_plus_PRT_NUM                (* (reg8 *) plc_current_24v_plus__PRT) 
/* Connect to Analog Globals */                                                  
#define plc_current_24v_plus_AG                     (* (reg8 *) plc_current_24v_plus__AG)                       
/* Analog MUX bux enable */
#define plc_current_24v_plus_AMUX                   (* (reg8 *) plc_current_24v_plus__AMUX) 
/* Bidirectional Enable */                                                        
#define plc_current_24v_plus_BIE                    (* (reg8 *) plc_current_24v_plus__BIE)
/* Bit-mask for Aliased Register Access */
#define plc_current_24v_plus_BIT_MASK               (* (reg8 *) plc_current_24v_plus__BIT_MASK)
/* Bypass Enable */
#define plc_current_24v_plus_BYP                    (* (reg8 *) plc_current_24v_plus__BYP)
/* Port wide control signals */                                                   
#define plc_current_24v_plus_CTL                    (* (reg8 *) plc_current_24v_plus__CTL)
/* Drive Modes */
#define plc_current_24v_plus_DM0                    (* (reg8 *) plc_current_24v_plus__DM0) 
#define plc_current_24v_plus_DM1                    (* (reg8 *) plc_current_24v_plus__DM1)
#define plc_current_24v_plus_DM2                    (* (reg8 *) plc_current_24v_plus__DM2) 
/* Input Buffer Disable Override */
#define plc_current_24v_plus_INP_DIS                (* (reg8 *) plc_current_24v_plus__INP_DIS)
/* LCD Common or Segment Drive */
#define plc_current_24v_plus_LCD_COM_SEG            (* (reg8 *) plc_current_24v_plus__LCD_COM_SEG)
/* Enable Segment LCD */
#define plc_current_24v_plus_LCD_EN                 (* (reg8 *) plc_current_24v_plus__LCD_EN)
/* Slew Rate Control */
#define plc_current_24v_plus_SLW                    (* (reg8 *) plc_current_24v_plus__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define plc_current_24v_plus_PRTDSI__CAPS_SEL       (* (reg8 *) plc_current_24v_plus__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define plc_current_24v_plus_PRTDSI__DBL_SYNC_IN    (* (reg8 *) plc_current_24v_plus__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define plc_current_24v_plus_PRTDSI__OE_SEL0        (* (reg8 *) plc_current_24v_plus__PRTDSI__OE_SEL0) 
#define plc_current_24v_plus_PRTDSI__OE_SEL1        (* (reg8 *) plc_current_24v_plus__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define plc_current_24v_plus_PRTDSI__OUT_SEL0       (* (reg8 *) plc_current_24v_plus__PRTDSI__OUT_SEL0) 
#define plc_current_24v_plus_PRTDSI__OUT_SEL1       (* (reg8 *) plc_current_24v_plus__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define plc_current_24v_plus_PRTDSI__SYNC_OUT       (* (reg8 *) plc_current_24v_plus__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(plc_current_24v_plus__SIO_CFG)
    #define plc_current_24v_plus_SIO_HYST_EN        (* (reg8 *) plc_current_24v_plus__SIO_HYST_EN)
    #define plc_current_24v_plus_SIO_REG_HIFREQ     (* (reg8 *) plc_current_24v_plus__SIO_REG_HIFREQ)
    #define plc_current_24v_plus_SIO_CFG            (* (reg8 *) plc_current_24v_plus__SIO_CFG)
    #define plc_current_24v_plus_SIO_DIFF           (* (reg8 *) plc_current_24v_plus__SIO_DIFF)
#endif /* (plc_current_24v_plus__SIO_CFG) */

/* Interrupt Registers */
#if defined(plc_current_24v_plus__INTSTAT)
    #define plc_current_24v_plus_INTSTAT            (* (reg8 *) plc_current_24v_plus__INTSTAT)
    #define plc_current_24v_plus_SNAP               (* (reg8 *) plc_current_24v_plus__SNAP)
    
	#define plc_current_24v_plus_0_INTTYPE_REG 		(* (reg8 *) plc_current_24v_plus__0__INTTYPE)
#endif /* (plc_current_24v_plus__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_plc_current_24v_plus_H */


/* [] END OF FILE */
