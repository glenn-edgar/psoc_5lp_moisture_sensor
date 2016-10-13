/*******************************************************************************
* File Name: master_drive_output.h  
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

#if !defined(CY_PINS_master_drive_output_H) /* Pins master_drive_output_H */
#define CY_PINS_master_drive_output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "master_drive_output_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 master_drive_output__PORT == 15 && ((master_drive_output__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    master_drive_output_Write(uint8 value);
void    master_drive_output_SetDriveMode(uint8 mode);
uint8   master_drive_output_ReadDataReg(void);
uint8   master_drive_output_Read(void);
void    master_drive_output_SetInterruptMode(uint16 position, uint16 mode);
uint8   master_drive_output_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the master_drive_output_SetDriveMode() function.
     *  @{
     */
        #define master_drive_output_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define master_drive_output_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define master_drive_output_DM_RES_UP          PIN_DM_RES_UP
        #define master_drive_output_DM_RES_DWN         PIN_DM_RES_DWN
        #define master_drive_output_DM_OD_LO           PIN_DM_OD_LO
        #define master_drive_output_DM_OD_HI           PIN_DM_OD_HI
        #define master_drive_output_DM_STRONG          PIN_DM_STRONG
        #define master_drive_output_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define master_drive_output_MASK               master_drive_output__MASK
#define master_drive_output_SHIFT              master_drive_output__SHIFT
#define master_drive_output_WIDTH              1u

/* Interrupt constants */
#if defined(master_drive_output__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in master_drive_output_SetInterruptMode() function.
     *  @{
     */
        #define master_drive_output_INTR_NONE      (uint16)(0x0000u)
        #define master_drive_output_INTR_RISING    (uint16)(0x0001u)
        #define master_drive_output_INTR_FALLING   (uint16)(0x0002u)
        #define master_drive_output_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define master_drive_output_INTR_MASK      (0x01u) 
#endif /* (master_drive_output__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define master_drive_output_PS                     (* (reg8 *) master_drive_output__PS)
/* Data Register */
#define master_drive_output_DR                     (* (reg8 *) master_drive_output__DR)
/* Port Number */
#define master_drive_output_PRT_NUM                (* (reg8 *) master_drive_output__PRT) 
/* Connect to Analog Globals */                                                  
#define master_drive_output_AG                     (* (reg8 *) master_drive_output__AG)                       
/* Analog MUX bux enable */
#define master_drive_output_AMUX                   (* (reg8 *) master_drive_output__AMUX) 
/* Bidirectional Enable */                                                        
#define master_drive_output_BIE                    (* (reg8 *) master_drive_output__BIE)
/* Bit-mask for Aliased Register Access */
#define master_drive_output_BIT_MASK               (* (reg8 *) master_drive_output__BIT_MASK)
/* Bypass Enable */
#define master_drive_output_BYP                    (* (reg8 *) master_drive_output__BYP)
/* Port wide control signals */                                                   
#define master_drive_output_CTL                    (* (reg8 *) master_drive_output__CTL)
/* Drive Modes */
#define master_drive_output_DM0                    (* (reg8 *) master_drive_output__DM0) 
#define master_drive_output_DM1                    (* (reg8 *) master_drive_output__DM1)
#define master_drive_output_DM2                    (* (reg8 *) master_drive_output__DM2) 
/* Input Buffer Disable Override */
#define master_drive_output_INP_DIS                (* (reg8 *) master_drive_output__INP_DIS)
/* LCD Common or Segment Drive */
#define master_drive_output_LCD_COM_SEG            (* (reg8 *) master_drive_output__LCD_COM_SEG)
/* Enable Segment LCD */
#define master_drive_output_LCD_EN                 (* (reg8 *) master_drive_output__LCD_EN)
/* Slew Rate Control */
#define master_drive_output_SLW                    (* (reg8 *) master_drive_output__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define master_drive_output_PRTDSI__CAPS_SEL       (* (reg8 *) master_drive_output__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define master_drive_output_PRTDSI__DBL_SYNC_IN    (* (reg8 *) master_drive_output__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define master_drive_output_PRTDSI__OE_SEL0        (* (reg8 *) master_drive_output__PRTDSI__OE_SEL0) 
#define master_drive_output_PRTDSI__OE_SEL1        (* (reg8 *) master_drive_output__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define master_drive_output_PRTDSI__OUT_SEL0       (* (reg8 *) master_drive_output__PRTDSI__OUT_SEL0) 
#define master_drive_output_PRTDSI__OUT_SEL1       (* (reg8 *) master_drive_output__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define master_drive_output_PRTDSI__SYNC_OUT       (* (reg8 *) master_drive_output__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(master_drive_output__SIO_CFG)
    #define master_drive_output_SIO_HYST_EN        (* (reg8 *) master_drive_output__SIO_HYST_EN)
    #define master_drive_output_SIO_REG_HIFREQ     (* (reg8 *) master_drive_output__SIO_REG_HIFREQ)
    #define master_drive_output_SIO_CFG            (* (reg8 *) master_drive_output__SIO_CFG)
    #define master_drive_output_SIO_DIFF           (* (reg8 *) master_drive_output__SIO_DIFF)
#endif /* (master_drive_output__SIO_CFG) */

/* Interrupt Registers */
#if defined(master_drive_output__INTSTAT)
    #define master_drive_output_INTSTAT            (* (reg8 *) master_drive_output__INTSTAT)
    #define master_drive_output_SNAP               (* (reg8 *) master_drive_output__SNAP)
    
	#define master_drive_output_0_INTTYPE_REG 		(* (reg8 *) master_drive_output__0__INTTYPE)
#endif /* (master_drive_output__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_master_drive_output_H */


/* [] END OF FILE */
