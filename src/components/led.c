#include "led.h"
#include "../components.h"
#include "../errors.h"

struct Ports leds_info[] = {
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
void leds_init(struct gpiod_line *leds[], struct gpiod_chip *chip, bool *start)
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
void leds_off(struct gpiod_line *leds[])
{
    int i = 0;
    for (i = 0; i < leds_total(); i++) {
        gpiod_line_set_value(leds[i], 0);
    }
}

// release resource
void leds_free(struct gpiod_line *leds[])
{
    leds_off(leds);

    int i = 0;
    for (i = 0; i < leds_total(); i++) {
        gpiod_line_release(leds[i]);
    }
}
