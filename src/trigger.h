#ifndef TRIGGER_H
#define TRIGGER_H

#include "unit.h"

typedef struct {
    uint value;
    bool flag;
} Counter;

void warn_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void notify_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void alarm_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);

void counter_update(time_t *ntime, time_t *ltime, Counter *counter);

#endif
