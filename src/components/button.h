#ifndef BUTTON_h
#define BUTTON_h

#include <gpiod.h>
#include "../unit.h"

struct Button {
    struct gpiod_line *call;
    uint sleep;
};

typedef struct Button Button;

int buttons_total();
void buttons_init(Button *buttons, UNIT_CHIP *chip, bool *start);
void buttons_update(Button *buttons, int *count, uint *counter, bool *shift);
void buttons_free(Button *buttons);

#endif
