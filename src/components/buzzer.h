#ifndef BUZZER_h
#define BUZZER_h

#include <gpiod.h>

int buzzers_total();
void buzzers_init(struct gpiod_line *buzzers[], struct gpiod_chip *chip, bool *start);
void buzzers_free(struct gpiod_line *buzzers[]);

#endif
