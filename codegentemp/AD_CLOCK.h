/*******************************************************************************
* File Name: AD_CLOCK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_AD_CLOCK_H)
#define CY_CLOCK_AD_CLOCK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void AD_CLOCK_Start(void) ;
void AD_CLOCK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void AD_CLOCK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void AD_CLOCK_StandbyPower(uint8 state) ;
void AD_CLOCK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 AD_CLOCK_GetDividerRegister(void) ;
void AD_CLOCK_SetModeRegister(uint8 modeBitMask) ;
void AD_CLOCK_ClearModeRegister(uint8 modeBitMask) ;
uint8 AD_CLOCK_GetModeRegister(void) ;
void AD_CLOCK_SetSourceRegister(uint8 clkSource) ;
uint8 AD_CLOCK_GetSourceRegister(void) ;
#if defined(AD_CLOCK__CFG3)
void AD_CLOCK_SetPhaseRegister(uint8 clkPhase) ;
uint8 AD_CLOCK_GetPhaseRegister(void) ;
#endif /* defined(AD_CLOCK__CFG3) */

#define AD_CLOCK_Enable()                       AD_CLOCK_Start()
#define AD_CLOCK_Disable()                      AD_CLOCK_Stop()
#define AD_CLOCK_SetDivider(clkDivider)         AD_CLOCK_SetDividerRegister(clkDivider, 1u)
#define AD_CLOCK_SetDividerValue(clkDivider)    AD_CLOCK_SetDividerRegister((clkDivider) - 1u, 1u)
#define AD_CLOCK_SetMode(clkMode)               AD_CLOCK_SetModeRegister(clkMode)
#define AD_CLOCK_SetSource(clkSource)           AD_CLOCK_SetSourceRegister(clkSource)
#if defined(AD_CLOCK__CFG3)
#define AD_CLOCK_SetPhase(clkPhase)             AD_CLOCK_SetPhaseRegister(clkPhase)
#define AD_CLOCK_SetPhaseValue(clkPhase)        AD_CLOCK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(AD_CLOCK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define AD_CLOCK_CLKEN              (* (reg8 *) AD_CLOCK__PM_ACT_CFG)
#define AD_CLOCK_CLKEN_PTR          ((reg8 *) AD_CLOCK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define AD_CLOCK_CLKSTBY            (* (reg8 *) AD_CLOCK__PM_STBY_CFG)
#define AD_CLOCK_CLKSTBY_PTR        ((reg8 *) AD_CLOCK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define AD_CLOCK_DIV_LSB            (* (reg8 *) AD_CLOCK__CFG0)
#define AD_CLOCK_DIV_LSB_PTR        ((reg8 *) AD_CLOCK__CFG0)
#define AD_CLOCK_DIV_PTR            ((reg16 *) AD_CLOCK__CFG0)

/* Clock MSB divider configuration register. */
#define AD_CLOCK_DIV_MSB            (* (reg8 *) AD_CLOCK__CFG1)
#define AD_CLOCK_DIV_MSB_PTR        ((reg8 *) AD_CLOCK__CFG1)

/* Mode and source configuration register */
#define AD_CLOCK_MOD_SRC            (* (reg8 *) AD_CLOCK__CFG2)
#define AD_CLOCK_MOD_SRC_PTR        ((reg8 *) AD_CLOCK__CFG2)

#if defined(AD_CLOCK__CFG3)
/* Analog clock phase configuration register */
#define AD_CLOCK_PHASE              (* (reg8 *) AD_CLOCK__CFG3)
#define AD_CLOCK_PHASE_PTR          ((reg8 *) AD_CLOCK__CFG3)
#endif /* defined(AD_CLOCK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define AD_CLOCK_CLKEN_MASK         AD_CLOCK__PM_ACT_MSK
#define AD_CLOCK_CLKSTBY_MASK       AD_CLOCK__PM_STBY_MSK

/* CFG2 field masks */
#define AD_CLOCK_SRC_SEL_MSK        AD_CLOCK__CFG2_SRC_SEL_MASK
#define AD_CLOCK_MODE_MASK          (~(AD_CLOCK_SRC_SEL_MSK))

#if defined(AD_CLOCK__CFG3)
/* CFG3 phase mask */
#define AD_CLOCK_PHASE_MASK         AD_CLOCK__CFG3_PHASE_DLY_MASK
#endif /* defined(AD_CLOCK__CFG3) */

#endif /* CY_CLOCK_AD_CLOCK_H */


/* [] END OF FILE */
