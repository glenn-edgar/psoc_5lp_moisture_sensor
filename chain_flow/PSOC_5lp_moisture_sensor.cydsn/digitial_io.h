/*
**
**
** File: digitial_io.h
**
**
**
**
**
**
*/

#ifndef DIGITIAL_IO_H
#define DIGITIAL_IO_H

#include <device.h>
    
uint32 read_board_switch( void );
uint32 read_log_pin( void );
uint32 read_active_pin( void );

#endif    
