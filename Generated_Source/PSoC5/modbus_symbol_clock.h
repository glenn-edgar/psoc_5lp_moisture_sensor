/*******************************************************************************
* File Name: modbus_symbol_clock.h
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

#if !defined(CY_CLOCK_modbus_symbol_clock_H)
#define CY_CLOCK_modbus_symbol_clock_H

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

void modbus_symbol_clock_Start(void) ;
void modbus_symbol_clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void modbus_symbol_clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void modbus_symbol_clock_StandbyPower(uint8 state) ;
void modbus_symbol_clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 modbus_symbol_clock_GetDividerRegister(void) ;
void modbus_symbol_clock_SetModeRegister(uint8 modeBitMask) ;
void modbus_symbol_clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 modbus_symbol_clock_GetModeRegister(void) ;
void modbus_symbol_clock_SetSourceRegister(uint8 clkSource) ;
uint8 modbus_symbol_clock_GetSourceRegister(void) ;
#if defined(modbus_symbol_clock__CFG3)
void modbus_symbol_clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 modbus_symbol_clock_GetPhaseRegister(void) ;
#endif /* defined(modbus_symbol_clock__CFG3) */

#define modbus_symbol_clock_Enable()                       modbus_symbol_clock_Start()
#define modbus_symbol_clock_Disable()                      modbus_symbol_clock_Stop()
#define modbus_symbol_clock_SetDivider(clkDivider)         modbus_symbol_clock_SetDividerRegister(clkDivider, 1u)
#define modbus_symbol_clock_SetDividerValue(clkDivider)    modbus_symbol_clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define modbus_symbol_clock_SetMode(clkMode)               modbus_symbol_clock_SetModeRegister(clkMode)
#define modbus_symbol_clock_SetSource(clkSource)           modbus_symbol_clock_SetSourceRegister(clkSource)
#if defined(modbus_symbol_clock__CFG3)
#define modbus_symbol_clock_SetPhase(clkPhase)             modbus_symbol_clock_SetPhaseRegister(clkPhase)
#define modbus_symbol_clock_SetPhaseValue(clkPhase)        modbus_symbol_clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(modbus_symbol_clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define modbus_symbol_clock_CLKEN              (* (reg8 *) modbus_symbol_clock__PM_ACT_CFG)
#define modbus_symbol_clock_CLKEN_PTR          ((reg8 *) modbus_symbol_clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define modbus_symbol_clock_CLKSTBY            (* (reg8 *) modbus_symbol_clock__PM_STBY_CFG)
#define modbus_symbol_clock_CLKSTBY_PTR        ((reg8 *) modbus_symbol_clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define modbus_symbol_clock_DIV_LSB            (* (reg8 *) modbus_symbol_clock__CFG0)
#define modbus_symbol_clock_DIV_LSB_PTR        ((reg8 *) modbus_symbol_clock__CFG0)
#define modbus_symbol_clock_DIV_PTR            ((reg16 *) modbus_symbol_clock__CFG0)

/* Clock MSB divider configuration register. */
#define modbus_symbol_clock_DIV_MSB            (* (reg8 *) modbus_symbol_clock__CFG1)
#define modbus_symbol_clock_DIV_MSB_PTR        ((reg8 *) modbus_symbol_clock__CFG1)

/* Mode and source configuration register */
#define modbus_symbol_clock_MOD_SRC            (* (reg8 *) modbus_symbol_clock__CFG2)
#define modbus_symbol_clock_MOD_SRC_PTR        ((reg8 *) modbus_symbol_clock__CFG2)

#if defined(modbus_symbol_clock__CFG3)
/* Analog clock phase configuration register */
#define modbus_symbol_clock_PHASE              (* (reg8 *) modbus_symbol_clock__CFG3)
#define modbus_symbol_clock_PHASE_PTR          ((reg8 *) modbus_symbol_clock__CFG3)
#endif /* defined(modbus_symbol_clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define modbus_symbol_clock_CLKEN_MASK         modbus_symbol_clock__PM_ACT_MSK
#define modbus_symbol_clock_CLKSTBY_MASK       modbus_symbol_clock__PM_STBY_MSK

/* CFG2 field masks */
#define modbus_symbol_clock_SRC_SEL_MSK        modbus_symbol_clock__CFG2_SRC_SEL_MASK
#define modbus_symbol_clock_MODE_MASK          (~(modbus_symbol_clock_SRC_SEL_MSK))

#if defined(modbus_symbol_clock__CFG3)
/* CFG3 phase mask */
#define modbus_symbol_clock_PHASE_MASK         modbus_symbol_clock__CFG3_PHASE_DLY_MASK
#endif /* defined(modbus_symbol_clock__CFG3) */

#endif /* CY_CLOCK_modbus_symbol_clock_H */


/* [] END OF FILE */
