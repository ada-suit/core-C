#ifndef TRIGGER_H
#define TRIGGER_H

#include "unit.h"

void button_action(short status, UNIT_LINE *leds[], bool *shift, const uint count);

void warn_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void notify_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);
void alarm_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter);

void counter_update(uint *counter);

#endif
