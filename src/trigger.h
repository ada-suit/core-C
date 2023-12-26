#ifndef TRIGGER_H
#define TRIGGER_H

#include <gpiod.h>
#include <stdio.h>
#include <time.h>

#include "setup.h"

struct Counter {
    int value;
    bool flag;
};

void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter);

#endif
