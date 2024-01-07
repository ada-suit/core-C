#include "include/buzzer.h"
#include "include/chip.h"

#define BUZZERS_COUNT 1

// initialise Buzzer array with Buzzer output lines
void buzzers_init(Unit *buzzers)
{
    const Port list[] = {
        {"all"    , 13}  // only buzzer I am using; used for all purpose
        // ...add more buzzers here
    };

    UNIT_CHIP *chip = chip_gen();

    for (int i = 0; i < BUZZERS_COUNT; i++) {
        buzzers[i].sleep = 0;

        const int status = line_init(&buzzers[i].call, chip, list[i], OUTPUT);
        if (status != 0) {
            printe(status, "Buzzer init", SEVERE);
        }
    }
}

// generate buzzers list
Unit* buzzers_gen()
{
    static bool generate = true;
    static Unit *buzzers;

    if (generate) {
        buzzers = (Unit *)malloc(BUZZERS_COUNT * sizeof(Unit));

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
    Unit *buzzers = buzzers_gen();

    for (int i = 0; i < BUZZERS_COUNT; i++) {
        gpiod_line_set_value(buzzers[i].call, 0);
        gpiod_line_release(buzzers[i].call);
    }

    free(buzzers);
}
