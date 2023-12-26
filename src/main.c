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

    struct Button buttons[component_total(BUT)];
    buttons_init(buttons, chip);

    // main loop; runs forever unless requested to stop
    while (1) {
        // trigger every 5 minutes
        if (counter.value % FIVE_MIN == 0 && counter.flag) {
            gpiod_line_set_value(leds[0], power_stable());
        }

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

// increment counter with time (seconds)
// todo: account delay with all sleep statements
void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter) 
{
    time(ntime);

    if (*ntime == *ltime) {
        counter->flag = 0;
    } else {
        *ltime = *ntime;
        counter->value++;
        counter->flag = 1;
    }
}
