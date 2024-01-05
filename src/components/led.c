#include "include/led.h"

// initialise LED array with LED output lines
void leds_init(UNIT_LINE *leds[], UNIT_CHIP *chip, bool *start)
{
    const Port list[] = {
        {"power"  , 26}, // 0  indicate power stability
        {"network", 21}, // 1  indicate internet connectivity
        {"shiftL",  23}  // 2  indicate shift status
    };

    for (int i = 0; i < LEDS_COUNT; i++) {
        const int status = line_init(&leds[i], chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "LED init", SEVERE);
            start = false;
        }
    }
}

// turn off all LEDs
void leds_off(UNIT_LINE *leds[])
{
    for (int i = 0; i < LEDS_COUNT; i++) {
        gpiod_line_set_value(leds[i], 0);
    }
}

// release resource
void leds_free(UNIT_LINE *leds[])
{
    leds_off(leds);

    for (int i = 0; i < LEDS_COUNT; i++) {
        gpiod_line_release(leds[i]);
    }
}
