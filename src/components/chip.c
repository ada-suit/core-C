#include "chip.h"
#include "../errors.h"

// initialise the gpio chip
void chip_init(struct gpiod_chip **chip, bool *start)
{
    *chip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);
    if (*chip == NULL) {
        printe(1001, "GPIO chip", SEVERE);
        start = false;
    }
}
