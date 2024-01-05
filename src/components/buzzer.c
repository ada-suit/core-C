#include "include/buzzer.h"

// initialise Buzzer array with Buzzer output lines
void buzzers_init(UNIT_LINE *buzzers[], UNIT_CHIP *chip, bool *start)
{
    const Port list[] = {
        {"all"    , 13}  // only buzzer I am using; used for all purpose
    };

    for (int i = 0; i < BUZZERS_COUNT; i++) {
        const int status = line_init(&buzzers[i], chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "Buzzer init", SEVERE);
            *start = false;
        }
    }
}

void buzzers_free(UNIT_LINE *buzzers[])
{
    for (int i = 0; i < BUZZERS_COUNT; i++) {
        gpiod_line_release(buzzers[i]);
    }
}
