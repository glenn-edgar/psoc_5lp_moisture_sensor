/*******************************************************************************
* File Name: filter_pressure_a4.h  
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

#if !defined(CY_PINS_filter_pressure_a4_H) /* Pins filter_pressure_a4_H */
#define CY_PINS_filter_pressure_a4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "filter_pressure_a4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 filter_pressure_a4__PORT == 15 && ((filter_pressure_a4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    filter_pressure_a4_Write(uint8 value);
void    filter_pressure_a4_SetDriveMode(uint8 mode);
uint8   filter_pressure_a4_ReadDataReg(void);
uint8   filter_pressure_a4_Read(void);
void    filter_pressure_a4_SetInterruptMode(uint16 position, uint16 mode);
uint8   filter_pressure_a4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the filter_pressure_a4_SetDriveMode() function.
     *  @{
     */
        #define filter_pressure_a4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define filter_pressure_a4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define filter_pressure_a4_DM_RES_UP          PIN_DM_RES_UP
        #define filter_pressure_a4_DM_RES_DWN         PIN_DM_RES_DWN
        #define filter_pressure_a4_DM_OD_LO           PIN_DM_OD_LO
        #define filter_pressure_a4_DM_OD_HI           PIN_DM_OD_HI
        #define filter_pressure_a4_DM_STRONG          PIN_DM_STRONG
        #define filter_pressure_a4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define filter_pressure_a4_MASK               filter_pressure_a4__MASK
#define filter_pressure_a4_SHIFT              filter_pressure_a4__SHIFT
#define filter_pressure_a4_WIDTH              1u

/* Interrupt constants */
#if defined(filter_pressure_a4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in filter_pressure_a4_SetInterruptMode() function.
     *  @{
     */
        #define filter_pressure_a4_INTR_NONE      (uint16)(0x0000u)
        #define filter_pressure_a4_INTR_RISING    (uint16)(0x0001u)
        #define filter_pressure_a4_INTR_FALLING   (uint16)(0x0002u)
        #define filter_pressure_a4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define filter_pressure_a4_INTR_MASK      (0x01u) 
#endif /* (filter_pressure_a4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define filter_pressure_a4_PS                     (* (reg8 *) filter_pressure_a4__PS)
/* Data Register */
#define filter_pressure_a4_DR                     (* (reg8 *) filter_pressure_a4__DR)
/* Port Number */
#define filter_pressure_a4_PRT_NUM                (* (reg8 *) filter_pressure_a4__PRT) 
/* Connect to Analog Globals */                                                  
#define filter_pressure_a4_AG                     (* (reg8 *) filter_pressure_a4__AG)                       
/* Analog MUX bux enable */
#define filter_pressure_a4_AMUX                   (* (reg8 *) filter_pressure_a4__AMUX) 
/* Bidirectional Enable */                                                        
#define filter_pressure_a4_BIE                    (* (reg8 *) filter_pressure_a4__BIE)
/* Bit-mask for Aliased Register Access */
#define filter_pressure_a4_BIT_MASK               (* (reg8 *) filter_pressure_a4__BIT_MASK)
/* Bypass Enable */
#define filter_pressure_a4_BYP                    (* (reg8 *) filter_pressure_a4__BYP)
/* Port wide control signals */                                                   
#define filter_pressure_a4_CTL                    (* (reg8 *) filter_pressure_a4__CTL)
/* Drive Modes */
#define filter_pressure_a4_DM0                    (* (reg8 *) filter_pressure_a4__DM0) 
#define filter_pressure_a4_DM1                    (* (reg8 *) filter_pressure_a4__DM1)
#define filter_pressure_a4_DM2                    (* (reg8 *) filter_pressure_a4__DM2) 
/* Input Buffer Disable Override */
#define filter_pressure_a4_INP_DIS                (* (reg8 *) filter_pressure_a4__INP_DIS)
/* LCD Common or Segment Drive */
#define filter_pressure_a4_LCD_COM_SEG            (* (reg8 *) filter_pressure_a4__LCD_COM_SEG)
/* Enable Segment LCD */
#define filter_pressure_a4_LCD_EN                 (* (reg8 *) filter_pressure_a4__LCD_EN)
/* Slew Rate Control */
#define filter_pressure_a4_SLW                    (* (reg8 *) filter_pressure_a4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define filter_pressure_a4_PRTDSI__CAPS_SEL       (* (reg8 *) filter_pressure_a4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define filter_pressure_a4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) filter_pressure_a4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define filter_pressure_a4_PRTDSI__OE_SEL0        (* (reg8 *) filter_pressure_a4__PRTDSI__OE_SEL0) 
#define filter_pressure_a4_PRTDSI__OE_SEL1        (* (reg8 *) filter_pressure_a4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define filter_pressure_a4_PRTDSI__OUT_SEL0       (* (reg8 *) filter_pressure_a4__PRTDSI__OUT_SEL0) 
#define filter_pressure_a4_PRTDSI__OUT_SEL1       (* (reg8 *) filter_pressure_a4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define filter_pressure_a4_PRTDSI__SYNC_OUT       (* (reg8 *) filter_pressure_a4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(filter_pressure_a4__SIO_CFG)
    #define filter_pressure_a4_SIO_HYST_EN        (* (reg8 *) filter_pressure_a4__SIO_HYST_EN)
    #define filter_pressure_a4_SIO_REG_HIFREQ     (* (reg8 *) filter_pressure_a4__SIO_REG_HIFREQ)
    #define filter_pressure_a4_SIO_CFG            (* (reg8 *) filter_pressure_a4__SIO_CFG)
    #define filter_pressure_a4_SIO_DIFF           (* (reg8 *) filter_pressure_a4__SIO_DIFF)
#endif /* (filter_pressure_a4__SIO_CFG) */

/* Interrupt Registers */
#if defined(filter_pressure_a4__INTSTAT)
    #define filter_pressure_a4_INTSTAT            (* (reg8 *) filter_pressure_a4__INTSTAT)
    #define filter_pressure_a4_SNAP               (* (reg8 *) filter_pressure_a4__SNAP)
    
	#define filter_pressure_a4_0_INTTYPE_REG 		(* (reg8 *) filter_pressure_a4__0__INTTYPE)
#endif /* (filter_pressure_a4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_filter_pressure_a4_H */


/* [] END OF FILE */
