#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>
#include <time.h>

#include "setup.h"
#include "inform.h"
#include "sysinfo.h"

#define FIVE_MIN 300

struct Counter {
    int value;
    bool flag;
};

void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter);

#endif
