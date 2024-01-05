#ifndef CHIP_h
#define CHIP_h

#include <gpiod.h>
#include "../include/unit.h"

#define GPIO_CHIP_NAME "gpiochip0"

void chip_init(UNIT_CHIP **chip, bool *start);

#endif
