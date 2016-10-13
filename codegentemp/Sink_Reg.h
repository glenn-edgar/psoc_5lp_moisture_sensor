/*******************************************************************************
* File Name: Sink_Reg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_Sink_Reg_H) /* CY_CONTROL_REG_Sink_Reg_H */
#define CY_CONTROL_REG_Sink_Reg_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Sink_Reg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Sink_Reg_Write(uint8 control) ;
uint8   Sink_Reg_Read(void) ;

void Sink_Reg_SaveConfig(void) ;
void Sink_Reg_RestoreConfig(void) ;
void Sink_Reg_Sleep(void) ; 
void Sink_Reg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Sink_Reg_Control        (* (reg8 *) Sink_Reg_Sync_ctrl_reg__CONTROL_REG )
#define Sink_Reg_Control_PTR    (  (reg8 *) Sink_Reg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Sink_Reg_H */


/* [] END OF FILE */
