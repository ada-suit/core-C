#ifndef UNIT_H
#define UNIT_H

#include <gpiod.h>

#define OUTPUT 0
#define INPUT  1

struct Ports {
    char name[8];
    int pin;
};

typedef struct Ports Ports;
typedef struct gpiod_line GPIO_LINE;
typedef struct gpiod_chip GPIO_CHIP;

int line_init(GPIO_LINE **line, GPIO_CHIP *chip, Ports *port, bool mode);

#endif
