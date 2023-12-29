#ifndef COMPONENT_H
#define COMPONENT_H

#include <gpiod.h>

#define OUTPUT 0
#define INPUT  1

struct Ports {
    char name[8];
    int pin;
};

int line_init(struct gpiod_line **line, struct gpiod_chip *chip, struct Ports *port, bool mode);

#endif
