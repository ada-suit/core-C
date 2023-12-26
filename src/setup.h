#ifndef SETUP_H
#define SETUP_H

#include <gpiod.h>
#include <stdio.h>

#define GPIO_CHIP_NAME "gpiochip0"
#define OUTPUT 0
#define INPUT  1

struct Ports {
    char name[8];
    int pin;
};

struct Button {
    struct gpiod_line *call;
    bool sleep;
};

int component_total(int index);
int chip_init(struct gpiod_chip **chip);
int leds_init(struct gpiod_line *leds[], struct gpiod_chip *chip);
int buttons_init(struct Button *buttons, struct gpiod_chip *chip);
int buzzers_init(struct gpiod_line *buzzers[], struct gpiod_chip *chip);
void clean_resources(struct gpiod_line *leds[], struct Button *buttons, struct gpiod_line *buzzers[]);

#endif
