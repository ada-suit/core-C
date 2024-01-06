#include "include/chip.h"

// initialise the gpio chip
void chip_init(UNIT_CHIP **chip)
{
    *chip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);
    if (*chip == NULL) {
        printe(1001, "GPIO chip", SEVERE);
    }
}

UNIT_CHIP* chip_gen()
{
    static UNIT_CHIP *chip;

    if (chip == NULL) {
        chip_init(&chip);
    }

    return chip;
}

// release chip resources
void chip_free()
{
    UNIT_CHIP *chip = chip_gen();
    gpiod_chip_close(chip);

    free(chip);
}
