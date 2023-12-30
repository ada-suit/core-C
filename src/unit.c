#include "unit.h"

// initalise lines and configure them for input/output
int line_init(UNIT_LINE **line, UNIT_CHIP *chip, Ports *port, bool mode)
{
    *line = gpiod_chip_get_line(chip, port->pin);
    if (!(*line)) {
        gpiod_chip_close(chip);
        return 1001;
    }
    if (mode) {
        // input
        if (gpiod_line_request_input(*line, port->name) < 0) {
            gpiod_line_release(*line);
            gpiod_chip_close(chip);
            return 1002;
        }    
    } else {
        // output
        if (gpiod_line_request_output(*line, port->name, 0) < 0) {
            gpiod_line_release(*line);
            gpiod_chip_close(chip);
            return 1003;
        }
    }

    return 0;
}
