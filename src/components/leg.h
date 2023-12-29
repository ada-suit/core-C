#ifndef LED_h
#define LED_h

#include <gpiod.h>

int leds_total();
void leds_init(struct gpiod_line *leds[], struct gpiod_chip *chip, bool *start);
void leds_free(struct gpiod_line *leds[]);

#endif
