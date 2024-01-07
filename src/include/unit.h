#ifndef UNIT_H
#define UNIT_H

#include <gpiod.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "errors.h"

#define OUTPUT 0
#define INPUT  1

typedef struct {
    char name[8];
    int pin;
} Port;

typedef struct {
    struct gpiod_line *call;
    uint sleep;
} Unit;

typedef unsigned int uint;
typedef __uint8_t uintb; // one byte unsigned int
typedef struct gpiod_line UNIT_LINE;
typedef struct gpiod_chip UNIT_CHIP;

int line_init(UNIT_LINE **line, UNIT_CHIP *chip, Port values, const bool mode);

#endif
