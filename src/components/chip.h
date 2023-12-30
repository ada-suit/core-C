#ifndef BUZZER_h
#define BUZZER_h

#include <gpiod.h>
#include "../unit.h"

#define GPIO_CHIP_NAME "gpiochip0"

void chip_init(UNIT_CHIP **chip, bool *start);

#endif
