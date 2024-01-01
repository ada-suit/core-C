#include <gpiod.h>
#include <time.h>
#include <limits.h>
#include "trigger.h"

void warn_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter)
{
    //
}

void notify_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter)
{
    //
}

void alarm_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, uint *counter)
{
    //
}

// increment counter with time (seconds)
void counter_update(time_t *ntime, time_t *ltime, Counter *counter) 
{
    time(ntime);

    if (*ntime == *ltime) {
        counter->flag = 0;
    } else {
        *ltime = *ntime;
        counter->value++;
        counter->flag = 1;

        if (counter->value == UINT_MAX) {
            counter->value = 0;
        }
    }
}
