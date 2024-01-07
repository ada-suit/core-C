#include "include/led.h"
#include "include/chip.h"

#define LEDS_COUNT 3

// initialise LED array with LED output lines
void leds_init(Unit *leds)
{
    const Port list[] = {
        {"power"  , 26}, // 0  indicate power stability
        {"network", 21}, // 1  indicate internet connectivity
        {"shiftL",  23}  // 2  indicate shift status
        // ...add more LEDs here
    };

    UNIT_CHIP *chip = chip_gen();

    for (int i = 0; i < LEDS_COUNT; i++) {
        leds[i].sleep = 0;

        const int status = line_init(&leds[i].call, chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "LED init", SEVERE);
        }
    }
}

// generate an array of gpiod LEDs lines
Unit* leds_gen()
{
    static bool generate = true;
    static Unit *leds;

    if (generate) {
        leds = (Unit *)malloc(LEDS_COUNT * sizeof(Unit));

        if (leds == NULL) {
            printe(1200, "LED init", SEVERE);
        }

        leds_init(leds);
        generate = false;
    }

    return leds;
}

// update leds state to turn them off if required
void leds_update(const uint *counter)
{
    Unit *leds = leds_gen();

    for (int i = 1; i < LEDS_COUNT; i++) {
        if (leds[i].sleep == *counter) {
            leds[i].sleep = 0;
            gpiod_line_set_value(leds[i].call, 0);
        }
    }
}

// release resource
void leds_free()
{
    Unit *leds = leds_gen();

    for (int i = 0; i < LEDS_COUNT; i++) {
        gpiod_line_set_value(leds[i].call, 0);
        gpiod_line_release(leds[i].call);
    }

    free(leds);
}
