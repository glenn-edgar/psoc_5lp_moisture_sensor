/*
** File: modbus_srial_ctrl.c
**
**
*/

#include <device.h>
#include "modbus_serial_ctrl.h"
#include "process_modbus_message.h"





int initialize_modbus_rtu(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    return CF_DISABLE; // TBD Right now
}

int process_rtu_message(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    return CF_TERMINATE; // TBD Right now
}