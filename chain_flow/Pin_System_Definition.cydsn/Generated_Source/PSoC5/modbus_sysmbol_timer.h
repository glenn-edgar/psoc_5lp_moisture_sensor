/*******************************************************************************
* File Name: modbus_sysmbol_timer.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_modbus_sysmbol_timer_H)
#define CY_ISR_modbus_sysmbol_timer_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void modbus_sysmbol_timer_Start(void);
void modbus_sysmbol_timer_StartEx(cyisraddress address);
void modbus_sysmbol_timer_Stop(void);

CY_ISR_PROTO(modbus_sysmbol_timer_Interrupt);

void modbus_sysmbol_timer_SetVector(cyisraddress address);
cyisraddress modbus_sysmbol_timer_GetVector(void);

void modbus_sysmbol_timer_SetPriority(uint8 priority);
uint8 modbus_sysmbol_timer_GetPriority(void);

void modbus_sysmbol_timer_Enable(void);
uint8 modbus_sysmbol_timer_GetState(void);
void modbus_sysmbol_timer_Disable(void);

void modbus_sysmbol_timer_SetPending(void);
void modbus_sysmbol_timer_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the modbus_sysmbol_timer ISR. */
#define modbus_sysmbol_timer_INTC_VECTOR            ((reg32 *) modbus_sysmbol_timer__INTC_VECT)

/* Address of the modbus_sysmbol_timer ISR priority. */
#define modbus_sysmbol_timer_INTC_PRIOR             ((reg8 *) modbus_sysmbol_timer__INTC_PRIOR_REG)

/* Priority of the modbus_sysmbol_timer interrupt. */
#define modbus_sysmbol_timer_INTC_PRIOR_NUMBER      modbus_sysmbol_timer__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable modbus_sysmbol_timer interrupt. */
#define modbus_sysmbol_timer_INTC_SET_EN            ((reg32 *) modbus_sysmbol_timer__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the modbus_sysmbol_timer interrupt. */
#define modbus_sysmbol_timer_INTC_CLR_EN            ((reg32 *) modbus_sysmbol_timer__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the modbus_sysmbol_timer interrupt state to pending. */
#define modbus_sysmbol_timer_INTC_SET_PD            ((reg32 *) modbus_sysmbol_timer__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the modbus_sysmbol_timer interrupt. */
#define modbus_sysmbol_timer_INTC_CLR_PD            ((reg32 *) modbus_sysmbol_timer__INTC_CLR_PD_REG)


#endif /* CY_ISR_modbus_sysmbol_timer_H */


/* [] END OF FILE */
