#ifndef BUZZER_h
#define BUZZER_h

#include <gpiod.h>
#include "../include/unit.h"

#define BUZZERS_COUNT 1

void buzzers_init(UNIT_LINE *buzzers[], UNIT_CHIP *chip, bool *start);
void buzzers_free(UNIT_LINE *buzzers[]);

#endif
