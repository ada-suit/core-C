#ifndef BUTTON_h
#define BUTTON_h

#include <gpiod.h>

struct Button {
    struct gpiod_line *call;
    uint sleep;
};

int buttons_total();
void buttons_init(struct Button *buttons, struct gpiod_chip *chip, bool *start);
void button_value_update(struct Button *buttons, int *count, uint *counter, bool *shift);
void button_state_update(struct Button *buttons, int *count, uint *counter);
void buttons_free(struct Button *buttons);

#endif
