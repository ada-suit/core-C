#include <stdio.h>
#include <gpiod.h>
#include "sysinfo.h"

int main() {
    struct gpiod_chip *chip;
    chip_init(&chip);

    struct gpiod_line *led_power;
    line_init(&led_power, chip, "power stability", 26, 'o');
    gpiod_line_set_value(led_power, power_stable());
    
    // Release resources
    gpiod_line_release(led_power);
    gpiod_chip_close(chip);

    return 0;
}
