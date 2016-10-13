/*******************************************************************************
* File Name: output_register.h  
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

#if !defined(CY_CONTROL_REG_output_register_H) /* CY_CONTROL_REG_output_register_H */
#define CY_CONTROL_REG_output_register_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} output_register_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    output_register_Write(uint8 control) ;
uint8   output_register_Read(void) ;

void output_register_SaveConfig(void) ;
void output_register_RestoreConfig(void) ;
void output_register_Sleep(void) ; 
void output_register_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define output_register_Control        (* (reg8 *) output_register_Sync_ctrl_reg__CONTROL_REG )
#define output_register_Control_PTR    (  (reg8 *) output_register_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_output_register_H */


/* [] END OF FILE */
