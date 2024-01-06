#include "include/buzzer.h"
#include "include/chip.h"

#define BUZZERS_COUNT 1

// initialise Buzzer array with Buzzer output lines
void buzzers_init(UNIT_LINE *buzzers[])
{
    const Port list[] = {
        {"all"    , 13}  // only buzzer I am using; used for all purpose
    };

    UNIT_CHIP *chip = chip_gen();

    for (int i = 0; i < BUZZERS_COUNT; i++) {
        const int status = line_init(&buzzers[i], chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "Buzzer init", SEVERE);
        }
    }
}

UNIT_LINE** buzzers_gen()
{
    static bool generate = true;
    static UNIT_LINE **buzzers;

    if (generate) {
        buzzers = (UNIT_LINE **)malloc(BUZZERS_COUNT * sizeof(UNIT_LINE*));

        if (buzzers == NULL) {
            printe(1200, "Buzzer init", SEVERE);
        }

        buzzers_init(buzzers);
        generate = false;
    }

    return buzzers;
}

void buzzers_free()
{
    UNIT_LINE **buzzers = buzzers_gen();

    for (int i = 0; i < BUZZERS_COUNT; i++) {
        gpiod_line_release(buzzers[i]);
    }

    free(buzzers);
}
