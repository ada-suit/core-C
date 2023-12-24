#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>
#include <time.h>

#include "setup.h"
#include "inform.h"
#include "sysinfo.h"

void counter_update(int *value, time_t *start_time, time_t *current_time);

#endif
