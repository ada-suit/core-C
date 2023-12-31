#include "buzzer.h"
#include "../errors.h"

Ports buzzers_info[] = {
    {"all"    , 13}  // only buzzer I am using; used for all purpose
};

int buzzers_total()
{
    return sizeof(buzzers_info) / sizeof(buzzers_info[0]);
}

// initialise Buzzer array with Buzzer output lines
void buzzers_init(UNIT_LINE *buzzers[], UNIT_CHIP *chip, bool *start)
{
    int i, status;
    for (i = 0; i < buzzers_total(); i++) {
        status = line_init(&buzzers[i], chip, &buzzers_info[i], OUTPUT);
        if (status != 0) {
            printe(status, "Buzzer init", SEVERE);
            start = false;
        }
    }
}

void buzzers_free(UNIT_LINE *buzzers[])
{
    int i = 0;
    for (i = 0; i < buzzers_total(); i++) {
        gpiod_line_release(buzzers[i]);
    }
}
