#include <gpiod.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "include/trigger.h"
#include "include/sysinfo.h"
#include "components/include/led.h"
#include "components/include/buzzer.h"

// trigger different actions depending on button pressed
void button_action(short status, bool *shift, const uint *count)
{
    UNIT_LINE **leds = leds_gen();

    status = (status * 10) + *shift;
    switch (status) {
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
            printf("button 1 shift off\n");
            printf("Counter value = %u\n", *count);
            break;

        case 101: // shift on
            printf("button 1 shift on\n");
            break;

        // ========== button 2 ========== //
        case 1000: // shift off
            printf("button 2 shift off\n");
            break;

        case 1001: // shift on
            printf("button 2 shift on\n");
            break;

        // ========== button 3 ========== //
        case 1100: // shift off
            printf("button 3 shift off\n");
            break;

        case 1101: // shift on
            printf("button 3 shift on\n");
            break;

        // ========== button 4 ========== //
        case 10000: // shift off
            printf("button 4 shift off\n");
            break;

        case 10001: // shift on
            printf("button 4 shift on\n");
            break;

        // ========== button 5 ========== //
        case 10100: // shift off
            printf("button 5 shift off\n");
            break;

        case 10101: // shift on
            printf("button 5 shift on\n");
            break;

        // ========== button 6 ========== //
        case 11000: // shift off
            printf("button 6 shift off\n");
            break;

        case 11001: // shift on
            printf("button 6 shift on\n");
            break;

        // ========== button 7 ========== //
        case 11100: // shift off
            printf("button 7 shift off\n");
            break;

        case 11101: // shift on
            printf("button 7 shift on\n");
            break;
        
        default:
            break;
    }
}

// automate these commands within certain time duration
void automation(const uint *counter)
{
    UNIT_LINE **leds = leds_gen();

    if (*counter == 0) {
        gpiod_line_set_value(leds[0], power_stable());
    }
}

void warn_indicate(uint *counter)
{
    //
}

void notify_indicate( uint *counter)
{
    //
}

void alarm_indicate(uint *counter)
{
    //
}

// increment counter with time (seconds)
void counter_update(uint *counter)
{
    *counter = (*counter + 1) * (*counter != UINT_MAX);
}
