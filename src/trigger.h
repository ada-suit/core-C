#ifndef TRIGGER_H
#define TRIGGER_H

#include "setup.h"

struct Counter {
    uint value;
    bool flag;
};

void warn_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);
void notify_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);
void alarm_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);

void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter);

#endif
