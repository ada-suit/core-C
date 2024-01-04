#ifndef BUTTON_h
#define BUTTON_h

#include <gpiod.h>
#include "../unit.h"

#define BUTTONS_COUNT 5

typedef struct {
    struct gpiod_line *call;
    uint sleep;
} Button;

void  buttons_init(Button *buttons, UNIT_CHIP *chip, bool *start);
short buttons_update(Button *buttons, u_int8_t *counter);
void  buttons_free(Button *buttons);

#endif
