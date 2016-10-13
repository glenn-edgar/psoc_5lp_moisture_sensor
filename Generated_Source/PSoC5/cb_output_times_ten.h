/*******************************************************************************
* File Name: cb_output_times_ten.h  
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

#if !defined(CY_PINS_cb_output_times_ten_H) /* Pins cb_output_times_ten_H */
#define CY_PINS_cb_output_times_ten_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "cb_output_times_ten_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 cb_output_times_ten__PORT == 15 && ((cb_output_times_ten__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    cb_output_times_ten_Write(uint8 value);
void    cb_output_times_ten_SetDriveMode(uint8 mode);
uint8   cb_output_times_ten_ReadDataReg(void);
uint8   cb_output_times_ten_Read(void);
void    cb_output_times_ten_SetInterruptMode(uint16 position, uint16 mode);
uint8   cb_output_times_ten_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the cb_output_times_ten_SetDriveMode() function.
     *  @{
     */
        #define cb_output_times_ten_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define cb_output_times_ten_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define cb_output_times_ten_DM_RES_UP          PIN_DM_RES_UP
        #define cb_output_times_ten_DM_RES_DWN         PIN_DM_RES_DWN
        #define cb_output_times_ten_DM_OD_LO           PIN_DM_OD_LO
        #define cb_output_times_ten_DM_OD_HI           PIN_DM_OD_HI
        #define cb_output_times_ten_DM_STRONG          PIN_DM_STRONG
        #define cb_output_times_ten_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define cb_output_times_ten_MASK               cb_output_times_ten__MASK
#define cb_output_times_ten_SHIFT              cb_output_times_ten__SHIFT
#define cb_output_times_ten_WIDTH              1u

/* Interrupt constants */
#if defined(cb_output_times_ten__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in cb_output_times_ten_SetInterruptMode() function.
     *  @{
     */
        #define cb_output_times_ten_INTR_NONE      (uint16)(0x0000u)
        #define cb_output_times_ten_INTR_RISING    (uint16)(0x0001u)
        #define cb_output_times_ten_INTR_FALLING   (uint16)(0x0002u)
        #define cb_output_times_ten_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define cb_output_times_ten_INTR_MASK      (0x01u) 
#endif /* (cb_output_times_ten__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define cb_output_times_ten_PS                     (* (reg8 *) cb_output_times_ten__PS)
/* Data Register */
#define cb_output_times_ten_DR                     (* (reg8 *) cb_output_times_ten__DR)
/* Port Number */
#define cb_output_times_ten_PRT_NUM                (* (reg8 *) cb_output_times_ten__PRT) 
/* Connect to Analog Globals */                                                  
#define cb_output_times_ten_AG                     (* (reg8 *) cb_output_times_ten__AG)                       
/* Analog MUX bux enable */
#define cb_output_times_ten_AMUX                   (* (reg8 *) cb_output_times_ten__AMUX) 
/* Bidirectional Enable */                                                        
#define cb_output_times_ten_BIE                    (* (reg8 *) cb_output_times_ten__BIE)
/* Bit-mask for Aliased Register Access */
#define cb_output_times_ten_BIT_MASK               (* (reg8 *) cb_output_times_ten__BIT_MASK)
/* Bypass Enable */
#define cb_output_times_ten_BYP                    (* (reg8 *) cb_output_times_ten__BYP)
/* Port wide control signals */                                                   
#define cb_output_times_ten_CTL                    (* (reg8 *) cb_output_times_ten__CTL)
/* Drive Modes */
#define cb_output_times_ten_DM0                    (* (reg8 *) cb_output_times_ten__DM0) 
#define cb_output_times_ten_DM1                    (* (reg8 *) cb_output_times_ten__DM1)
#define cb_output_times_ten_DM2                    (* (reg8 *) cb_output_times_ten__DM2) 
/* Input Buffer Disable Override */
#define cb_output_times_ten_INP_DIS                (* (reg8 *) cb_output_times_ten__INP_DIS)
/* LCD Common or Segment Drive */
#define cb_output_times_ten_LCD_COM_SEG            (* (reg8 *) cb_output_times_ten__LCD_COM_SEG)
/* Enable Segment LCD */
#define cb_output_times_ten_LCD_EN                 (* (reg8 *) cb_output_times_ten__LCD_EN)
/* Slew Rate Control */
#define cb_output_times_ten_SLW                    (* (reg8 *) cb_output_times_ten__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define cb_output_times_ten_PRTDSI__CAPS_SEL       (* (reg8 *) cb_output_times_ten__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define cb_output_times_ten_PRTDSI__DBL_SYNC_IN    (* (reg8 *) cb_output_times_ten__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define cb_output_times_ten_PRTDSI__OE_SEL0        (* (reg8 *) cb_output_times_ten__PRTDSI__OE_SEL0) 
#define cb_output_times_ten_PRTDSI__OE_SEL1        (* (reg8 *) cb_output_times_ten__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define cb_output_times_ten_PRTDSI__OUT_SEL0       (* (reg8 *) cb_output_times_ten__PRTDSI__OUT_SEL0) 
#define cb_output_times_ten_PRTDSI__OUT_SEL1       (* (reg8 *) cb_output_times_ten__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define cb_output_times_ten_PRTDSI__SYNC_OUT       (* (reg8 *) cb_output_times_ten__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(cb_output_times_ten__SIO_CFG)
    #define cb_output_times_ten_SIO_HYST_EN        (* (reg8 *) cb_output_times_ten__SIO_HYST_EN)
    #define cb_output_times_ten_SIO_REG_HIFREQ     (* (reg8 *) cb_output_times_ten__SIO_REG_HIFREQ)
    #define cb_output_times_ten_SIO_CFG            (* (reg8 *) cb_output_times_ten__SIO_CFG)
    #define cb_output_times_ten_SIO_DIFF           (* (reg8 *) cb_output_times_ten__SIO_DIFF)
#endif /* (cb_output_times_ten__SIO_CFG) */

/* Interrupt Registers */
#if defined(cb_output_times_ten__INTSTAT)
    #define cb_output_times_ten_INTSTAT            (* (reg8 *) cb_output_times_ten__INTSTAT)
    #define cb_output_times_ten_SNAP               (* (reg8 *) cb_output_times_ten__SNAP)
    
	#define cb_output_times_ten_0_INTTYPE_REG 		(* (reg8 *) cb_output_times_ten__0__INTTYPE)
#endif /* (cb_output_times_ten__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_cb_output_times_ten_H */


/* [] END OF FILE */
