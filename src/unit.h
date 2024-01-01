#ifndef UNIT_H
#define UNIT_H

#include <gpiod.h>

#define OUTPUT 0
#define INPUT  1

typedef struct {
    char name[8];
    int pin;
} Port;

typedef struct gpiod_line UNIT_LINE;
typedef struct gpiod_chip UNIT_CHIP;

int line_init(UNIT_LINE **line, UNIT_CHIP *chip, Ports *port, bool mode);

#endif
