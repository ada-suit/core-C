#include "main.h"

int main() 
{
    // setting up the counter
    struct Counter counter = {0, 1};
    time_t time_now, time_last;
    time(&time_last);

    // initialising the chip
    struct gpiod_chip *chip;
    chip_init(&chip);

    // initialising all components
    struct gpiod_line *leds[component_total(LED)];
    leds_init(leds, chip);

    struct gpiod_line *buzzers[component_total(BUZ)];
    buzzers_init(buzzers, chip);

    int button_count = component_total(BUT);      // [1]
    struct Button buttons[button_count];
    buttons_init(buttons, chip);

    bool button_shift = false; // toggle shift state [2]

    // main loop; runs forever unless requested to not run
    bool run = true;
    while (run) {
        // trigger every 5 minutes
        if (counter.value % FIVE_MIN == 0 && counter.flag) {
            gpiod_line_set_value(leds[0], power_stable());
        }
        
        button_value_update(buttons, &run, &button_shift, &button_count, &counter);

        //int v_terminate = gpiod_line_get_value(b_terminate);
        //if (v_terminate < 1) {
        //    printf("%d\n", v_terminate);
        //    break;
        //}

        // update the counter
        counter_update(&time_now, &time_last, &counter);
    }

    // release resources
    clean_resources(leds, buttons, buzzers);
    gpiod_chip_close(chip);

    return 0;
}
