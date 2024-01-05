#include <gpiod.h>
#include <stdbool.h>
#include "include/trigger.h"
#include "components/include/led.h"
#include "components/include/button.h"
#include "components/include/buzzer.h"
#include "components/include/chip.h"

int main() 
{
    bool run = true;            // conditions to run the program
    uint counter = 0;           // setting up the counter
    bool button_shift = false;  // toggle shift state

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

    // main loop; runs forever unless requested to not run
    while (run) {
        // update the counter
        counter_update(&counter);

        // trigger actions
        automation(leds, &counter);
        button_action(buttons_update(buttons, &counter), leds, &button_shift, counter);

        // stop when button 0 is pressed
        run = run_program(buttons[0]);
    }
    
    // release resources
    leds_free(leds);
    buttons_free(buttons);
    buzzers_free(buzzers);
    gpiod_chip_close(chip);

    return 0;
}
