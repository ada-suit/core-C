#ifndef BUZZER_h
#define BUZZER_h

#include "../include/unit.h"

Unit* buzzers_gen();
void  buzzers_update(const uint *counter);
void  buzzers_free();

#endif
