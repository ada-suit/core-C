#include <gpiod.h>
#include <time.h>
#include "trigger.h"

void warn_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter)
{
    //
}

void notify_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter)
{
    //
}

void alarm_indicate(struct gpiod_line *buzzer, struct gpiod_line *led, uint *counter)
{
    //
}

// increment counter with time (seconds)
void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter) 
{
    time(ntime);

    if (*ntime == *ltime) {
        counter->flag = 0;
    } else {
        *ltime = *ntime;
        counter->value++;
        counter->flag = 1;
    }
}

