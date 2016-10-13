/*******************************************************************************
* File Name: SIGMA_A_D_INT.c
* Version 3.20
*
* Description:
*  This file contains the code that operates during the ADC_DelSig interrupt
*  service routine.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SIGMA_A_D.h"
#include "cyapicallbacks.h"


/*******************************************************************************
* Custom Declarations and Variables
* - add user include files, prototypes and variables between the following
*   #START and #END tags
*******************************************************************************/
/* `#START ADC_SYS_VAR`  */

/* `#END`  */

#if(SIGMA_A_D_IRQ_REMOVE == 0u)


    /*****************************************************************************
    * Function Name: SIGMA_A_D_ISR1
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( SIGMA_A_D_ISR1)
    {
        #ifdef SIGMA_A_D_ISR1_ENTRY_CALLBACK
            SIGMA_A_D_ISR1_EntryCallback();
        #endif /* SIGMA_A_D_ISR1_ENTRY_CALLBACK */
        

        /**************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR1`  */

        /* `#END`  */
        
        /* Stop the conversion if conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(SIGMA_A_D_CFG1_RESOLUTION > 16 && \
            SIGMA_A_D_CFG1_CONV_MODE == SIGMA_A_D_MODE_SINGLE_SAMPLE)
            SIGMA_A_D_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            SIGMA_A_D_convDone = SIGMA_A_D_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef SIGMA_A_D_ISR1_EXIT_CALLBACK
            SIGMA_A_D_ISR1_ExitCallback();
        #endif /* SIGMA_A_D_ISR1_EXIT_CALLBACK */
    }


    /*****************************************************************************
    * Function Name: SIGMA_A_D_ISR2
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( SIGMA_A_D_ISR2)
    {
        #ifdef SIGMA_A_D_ISR2_ENTRY_CALLBACK
            SIGMA_A_D_ISR2_EntryCallback();
        #endif /* SIGMA_A_D_ISR2_ENTRY_CALLBACK */
        
        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR2`  */

        /* `#END`  */

        /* Stop the conversion conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(SIGMA_A_D_CFG2_RESOLUTION > 16 && \
            SIGMA_A_D_CFG2_CONVMODE == SIGMA_A_D_MODE_SINGLE_SAMPLE)
            SIGMA_A_D_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *   resolution is above 16 bits and conversion mode is single sample 
			*/
            SIGMA_A_D_convDone = SIGMA_A_D_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef SIGMA_A_D_ISR2_EXIT_CALLBACK
            SIGMA_A_D_ISR2_ExitCallback();
        #endif /* SIGMA_A_D_ISR2_EXIT_CALLBACK */
    }


    /*****************************************************************************
    * Function Name: SIGMA_A_D_ISR3
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( SIGMA_A_D_ISR3)
    {
        #ifdef SIGMA_A_D_ISR3_ENTRY_CALLBACK
            SIGMA_A_D_ISR3_EntryCallback();
        #endif /* SIGMA_A_D_ISR3_ENTRY_CALLBACK */        

        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR3`  */

        /* `#END`  */
        
        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(SIGMA_A_D_CFG3_RESOLUTION > 16 && \
            SIGMA_A_D_CFG3_CONVMODE == SIGMA_A_D_MODE_SINGLE_SAMPLE)
            SIGMA_A_D_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            SIGMA_A_D_convDone = SIGMA_A_D_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

        #ifdef SIGMA_A_D_ISR3_EXIT_CALLBACK
            SIGMA_A_D_ISR3_ExitCallback();
        #endif /* SIGMA_A_D_ISR3_EXIT_CALLBACK */        
    }


    /*****************************************************************************
    * Function Name: SIGMA_A_D_ISR4
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( SIGMA_A_D_ISR4)
    {
        #ifdef SIGMA_A_D_ISR4_ENTRY_CALLBACK
            SIGMA_A_D_ISR4_EntryCallback();
        #endif /* SIGMA_A_D_ISR4_ENTRY_CALLBACK */            

        
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR4`  */

        /* `#END`  */

        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(SIGMA_A_D_CFG4_RESOLUTION > 16 && \
            SIGMA_A_D_CFG4_CONVMODE == SIGMA_A_D_MODE_SINGLE_SAMPLE)
            SIGMA_A_D_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            SIGMA_A_D_convDone = SIGMA_A_D_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */
        
        #ifdef SIGMA_A_D_ISR4_EXIT_CALLBACK
            SIGMA_A_D_ISR4_ExitCallback();
        #endif /* SIGMA_A_D_ISR4_EXIT_CALLBACK */            
    }

#endif   /* End SIGMA_A_D_IRQ_REMOVE */


/* [] END OF FILE */
