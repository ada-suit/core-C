#ifndef SETUP_H
#define SETUP_H

#include <gpiod.h>

#define GPIO_CHIP_NAME "gpiochip0"

int chip_init(struct gpiod_chip **chip);
int line_init(struct gpiod_line **line, struct gpiod_chip *chip, char *label, int pin, char mode);

#endif // SETUP_H
