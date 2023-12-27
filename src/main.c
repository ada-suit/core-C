#include "main.h"

int main() 
{
    // conditions to run the program
    bool run = true;

    // setting up the counter
    struct Counter counter = {0, 1};
    time_t time_now, time_last;
    time(&time_last);

    // initialising the chip
    struct gpiod_chip *chip;
    chip_init(&chip, &run);

    // initialising all components
    struct gpiod_line *leds[component_total(LED)];
    leds_init(leds, chip, &run);

    struct gpiod_line *buzzers[component_total(BUZ)];
    buzzers_init(buzzers, chip, &run);

    int button_count = component_total(BUT);      // [1]
    struct Button buttons[button_count];
    buttons_init(buttons, chip, &run);

    bool button_shift = false; // toggle shift state [2]

    // main loop; runs forever unless requested to not run
    while (run) {
        // trigger every 5 minutes
        if (counter.value % FIVE_MIN == 0 && counter.flag) {
            gpiod_line_set_value(leds[0], power_stable());
        }

        button_state_update(buttons, &button_count, &counter.value);
        button_value_update(buttons, &button_count, &counter.value, &button_shift);

        // stop when button 0 is pressed
        run = 0 < gpiod_line_get_value(buttons[0].call);

        // update the counter
        counter_update(&time_now, &time_last, &counter);
    }

    // turn off all LEDs
    led_call_off(leds, component_total(LED));

    // release resources
    clean_resources(leds, buttons, buzzers);
    gpiod_chip_close(chip);

    return 0;
}
