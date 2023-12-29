#ifndef BUZZER_h
#define BUZZER_h

#include <gpiod.h>

#define GPIO_CHIP_NAME "gpiochip0"

void chip_init(struct gpiod_chip **chip, bool *start);

#endif
