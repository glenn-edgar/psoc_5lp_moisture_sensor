/*******************************************************************************
* File Name: vdda_2_signal.h  
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

#if !defined(CY_PINS_vdda_2_signal_H) /* Pins vdda_2_signal_H */
#define CY_PINS_vdda_2_signal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "vdda_2_signal_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 vdda_2_signal__PORT == 15 && ((vdda_2_signal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    vdda_2_signal_Write(uint8 value);
void    vdda_2_signal_SetDriveMode(uint8 mode);
uint8   vdda_2_signal_ReadDataReg(void);
uint8   vdda_2_signal_Read(void);
void    vdda_2_signal_SetInterruptMode(uint16 position, uint16 mode);
uint8   vdda_2_signal_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the vdda_2_signal_SetDriveMode() function.
     *  @{
     */
        #define vdda_2_signal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define vdda_2_signal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define vdda_2_signal_DM_RES_UP          PIN_DM_RES_UP
        #define vdda_2_signal_DM_RES_DWN         PIN_DM_RES_DWN
        #define vdda_2_signal_DM_OD_LO           PIN_DM_OD_LO
        #define vdda_2_signal_DM_OD_HI           PIN_DM_OD_HI
        #define vdda_2_signal_DM_STRONG          PIN_DM_STRONG
        #define vdda_2_signal_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define vdda_2_signal_MASK               vdda_2_signal__MASK
#define vdda_2_signal_SHIFT              vdda_2_signal__SHIFT
#define vdda_2_signal_WIDTH              1u

/* Interrupt constants */
#if defined(vdda_2_signal__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vdda_2_signal_SetInterruptMode() function.
     *  @{
     */
        #define vdda_2_signal_INTR_NONE      (uint16)(0x0000u)
        #define vdda_2_signal_INTR_RISING    (uint16)(0x0001u)
        #define vdda_2_signal_INTR_FALLING   (uint16)(0x0002u)
        #define vdda_2_signal_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define vdda_2_signal_INTR_MASK      (0x01u) 
#endif /* (vdda_2_signal__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define vdda_2_signal_PS                     (* (reg8 *) vdda_2_signal__PS)
/* Data Register */
#define vdda_2_signal_DR                     (* (reg8 *) vdda_2_signal__DR)
/* Port Number */
#define vdda_2_signal_PRT_NUM                (* (reg8 *) vdda_2_signal__PRT) 
/* Connect to Analog Globals */                                                  
#define vdda_2_signal_AG                     (* (reg8 *) vdda_2_signal__AG)                       
/* Analog MUX bux enable */
#define vdda_2_signal_AMUX                   (* (reg8 *) vdda_2_signal__AMUX) 
/* Bidirectional Enable */                                                        
#define vdda_2_signal_BIE                    (* (reg8 *) vdda_2_signal__BIE)
/* Bit-mask for Aliased Register Access */
#define vdda_2_signal_BIT_MASK               (* (reg8 *) vdda_2_signal__BIT_MASK)
/* Bypass Enable */
#define vdda_2_signal_BYP                    (* (reg8 *) vdda_2_signal__BYP)
/* Port wide control signals */                                                   
#define vdda_2_signal_CTL                    (* (reg8 *) vdda_2_signal__CTL)
/* Drive Modes */
#define vdda_2_signal_DM0                    (* (reg8 *) vdda_2_signal__DM0) 
#define vdda_2_signal_DM1                    (* (reg8 *) vdda_2_signal__DM1)
#define vdda_2_signal_DM2                    (* (reg8 *) vdda_2_signal__DM2) 
/* Input Buffer Disable Override */
#define vdda_2_signal_INP_DIS                (* (reg8 *) vdda_2_signal__INP_DIS)
/* LCD Common or Segment Drive */
#define vdda_2_signal_LCD_COM_SEG            (* (reg8 *) vdda_2_signal__LCD_COM_SEG)
/* Enable Segment LCD */
#define vdda_2_signal_LCD_EN                 (* (reg8 *) vdda_2_signal__LCD_EN)
/* Slew Rate Control */
#define vdda_2_signal_SLW                    (* (reg8 *) vdda_2_signal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define vdda_2_signal_PRTDSI__CAPS_SEL       (* (reg8 *) vdda_2_signal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define vdda_2_signal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) vdda_2_signal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define vdda_2_signal_PRTDSI__OE_SEL0        (* (reg8 *) vdda_2_signal__PRTDSI__OE_SEL0) 
#define vdda_2_signal_PRTDSI__OE_SEL1        (* (reg8 *) vdda_2_signal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define vdda_2_signal_PRTDSI__OUT_SEL0       (* (reg8 *) vdda_2_signal__PRTDSI__OUT_SEL0) 
#define vdda_2_signal_PRTDSI__OUT_SEL1       (* (reg8 *) vdda_2_signal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define vdda_2_signal_PRTDSI__SYNC_OUT       (* (reg8 *) vdda_2_signal__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(vdda_2_signal__SIO_CFG)
    #define vdda_2_signal_SIO_HYST_EN        (* (reg8 *) vdda_2_signal__SIO_HYST_EN)
    #define vdda_2_signal_SIO_REG_HIFREQ     (* (reg8 *) vdda_2_signal__SIO_REG_HIFREQ)
    #define vdda_2_signal_SIO_CFG            (* (reg8 *) vdda_2_signal__SIO_CFG)
    #define vdda_2_signal_SIO_DIFF           (* (reg8 *) vdda_2_signal__SIO_DIFF)
#endif /* (vdda_2_signal__SIO_CFG) */

/* Interrupt Registers */
#if defined(vdda_2_signal__INTSTAT)
    #define vdda_2_signal_INTSTAT            (* (reg8 *) vdda_2_signal__INTSTAT)
    #define vdda_2_signal_SNAP               (* (reg8 *) vdda_2_signal__SNAP)
    
	#define vdda_2_signal_0_INTTYPE_REG 		(* (reg8 *) vdda_2_signal__0__INTTYPE)
#endif /* (vdda_2_signal__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_vdda_2_signal_H */


/* [] END OF FILE */
