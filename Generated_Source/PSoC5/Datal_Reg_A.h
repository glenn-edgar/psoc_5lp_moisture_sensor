/*******************************************************************************
* File Name: Datal_Reg_A.h  
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

#if !defined(CY_CONTROL_REG_Datal_Reg_A_H) /* CY_CONTROL_REG_Datal_Reg_A_H */
#define CY_CONTROL_REG_Datal_Reg_A_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} Datal_Reg_A_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    Datal_Reg_A_Write(uint8 control) ;
uint8   Datal_Reg_A_Read(void) ;

void Datal_Reg_A_SaveConfig(void) ;
void Datal_Reg_A_RestoreConfig(void) ;
void Datal_Reg_A_Sleep(void) ; 
void Datal_Reg_A_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Datal_Reg_A_Control        (* (reg8 *) Datal_Reg_A_Sync_ctrl_reg__CONTROL_REG )
#define Datal_Reg_A_Control_PTR    (  (reg8 *) Datal_Reg_A_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Datal_Reg_A_H */


/* [] END OF FILE */
