#ifndef TRIGGER_H
#define TRIGGER_H

#include "setup.h"
#include "unit.h"

struct Counter {
    uint value;
    bool flag;
};

typedef struct Counter Counter;

void warn_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void notify_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void alarm_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);

void counter_update(time_t *ntime, time_t *ltime, Counter *counter);

#endif
