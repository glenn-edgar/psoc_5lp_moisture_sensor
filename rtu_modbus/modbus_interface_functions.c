/*
**
** File: modbus_interface_functions.c
**
**
**
**
*/

#include "modbus_interface_functions.h"
uint8  RTC_1_ReadSecond(void)                     ;
uint8  RTC_1_ReadMinute(void)                     ;
uint8  RTC_1_ReadHour(void)                       ;
uint8  RTC_1_ReadDayOfMonth(void)                 ;
uint8  RTC_1_ReadMonth(void)                      ;
uint16 RTC_1_ReadYear(void)                       ;

/*
**
**  Type 3 modbus messages
**
*/

uint16  mod_access_read_temp( uint8 *buffer )
{
    return 0;
}    
  


uint16 mod_read_current_time( uint8 *buffer )
{
    uint16 *temp_ptr;
    
    
    *buffer++ =  RTC_1_ReadSecond();
    *buffer++ =  RTC_1_ReadMinute();
    *buffer++ =  RTC_1_ReadHour();
    *buffer++ =   RTC_1_ReadMonth();
    temp_ptr =     (uint16 *)buffer;
    *temp_ptr = RTC_1_ReadYear();
    return  6;
}  

uint16  mod_sigma_dc(  uint8 *buffer )
{
    return 4;
}    
uint16  mod_sigma_ac( uint8 *buffer )
{
    return 0;
}

uint16  mod_sar_dc(   uint8 *buffer )
{
    return 0;
}

uint16  mod_sar_ac(   uint8 *buffer )
{
    return 0;

}    
 

/*
**
**  Type 16 messages
**
*/

uint16  mod_store_current_time( uint8 *buffer )
{
    uint16 *temp_ptr;
    
    RTC_1_WriteSecond(*buffer++);   
    RTC_1_WriteMinute(*buffer++);  
    RTC_1_WriteHour( *buffer++ );
    RTC_1_WriteMonth(*buffer++);
    temp_ptr =     (uint16 *)buffer;
    RTC_1_WriteYear( *temp_ptr );

    return 0;
}
