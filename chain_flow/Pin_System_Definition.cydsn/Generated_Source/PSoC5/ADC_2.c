/*******************************************************************************
* File Name: ADC_2.c
* Version 2.0
*
* Description:
*  This file provides the API functionality of the ADC SAR Sequencer Component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_2.h"
#if(ADC_2_IRQ_REMOVE == 0u)
    #include "ADC_2_IRQ.h"
#endif   /* End ADC_2_IRQ_REMOVE */

int16  ADC_2_finalArray[ADC_2_NUMBER_OF_CHANNELS];
uint32 ADC_2_initVar = 0u;
static uint8 ADC_2_tempChan;
static uint8 ADC_2_finalChan;
static uint8 ADC_2_tempTD = CY_DMA_INVALID_TD;
static uint8 ADC_2_finalTD = CY_DMA_INVALID_TD;


/****************************************************************************
* Function Name: ADC_2_Disable()
*****************************************************************************
*
* Summary:
*  Disables the component without disabling the ADC SAR.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
****************************************************************************/
void ADC_2_Disable(void)
{
    ADC_2_CONTROL_REG &= ((uint8)(~ADC_2_BASE_COMPONENT_ENABLE));

    (void) CyDmaChDisable(ADC_2_tempChan);
    CyDmaTdFree(ADC_2_tempTD);
    ADC_2_tempTD = CY_DMA_INVALID_TD;

    (void) CyDmaChDisable(ADC_2_finalChan);
    CyDmaTdFree(ADC_2_finalTD);
    ADC_2_finalTD = CY_DMA_INVALID_TD;
}


/*******************************************************************************
* Function Name: ADC_2_Init
********************************************************************************
*
* Summary:
*  Inits channels for DMA transfer. Provides loading period to the AMUX address
*  selection counter
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_Init(void)
{
    /* Init DMA, 2 bytes bursts, each burst requires a request */
    ADC_2_tempChan = ADC_2_TempBuf_DmaInitialize(ADC_2_TEMP_BYTES_PER_BURST,
        ADC_2_REQUEST_PER_BURST, (uint16)(HI16(CYDEV_PERIPH_BASE)), (uint16)(HI16(CYDEV_SRAM_BASE)));

    /* Init DMA, (ADC_2_NUMBER_OF_CHANNELS << 1u) bytes bursts, each burst requires a request */
    ADC_2_finalChan = ADC_2_FinalBuf_DmaInitialize((uint8)ADC_2_FINAL_BYTES_PER_BURST,
        ADC_2_REQUEST_PER_BURST, (uint16)(HI16(CYDEV_SRAM_BASE)), (uint16)(HI16(CYDEV_SRAM_BASE)));

    #if(ADC_2_IRQ_REMOVE == 0u)
        /* Set the ISR to point to the ADC_2_IRQ Interrupt. */
        ADC_2_IRQ_SetVector(&ADC_2_ISR);
        /* Set the priority. */
        ADC_2_IRQ_SetPriority((uint8)ADC_2_INTC_NUMBER);
    #endif   /* End ADC_2_IRQ_REMOVE */

}


