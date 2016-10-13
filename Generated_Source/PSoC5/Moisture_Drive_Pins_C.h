/*******************************************************************************
* File Name: Moisture_Drive_Pins_C.h  
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

#if !defined(CY_PINS_Moisture_Drive_Pins_C_H) /* Pins Moisture_Drive_Pins_C_H */
#define CY_PINS_Moisture_Drive_Pins_C_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Moisture_Drive_Pins_C_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Moisture_Drive_Pins_C__PORT == 15 && ((Moisture_Drive_Pins_C__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Moisture_Drive_Pins_C_Write(uint8 value);
void    Moisture_Drive_Pins_C_SetDriveMode(uint8 mode);
uint8   Moisture_Drive_Pins_C_ReadDataReg(void);
uint8   Moisture_Drive_Pins_C_Read(void);
void    Moisture_Drive_Pins_C_SetInterruptMode(uint16 position, uint16 mode);
uint8   Moisture_Drive_Pins_C_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Moisture_Drive_Pins_C_SetDriveMode() function.
     *  @{
     */
        #define Moisture_Drive_Pins_C_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Moisture_Drive_Pins_C_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Moisture_Drive_Pins_C_DM_RES_UP          PIN_DM_RES_UP
        #define Moisture_Drive_Pins_C_DM_RES_DWN         PIN_DM_RES_DWN
        #define Moisture_Drive_Pins_C_DM_OD_LO           PIN_DM_OD_LO
        #define Moisture_Drive_Pins_C_DM_OD_HI           PIN_DM_OD_HI
        #define Moisture_Drive_Pins_C_DM_STRONG          PIN_DM_STRONG
        #define Moisture_Drive_Pins_C_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Moisture_Drive_Pins_C_MASK               Moisture_Drive_Pins_C__MASK
#define Moisture_Drive_Pins_C_SHIFT              Moisture_Drive_Pins_C__SHIFT
#define Moisture_Drive_Pins_C_WIDTH              1u

/* Interrupt constants */
#if defined(Moisture_Drive_Pins_C__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Moisture_Drive_Pins_C_SetInterruptMode() function.
     *  @{
     */
        #define Moisture_Drive_Pins_C_INTR_NONE      (uint16)(0x0000u)
        #define Moisture_Drive_Pins_C_INTR_RISING    (uint16)(0x0001u)
        #define Moisture_Drive_Pins_C_INTR_FALLING   (uint16)(0x0002u)
        #define Moisture_Drive_Pins_C_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Moisture_Drive_Pins_C_INTR_MASK      (0x01u) 
#endif /* (Moisture_Drive_Pins_C__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Moisture_Drive_Pins_C_PS                     (* (reg8 *) Moisture_Drive_Pins_C__PS)
/* Data Register */
#define Moisture_Drive_Pins_C_DR                     (* (reg8 *) Moisture_Drive_Pins_C__DR)
/* Port Number */
#define Moisture_Drive_Pins_C_PRT_NUM                (* (reg8 *) Moisture_Drive_Pins_C__PRT) 
/* Connect to Analog Globals */                                                  
#define Moisture_Drive_Pins_C_AG                     (* (reg8 *) Moisture_Drive_Pins_C__AG)                       
/* Analog MUX bux enable */
#define Moisture_Drive_Pins_C_AMUX                   (* (reg8 *) Moisture_Drive_Pins_C__AMUX) 
/* Bidirectional Enable */                                                        
#define Moisture_Drive_Pins_C_BIE                    (* (reg8 *) Moisture_Drive_Pins_C__BIE)
/* Bit-mask for Aliased Register Access */
#define Moisture_Drive_Pins_C_BIT_MASK               (* (reg8 *) Moisture_Drive_Pins_C__BIT_MASK)
/* Bypass Enable */
#define Moisture_Drive_Pins_C_BYP                    (* (reg8 *) Moisture_Drive_Pins_C__BYP)
/* Port wide control signals */                                                   
#define Moisture_Drive_Pins_C_CTL                    (* (reg8 *) Moisture_Drive_Pins_C__CTL)
/* Drive Modes */
#define Moisture_Drive_Pins_C_DM0                    (* (reg8 *) Moisture_Drive_Pins_C__DM0) 
#define Moisture_Drive_Pins_C_DM1                    (* (reg8 *) Moisture_Drive_Pins_C__DM1)
#define Moisture_Drive_Pins_C_DM2                    (* (reg8 *) Moisture_Drive_Pins_C__DM2) 
/* Input Buffer Disable Override */
#define Moisture_Drive_Pins_C_INP_DIS                (* (reg8 *) Moisture_Drive_Pins_C__INP_DIS)
/* LCD Common or Segment Drive */
#define Moisture_Drive_Pins_C_LCD_COM_SEG            (* (reg8 *) Moisture_Drive_Pins_C__LCD_COM_SEG)
/* Enable Segment LCD */
#define Moisture_Drive_Pins_C_LCD_EN                 (* (reg8 *) Moisture_Drive_Pins_C__LCD_EN)
/* Slew Rate Control */
#define Moisture_Drive_Pins_C_SLW                    (* (reg8 *) Moisture_Drive_Pins_C__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Moisture_Drive_Pins_C_PRTDSI__CAPS_SEL       (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Moisture_Drive_Pins_C_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Moisture_Drive_Pins_C_PRTDSI__OE_SEL0        (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__OE_SEL0) 
#define Moisture_Drive_Pins_C_PRTDSI__OE_SEL1        (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Moisture_Drive_Pins_C_PRTDSI__OUT_SEL0       (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__OUT_SEL0) 
#define Moisture_Drive_Pins_C_PRTDSI__OUT_SEL1       (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Moisture_Drive_Pins_C_PRTDSI__SYNC_OUT       (* (reg8 *) Moisture_Drive_Pins_C__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Moisture_Drive_Pins_C__SIO_CFG)
    #define Moisture_Drive_Pins_C_SIO_HYST_EN        (* (reg8 *) Moisture_Drive_Pins_C__SIO_HYST_EN)
    #define Moisture_Drive_Pins_C_SIO_REG_HIFREQ     (* (reg8 *) Moisture_Drive_Pins_C__SIO_REG_HIFREQ)
    #define Moisture_Drive_Pins_C_SIO_CFG            (* (reg8 *) Moisture_Drive_Pins_C__SIO_CFG)
    #define Moisture_Drive_Pins_C_SIO_DIFF           (* (reg8 *) Moisture_Drive_Pins_C__SIO_DIFF)
#endif /* (Moisture_Drive_Pins_C__SIO_CFG) */

/* Interrupt Registers */
#if defined(Moisture_Drive_Pins_C__INTSTAT)
    #define Moisture_Drive_Pins_C_INTSTAT            (* (reg8 *) Moisture_Drive_Pins_C__INTSTAT)
    #define Moisture_Drive_Pins_C_SNAP               (* (reg8 *) Moisture_Drive_Pins_C__SNAP)
    
	#define Moisture_Drive_Pins_C_0_INTTYPE_REG 		(* (reg8 *) Moisture_Drive_Pins_C__0__INTTYPE)
#endif /* (Moisture_Drive_Pins_C__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Moisture_Drive_Pins_C_H */


/* [] END OF FILE */
