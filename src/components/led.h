#ifndef LED_h
#define LED_h

#include <gpiod.h>
#include "../unit.h"

int  leds_total();
void leds_init(UNIT_LINE *leds[], UNIT_CHIP *chip, bool *start);
void leds_free(UNIT_LINE *leds[]);

#endif
