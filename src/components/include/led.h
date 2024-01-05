#ifndef LED_h
#define LED_h

#include <gpiod.h>
#include "../include/unit.h"

#define LEDS_COUNT 3

void leds_init(UNIT_LINE *leds[], UNIT_CHIP *chip, bool *start);
void leds_free(UNIT_LINE *leds[]);

#endif
