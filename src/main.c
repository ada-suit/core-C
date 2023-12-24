#include "main.h"

int main() {
    struct gpiod_chip *chip;
    chip_init(&chip);

    struct gpiod_line *buzzer;
    line_init(&buzzer, chip, "buzzer", 17, 'o');

    struct gpiod_line *led_power;
    line_init(&led_power, chip, "power stability", 26, 'o');

    int counter = 0;
    int stop = 0;
    while (!stop) {
        // trigger every 300 loops
        if (counter % 300 == 0) { 
            gpiod_line_set_value(led_power, power_stable());
        }

        counter_update(&counter, &start_time, &current_time);

        counter++;
    }

    // Release resources
    gpiod_line_release(led_power);
    gpiod_line_release(buzzer);
    gpiod_chip_close(chip);

    return 0;
}
