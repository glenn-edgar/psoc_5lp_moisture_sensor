/*
**
** File: moving_average.h
**
**
**
*/

#ifndef _MOVING_AVERAGE_H_
#define _MOVING_AVERAGE_H_
#include <device.h>
typedef struct
{
   float alpha;
   float minus_alpha;
   float average;
}MOVING_AVERAGE_STRUCT;

void ma_initialize( MOVING_AVERAGE_STRUCT *ma, float alpha);
int32 ma_update( MOVING_AVERAGE_STRUCT *moving_average, int32 new_sample);
int32 ma_get_value( MOVING_AVERAGE_STRUCT *moving_average );

#endif

