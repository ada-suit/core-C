#ifndef CHIP_h
#define CHIP_h

#include <gpiod.h>
#include "../include/unit.h"

#define GPIO_CHIP_NAME "gpiochip0"

UNIT_CHIP* chip_gen();
void chip_free();

#endif
