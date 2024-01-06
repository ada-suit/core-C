#ifndef TRIGGER_H
#define TRIGGER_H

#include "unit.h"

void button_action(short status, bool *shift, const uint *count);
void automation(const uint *counter);

void warn_indicate(uint *counter);
void notify_indicate(uint *counter);
void alarm_indicate(uint *counter);

void counter_update(uint *counter);

#endif
