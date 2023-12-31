#include "main.h"

int main() 
{
    // conditions to run the program
    bool run = true;

    // setting up the counter
    Counter counter = {.value = 0, .flag = 1};
    time_t time_now, time_last;
    time(&time_last);

    // initialising the chip
    UNIT_CHIP *chip;
    chip_init(&chip, &run);

    // initialising all components
    UNIT_LINE *leds[leds_total()];
    leds_init(leds, chip, &run);

    UNIT_LINE *buzzers[buzzers_total()];
    buzzers_init(buzzers, chip, &run);

    int button_count = buttons_total(); //            [1]
    Button buttons[button_count];
    buttons_init(buttons, chip, &run);

    bool button_shift = false; // toggle shift state  [2]

    // main loop; runs forever unless requested to not run
    while (run) {
        // trigger every 5 minutes
        if (counter.value % FIVE_MIN == 0 && counter.flag) {
            gpiod_line_set_value(leds[0], power_stable());
        }

        buttons_update(buttons, &button_count, &counter.value, &button_shift);

        // stop when button 0 is pressed
        run = 0 < gpiod_line_get_value(buttons[0].call);

        // update the counter
        counter_update(&time_now, &time_last, &counter);
    }
    
    // release resources
    leds_free(leds);
    buttons_free(buttons);
    buzzers_free(buzzers);
    gpiod_chip_close(chip);

    return 0;
}
