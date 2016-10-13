/*******************************************************************************
* File Name: Control_Reg_C.h  
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

#if !defined(CY_CONTROL_REG_Control_Reg_C_H) /* CY_CONTROL_REG_Control_Reg_C_H */
#define CY_CONTROL_REG_Control_Reg_C_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Control_Reg_C_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Control_Reg_C_Write(uint8 control) ;
uint8   Control_Reg_C_Read(void) ;

void Control_Reg_C_SaveConfig(void) ;
void Control_Reg_C_RestoreConfig(void) ;
void Control_Reg_C_Sleep(void) ; 
void Control_Reg_C_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Control_Reg_C_Control        (* (reg8 *) Control_Reg_C_Sync_ctrl_reg__CONTROL_REG )
#define Control_Reg_C_Control_PTR    (  (reg8 *) Control_Reg_C_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Control_Reg_C_H */


/* [] END OF FILE */
