#include "include/led.h"
#include "include/chip.h"

#define LEDS_COUNT 3

// initialise LED array with LED output lines
void leds_init(UNIT_LINE *leds[])
{
    const Port list[] = {
        {"power"  , 26}, // 0  indicate power stability
        {"network", 21}, // 1  indicate internet connectivity
        {"shiftL",  23}  // 2  indicate shift status
        // ...add more LEDs here
    };

    UNIT_CHIP *chip = chip_gen();

    for (int i = 0; i < LEDS_COUNT; i++) {
        const int status = line_init(&leds[i], chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "LED init", SEVERE);
        }
    }
}

// generate an array of gpiod LEDs lines
UNIT_LINE** leds_gen()
{
    static bool generate = true;
    static UNIT_LINE **leds;

    if (generate) {
        leds = (UNIT_LINE **)malloc(LEDS_COUNT * sizeof(UNIT_LINE*));

        if (leds == NULL) {
            printe(1200, "LED init", SEVERE);
        }

        leds_init(leds);
        generate = false;
    }

    return leds;
}

// release resource
void leds_free()
{
    UNIT_LINE **leds = leds_gen();

    for (int i = 0; i < LEDS_COUNT; i++) {
        gpiod_line_set_value(leds[i], 0);
        gpiod_line_release(leds[i]);
    }

    free(leds);
}
