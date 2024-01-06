#ifndef BUZZER_h
#define BUZZER_h

#include <gpiod.h>
#include "../include/unit.h"

UNIT_LINE** buzzers_gen();
void buzzers_free();

#endif