/*******************************************************************************
* Function Name: ADC_2_Enable
********************************************************************************
*
* Summary:
*  Enables DMA channels, address selection counter and FSM of Base component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_Enable(void)
{
    uint8 enableInterrupts;

    static int16 ADC_2_tempArray[ADC_2_NUMBER_OF_CHANNELS];
    
    (void)CyDmaClearPendingDrq(ADC_2_tempChan);
    (void)CyDmaClearPendingDrq(ADC_2_finalChan);
    
    
    /* Provides initialization procedure for the TempBuf DMA
    * Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the destination address, but not the source address
    */

    if (ADC_2_tempTD == DMA_INVALID_TD)
    {
        ADC_2_tempTD = CyDmaTdAllocate();
    }

    (void) CyDmaTdSetConfiguration(ADC_2_tempTD, ADC_2_TEMP_TRANSFER_COUNT,
        ADC_2_tempTD, ((uint8)ADC_2_TempBuf__TD_TERMOUT_EN | (uint8)TD_INC_DST_ADR));

    /* From the SAR to the TempArray */
    (void) CyDmaTdSetAddress(ADC_2_tempTD, (uint16)(LO16((uint32)ADC_2_SAR_DATA_ADDR_0)),
        (uint16)(LO16((uint32)ADC_2_tempArray)));

    /* Associate the TD with the channel */
    (void) CyDmaChSetInitialTd(ADC_2_tempChan, ADC_2_tempTD);


    /* Provides initialization procedure for the FinalBuf DMA
    * Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the source and destination address
    */

    if (ADC_2_finalTD == DMA_INVALID_TD)
    {
        ADC_2_finalTD = CyDmaTdAllocate();
    }
    
    (void) CyDmaTdSetConfiguration(ADC_2_finalTD, (ADC_2_FINAL_BYTES_PER_BURST),
        ADC_2_finalTD, ((uint8)(ADC_2_FinalBuf__TD_TERMOUT_EN) | (uint8)TD_INC_SRC_ADR |
            (uint8)TD_INC_DST_ADR));

    /* From the the TempArray to Final Array */
    (void) CyDmaTdSetAddress(ADC_2_finalTD, (uint16)(LO16((uint32)ADC_2_tempArray)),
        (uint16)(LO16((uint32)ADC_2_finalArray)));

    /* Associate the TD with the channel */
    (void) CyDmaChSetInitialTd(ADC_2_finalChan, ADC_2_finalTD);
    
    (void) CyDmaChEnable(ADC_2_tempChan, 1u);
    (void) CyDmaChEnable(ADC_2_finalChan, 1u);

    /* Enable Counter and give Enable pulse to set an address of the last channel */
    enableInterrupts = CyEnterCriticalSection();
    ADC_2_CYCLE_COUNTER_AUX_CONTROL_REG |= ((uint8)(ADC_2_CYCLE_COUNTER_ENABLE));
    CyExitCriticalSection(enableInterrupts);

    /* Enable FSM of the Base Component */
    ADC_2_CONTROL_REG |= ((uint8)(ADC_2_BASE_COMPONENT_ENABLE));
    ADC_2_CONTROL_REG |= ((uint8)(ADC_2_LOAD_COUNTER_PERIOD));

    #if(ADC_2_IRQ_REMOVE == 0u)
        /* Clear a pending interrupt */
        CyIntClearPending(ADC_2_INTC_NUMBER);
    #endif   /* End ADC_2_IRQ_REMOVE */
}


/*******************************************************************************
* Function Name: ADC_2_Start
********************************************************************************
*
* Summary:
*  Starts component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  If the initVar variable is already set, this function only calls the 
*  ADC_2_Enable() function
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_Start(void)
{
    if(ADC_2_initVar == 0u)
    {
        ADC_2_Init();
        ADC_2_initVar = 1u;
    }

    ADC_2_Enable();
    ADC_2_SAR_Start();
    (void) CY_GET_REG8(ADC_2_STATUS_PTR);

}


/*******************************************************************************
* Function Name: ADC_2_Stop
********************************************************************************
*
* Summary:
*  Stops component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_Stop(void)
{
    ADC_2_SAR_Stop();
    ADC_2_Disable();
}

#if(ADC_2_SAMPLE_MODE != ADC_2_SAMPLE_MODE_HW_TRIGGERED)

    /*******************************************************************************
    * Function Name: ADC_2_StartConvert
    ********************************************************************************
    *
    * Summary:
    *  When the Sample Mode parameter is set to 'Free Running', the component will
    * operate in a continuous mode. The channels will be scanned continuously until
    * _StopConvert()or  _Stop() is called
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Calling ADC_2_StartConvert() disables the external SOC pin.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void ADC_2_StartConvert(void)
    {
        #if(ADC_2_SAMPLE_MODE != ADC_2_SAMPLE_MODE_FREE_RUNNING)

            ADC_2_CONTROL_REG |= ((uint8)(ADC_2_SOFTWARE_SOC_PULSE));

        #else

            ADC_2_SAR_StartConvert();

        #endif /*
                 #if(ADC_2_SAMPLE_MODE !=
                 ADC_2_SAMPLE_MODE_FREE_RUNNING)
               */
    }


    /*******************************************************************************
    * Function Name: ADC_2_StopConvert
    ********************************************************************************
    *
    * Summary:
    *  Forces the component to stop all conversions
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  In free-running and software trigger mode, this function sets a software 
    *  version of the SOC to low level and switches the SOC source to hardware SOC 
    *  input (Hardware trigger).
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void ADC_2_StopConvert(void)
    {
        ADC_2_SAR_StopConvert();
    }

#endif /* ADC_2_SAMPLE_MODE != ADC_2_SAMPLE_MODE_HW_TRIGGERED */


