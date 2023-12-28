#ifndef SETUP_H
#define SETUP_H

#include <gpiod.h>

#define GPIO_CHIP_NAME "gpiochip0"
#define OUTPUT 0
#define INPUT  1

struct Ports {
    char name[8];
    int pin;
};

struct Button {
    struct gpiod_line *call;
    uint sleep;
};

int component_total(int index);
void chip_init(struct gpiod_chip **chip, bool *start);
void leds_init(struct gpiod_line *leds[], struct gpiod_chip *chip, bool *start);
void buttons_init(struct Button *buttons, struct gpiod_chip *chip, bool *start);
void buzzers_init(struct gpiod_line *buzzers[], struct gpiod_chip *chip, bool *start);
void clean_resources(struct gpiod_line *leds[], struct Button *buttons, struct gpiod_line *buzzers[]);

#endif
