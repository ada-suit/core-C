#ifndef TRIGGER_H
#define TRIGGER_H

#include "setup.h"

struct Counter {
    uint value;
    bool flag;
};

void button_value_update(struct Button *buttons, int *count, uint *counter, bool *shift);
void button_state_update(struct Button *buttons, int *count, uint *counter);

void warn_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);
void notify_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);
void alarm_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter);

void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter);

void led_call_off(struct gpiod_line *leds[], int count);

#endif