/*******************************************************************************
* Function Name: ADC_2_IsEndConversion
********************************************************************************
*
* Summary:
*  Checks for ADC end of conversion for the case one channel and end of scan
*  for the case of multiple channels
*
* Parameters:
*  retMode: Check conversion return mode
*   Values:
*         - ADC_2_RETURN_STATUS      - Immediately returns the 
*                                                 status
*         - ADC_2_WAIT_FOR_RESULT    - Does not return a result 
*                                                 until the conversion 
*                                                 is complete
*
* Return:
*  If a nonzero value is returned, the last conversion is complete. If the 
*  returned value is zero, the ADC_SAR_Seq is still calculating the last result
*
* Side Effects:
*  This function reads the end of conversion status, which is cleared on read
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint32 ADC_2_IsEndConversion(uint8 retMode)
{
    uint8 status;

    do
    {
      status = ADC_2_STATUS_REG;
    } while ((status == 0u) && (retMode == ADC_2_WAIT_FOR_RESULT));

    return((uint32)status);
}


/*******************************************************************************
* Function Name: ADC_2_GetResult16
********************************************************************************
*
* Summary:
*  Returns the ADC result for channel chan
*
* Parameters:
*  chan: The ADC channel in which to return the result. The first channel is 0 
*        and the last channel is the total number of channels - 1
*
* Return:
*  Returns converted data as a signed 16-bit integer
*
* Side Effects:
*  Converts the ADC counts to the 2's complement form
*
* Reentrant:
*  No.
*
*******************************************************************************/
int16 ADC_2_GetResult16(uint16 chan)
{
    return (ADC_2_finalArray[ADC_2_GET_RESULT_INDEX_OFFSET - chan] - ADC_2_SAR_shift);
}


/*******************************************************************************
* Function Name: ADC_2_GetAdcResult
********************************************************************************
*
* Summary:
*  Gets the data available in the SAR DATA register, not the results buffer
*
* Parameters:
*  None.
*
* Return:
*  The last ADC conversion result
*
* Side Effects:
*  Converts the ADC counts to the 2's complement form
*
* Reentrant:
*  No.
*
*******************************************************************************/
int16 ADC_2_GetAdcResult(void)
{
    return (ADC_2_SAR_GetResult16());
}


