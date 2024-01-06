#ifndef TRIGGER_H
#define TRIGGER_H

#include "unit.h"

void call_action(short status, bool *shift, const uint *count);
void auto_action(const uint *counter);

void warn_indicate(uint *counter);
void notify_indicate(uint *counter);
void alarm_indicate(uint *counter);

bool  keep_running();
void counter_update(uint *counter);

#endif
