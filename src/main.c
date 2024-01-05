#include <gpiod.h>
#include <stdbool.h>
#include "include/sysinfo.h"
#include "include/trigger.h"
#include "components/include/led.h"
#include "components/include/button.h"
#include "components/include/buzzer.h"
#include "components/include/chip.h"
#include <stdio.h>

int main() 
{
    // conditions to run the program
    bool run = true;

    // setting up the counter
    uint counter = 0;

    // initialising the chip
    UNIT_CHIP *chip;
    chip_init(&chip, &run);

    // initialising all components
    UNIT_LINE *leds[LEDS_COUNT];
    leds_init(leds, chip, &run);

    UNIT_LINE *buzzers[BUZZERS_COUNT];
    buzzers_init(buzzers, chip, &run);

    Button buttons[BUTTONS_COUNT];
    buttons_init(buttons, chip, &run);

    bool button_shift = false; // toggle shift state  [2]

    // main loop; runs forever unless requested to not run
    while (run) {
        // trigger at every counter reset
        if (counter == 0) {
            gpiod_line_set_value(leds[0], power_stable());
            printf("power update\n");
        }

        const short condition = buttons_update(buttons, &counter);
        button_action(condition, leds, &button_shift, counter);

        // stop when button 0 is pressed
        run = !gpiod_line_get_value(buttons[0].call);

        // update the counter
        counter_update(&counter);
    }
    
    // release resources
    leds_free(leds);
    buttons_free(buttons);
    buzzers_free(buzzers);
    gpiod_chip_close(chip);

    return 0;
}
