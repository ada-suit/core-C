#include "main.h"

int main() {
    time_t current_time;

    struct gpiod_chip *chip;
    chip_init(&chip);

    struct gpiod_line *buzzer;
    line_init(&buzzer, chip, "buzzer", 17, 'o');

    struct gpiod_line *led_power;
    line_init(&led_power, chip, "power stability", 26, 'o');

    int stop = 0;
    while (!stop) {
        time(&current_time);

        if (current_time % 300 == 0) { // trigger every 5mins
            gpiod_line_set_value(led_power, power_stable());
        }
    }

    // Release resources
    gpiod_line_release(led_power);
    gpiod_line_release(buzzer);
    gpiod_chip_close(chip);

    return 0;
}
