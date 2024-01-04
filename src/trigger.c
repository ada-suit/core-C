#include <gpiod.h>
#include <time.h>
#include "trigger.h"
#include "sysinfo.h"

// trigger different actions depending on button pressed
void button_action(short condition, UNIT_LINE *leds[], bool *shift)
{
    condition = (condition * 10) + *shift;
    switch (condition) {
        // ======== toggle shift ======== //
        case 10: // shift off
            *shift = true;
            gpiod_line_set_value(leds[2], 1);
            break;

        case 11: // shift on
            *shift = false;
            gpiod_line_set_value(leds[2], 0);
            break;
        
        // ========== button 1 ========== //
        case 100: // shift off
            break;

        case 101: // shift on
            break;

        // ========== button 2 ========== //
        case 1000: // shift off
            break;

        case 1001: // shift on
            break;

        // ========== button 3 ========== //
        case 1100: // shift off
            break;

        case 1101: // shift on
            break;

        // ========== button 4 ========== //
        case 10000: // shift off
            break;

        case 10001: // shift on
            break;

        // ========== button 5 ========== //
        case 10100: // shift off
            break;

        case 10101: // shift on
            break;

        // ========== button 6 ========== //
        case 11000: // shift off
            break;

        case 11001: // shift on
            break;

        // ========== button 7 ========== //
        case 11100: // shift off
            break;

        case 11101: // shift on
            break;
        
        default:
            break;
    }
}

void warn_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, u_int8_t *counter)
{
    //
}

void notify_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, u_int8_t *counter)
{
    //
}

void alarm_indicate(UNIT_LINE *buzzer, UNIT_LINE *led, u_int8_t *counter)
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

        if (counter->value == 255) {
            counter->value = 0;
        }
    }
}
