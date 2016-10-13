/*******************************************************************************
* File Name: Output_Pins.h  
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

#if !defined(CY_PINS_Output_Pins_H) /* Pins Output_Pins_H */
#define CY_PINS_Output_Pins_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Output_Pins_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Output_Pins__PORT == 15 && ((Output_Pins__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Output_Pins_Write(uint8 value);
void    Output_Pins_SetDriveMode(uint8 mode);
uint8   Output_Pins_ReadDataReg(void);
uint8   Output_Pins_Read(void);
void    Output_Pins_SetInterruptMode(uint16 position, uint16 mode);
uint8   Output_Pins_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Output_Pins_SetDriveMode() function.
     *  @{
     */
        #define Output_Pins_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Output_Pins_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Output_Pins_DM_RES_UP          PIN_DM_RES_UP
        #define Output_Pins_DM_RES_DWN         PIN_DM_RES_DWN
        #define Output_Pins_DM_OD_LO           PIN_DM_OD_LO
        #define Output_Pins_DM_OD_HI           PIN_DM_OD_HI
        #define Output_Pins_DM_STRONG          PIN_DM_STRONG
        #define Output_Pins_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Output_Pins_MASK               Output_Pins__MASK
#define Output_Pins_SHIFT              Output_Pins__SHIFT
#define Output_Pins_WIDTH              4u

/* Interrupt constants */
#if defined(Output_Pins__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Output_Pins_SetInterruptMode() function.
     *  @{
     */
        #define Output_Pins_INTR_NONE      (uint16)(0x0000u)
        #define Output_Pins_INTR_RISING    (uint16)(0x0001u)
        #define Output_Pins_INTR_FALLING   (uint16)(0x0002u)
        #define Output_Pins_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Output_Pins_INTR_MASK      (0x01u) 
#endif /* (Output_Pins__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Output_Pins_PS                     (* (reg8 *) Output_Pins__PS)
/* Data Register */
#define Output_Pins_DR                     (* (reg8 *) Output_Pins__DR)
/* Port Number */
#define Output_Pins_PRT_NUM                (* (reg8 *) Output_Pins__PRT) 
/* Connect to Analog Globals */                                                  
#define Output_Pins_AG                     (* (reg8 *) Output_Pins__AG)                       
/* Analog MUX bux enable */
#define Output_Pins_AMUX                   (* (reg8 *) Output_Pins__AMUX) 
/* Bidirectional Enable */                                                        
#define Output_Pins_BIE                    (* (reg8 *) Output_Pins__BIE)
/* Bit-mask for Aliased Register Access */
#define Output_Pins_BIT_MASK               (* (reg8 *) Output_Pins__BIT_MASK)
/* Bypass Enable */
#define Output_Pins_BYP                    (* (reg8 *) Output_Pins__BYP)
/* Port wide control signals */                                                   
#define Output_Pins_CTL                    (* (reg8 *) Output_Pins__CTL)
/* Drive Modes */
#define Output_Pins_DM0                    (* (reg8 *) Output_Pins__DM0) 
#define Output_Pins_DM1                    (* (reg8 *) Output_Pins__DM1)
#define Output_Pins_DM2                    (* (reg8 *) Output_Pins__DM2) 
/* Input Buffer Disable Override */
#define Output_Pins_INP_DIS                (* (reg8 *) Output_Pins__INP_DIS)
/* LCD Common or Segment Drive */
#define Output_Pins_LCD_COM_SEG            (* (reg8 *) Output_Pins__LCD_COM_SEG)
/* Enable Segment LCD */
#define Output_Pins_LCD_EN                 (* (reg8 *) Output_Pins__LCD_EN)
/* Slew Rate Control */
#define Output_Pins_SLW                    (* (reg8 *) Output_Pins__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Output_Pins_PRTDSI__CAPS_SEL       (* (reg8 *) Output_Pins__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Output_Pins_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Output_Pins__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Output_Pins_PRTDSI__OE_SEL0        (* (reg8 *) Output_Pins__PRTDSI__OE_SEL0) 
#define Output_Pins_PRTDSI__OE_SEL1        (* (reg8 *) Output_Pins__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Output_Pins_PRTDSI__OUT_SEL0       (* (reg8 *) Output_Pins__PRTDSI__OUT_SEL0) 
#define Output_Pins_PRTDSI__OUT_SEL1       (* (reg8 *) Output_Pins__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Output_Pins_PRTDSI__SYNC_OUT       (* (reg8 *) Output_Pins__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Output_Pins__SIO_CFG)
    #define Output_Pins_SIO_HYST_EN        (* (reg8 *) Output_Pins__SIO_HYST_EN)
    #define Output_Pins_SIO_REG_HIFREQ     (* (reg8 *) Output_Pins__SIO_REG_HIFREQ)
    #define Output_Pins_SIO_CFG            (* (reg8 *) Output_Pins__SIO_CFG)
    #define Output_Pins_SIO_DIFF           (* (reg8 *) Output_Pins__SIO_DIFF)
#endif /* (Output_Pins__SIO_CFG) */

/* Interrupt Registers */
#if defined(Output_Pins__INTSTAT)
    #define Output_Pins_INTSTAT            (* (reg8 *) Output_Pins__INTSTAT)
    #define Output_Pins_SNAP               (* (reg8 *) Output_Pins__SNAP)
    
	#define Output_Pins_0_INTTYPE_REG 		(* (reg8 *) Output_Pins__0__INTTYPE)
	#define Output_Pins_1_INTTYPE_REG 		(* (reg8 *) Output_Pins__1__INTTYPE)
	#define Output_Pins_2_INTTYPE_REG 		(* (reg8 *) Output_Pins__2__INTTYPE)
	#define Output_Pins_3_INTTYPE_REG 		(* (reg8 *) Output_Pins__3__INTTYPE)
#endif /* (Output_Pins__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Output_Pins_H */


/* [] END OF FILE */
