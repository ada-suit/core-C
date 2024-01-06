#ifndef LED_h
#define LED_h

#include <gpiod.h>
#include "../include/unit.h"

UNIT_LINE** leds_gen();
//void leds_blink();
void leds_free();

#endif
