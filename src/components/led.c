#include "led.h"
#include "../errors.h"

Ports leds_info[] = {
    {"power"  , 26}, // 0  indicate power stability
    {"network", 21}, // 1  indicate internet connectivity
    {"shiftL",  23}  // 2  indicate shift status
};

// return total count of all leds
int leds_total()
{
    return sizeof(leds_info) / sizeof(leds_info[0]);
}

// initialise LED array with LED output lines
void leds_init(UNIT_LINE *leds[], UNIT_CHIP *chip, bool *start)
{
    int i, status;
    for (i = 0; i < leds_total(); i++) {
        status = line_init(&leds[i], chip, &leds_info[i], OUTPUT);
        if (status != 0) {
            printe(status, "LED init", SEVERE);
            start = false;
        }
    }
}

// turn off all LEDs
void leds_off(UNIT_LINE *leds[])
{
    int i = 0;
    for (i = 0; i < leds_total(); i++) {
        gpiod_line_set_value(leds[i], 0);
    }
}

// release resource
void leds_free(UNIT_LINE *leds[])
{
    leds_off(leds);

    int i = 0;
    for (i = 0; i < leds_total(); i++) {
        gpiod_line_release(leds[i]);
    }
}