/*******************************************************************************
* Function Name: ADC_2_SetOffset
********************************************************************************
*
* Summary:
*  Sets the ADC offset which is used by the functions _CountsTo_uVolts(),
*  _CountsTo_mVolts() and _CountsTo_Volts() to substract the offset from the
*  given reading before calculating the voltage conversion
*
* Parameters:
*  offset: This value is measured when the inputs are shorted or connected to
*  the same input voltage
*
* Return:
*  None.
*
* Side Effects:
*  Affects ADC_2_CountsTo_Volts(), 
*  ADC_2_CountsTo_mVolts(), and ADC_2_CountsTo_uVolts() 
*  by subtracting the given offset.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_SetOffset(int32 offset)
{
    ADC_2_SAR_SetOffset((int16)offset);
}


/*******************************************************************************
* Function Name: ADC_2_SetResolution
********************************************************************************
*
* Summary:
*  Sets the Relution of the SAR.
*  This function does not affect the actual conversion with PSoC5 ES1 silicon.
*
* Parameters:
*  resolution:
*  12 ->    RES12
*  10 ->    RES10
*  8  ->    RES8
*
* Return:
*  None.
*
* Side Effects:
*  The ADC_SAR_Seq resolution cannot be changed during a conversion cycle. The
*  recommended best practice is to stop conversions with
*  ADC_2_StopConvert(), change the resolution, then restart the
*  conversions with ADC_2_StartConvert().
*  If you decide not to stop conversions before calling this API, you
*  should use ADC_2_IsEndConversion() to wait until conversion is 
*  complete  before changing the resolution.
*  If you call ADC_SetResolution() during a conversion, the resolution will
*  not be changed until the current conversion is complete. Data will not be
*  available in the new resolution for another 6 + "New Resolution(in bits)"
*  clock cycles.
*  You may need add a delay of this number of clock cycles after
*  ADC_2_SetResolution() is called before data is valid again.
*  Affects ADC_2_CountsTo_Volts(), ADC_2_CountsTo_mVolts(), 
*  and ADC_2_CountsTo_uVolts() by calculating the correct conversion 
*  between ADC counts and the applied input voltage. Calculation depends on 
*  resolution, input range, and voltage reference.
*
*******************************************************************************/
void ADC_2_SetResolution(uint8 resolution)
{
    ADC_2_SAR_SetResolution(resolution);
}


/*******************************************************************************
* Function Name: ADC_2_SetGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per volt for the voltage conversion
*
* Parameters:
*  adcGain: counts per volt
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_SetGain(int32 adcGain)
{
    ADC_2_SAR_SetGain((int16)adcGain);
}


/*******************************************************************************
* Function Name: ADC_2_SetScaledGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per 10 volts for the voltage conversion functions
*  that follow. This value is set by default by the reference and input range
*  settings. It should only be used to further calibrate the ADC with a known
*  input or if the ADC is using an external reference.
*
* Parameters:
*  int32  adcGain  counts per 10 volt
*
* Return:
*  None.
*
* Side Effects:
*  Affects ADC_2_CountsTo_Volts(), ADC_2_CountsTo_mVolts(),
*  ADC_2_CountsTo_uVolts() by supplying the correct conversion 
*  between ADC counts and the applied input voltage
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_2_SetScaledGain(int32 adcGain)
{
    ADC_2_SAR_SetScaledGain(adcGain);
}


/*******************************************************************************
* Function Name: ADC_2_CountsTo_mVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to mVolts as a 32-bit integer
*
* Parameters:
*  adcCounts: Result from the ADC_SAR_Seq conversion
*
* Return:
*  Result in mV
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
int32 ADC_2_CountsTo_mVolts(int16 adcCounts)
{
    return ((int32) ADC_2_SAR_CountsTo_mVolts(adcCounts));
}


/*******************************************************************************
* Function Name: ADC_2_CountsTo_uVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to uVolts as a 32-bit integer
*
* Parameters:
*  adcCounts: Result from the ADC conversion
*
* Return:
*  Result in uV
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
int32 ADC_2_CountsTo_uVolts(int16 adcCounts)
{
    return (ADC_2_SAR_CountsTo_uVolts(adcCounts));
}


/*******************************************************************************
* Function Name: ADC_2_CountsTo_Volts
********************************************************************************
*
* Summary:
*  Converts the ADC output to Volts as a floating point number
*
* Parameters:
*  adcCounts: Result from the ADC_SAR_Seq conversion
*
* Return:
*  Result in volts
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
float32 ADC_2_CountsTo_Volts(int16 adcCounts)
{
    return (ADC_2_SAR_CountsTo_Volts(adcCounts));
}


/* [] END OF FILE */
