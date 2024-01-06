#ifndef BUTTON_h
#define BUTTON_h

#include <gpiod.h>
#include "../include/unit.h"

typedef struct {
    struct gpiod_line *call;
    uint sleep;
} Button;

Button* buttons_gen();
short buttons_update(const uint *counter);
bool  run_program();
void  buttons_free();

#endif
