#include "main.h"

int main() {
    int counter = 0;
    time_t current_time, start_time;
    time(&start_time);

    struct gpiod_chip *chip;
    chip_init(&chip);

    struct gpiod_line *buzzer;
    line_init(&buzzer, chip, "buzzer", 17, 'o');

    struct gpiod_line *led_power;
    line_init(&led_power, chip, "power stability", 26, 'o');

    int stop = 0;
    while (!stop) {
        // trigger every 5mins
        if (counter % 300 == 0) { 

            gpiod_line_set_value(led_power, power_stable());
        }

        counter_update(&counter, &start_time, &current_time);
    }

    // Release resources
    gpiod_line_release(led_power);
    gpiod_line_release(buzzer);
    gpiod_chip_close(chip);

    return 0;
}

void counter_update(int *value, time_t *last_time, time_t *now_time) {
    // Get the current time
    time(now_time);

    // Check if the current time has changed
    if (*now_time != *last_time) {
        *last_time = *now_time;
        (*value)++;
    }
}
