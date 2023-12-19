#include "setup.h"

int chip_init(struct gpiod_chip **chip)
{
    *chip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);
    if (!(*chip)) {
        perror("Error opening GPIO chip");
        return 1;
    }
    return 0;
}

int line_init(struct gpiod_line **line, struct gpiod_chip *chip, char *label, int pin, char mode)
{
    *line = gpiod_chip_get_line(chip, pin);
    if (!(*line)) {
        perror("Error opening GPIO line");
        gpiod_chip_close(chip);
        return 1;
    }

    switch (mode) {
        case 'o':
            if (gpiod_line_request_output(*line, label, 0) < 0) {
                perror("Error configuring GPIO line");
                gpiod_line_release(*line);
                gpiod_chip_close(chip);
                return 1;
            }
            break;

        case 'i':
            if (gpiod_line_request_input(*line, label) < 0) {
                perror("Error configuring GPIO line for input");
                gpiod_line_release(*line);
                gpiod_chip_close(chip);
                return 1;
            }
            break;

        default:
            fprintf("Invalid mode: %c\n", mode);
            gpiod_line_release(*line);
            gpiod_chip_close(chip);
            return 1;
    }
    return 0;
}
