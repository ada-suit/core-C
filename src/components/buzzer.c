#include "buzzer.h"
#include "../components.h"
#include "../errors.h"

struct Ports buzzers_info[] = {
    {"all"    , 13}  // only buzzer I am using; used for all purpose
};

int buzzers_total()
{
    return size = sizeof(buzzers_info) / sizeof(buzzers_info[0]);
}

// initialise Buzzer array with Buzzer output lines
void buzzers_init(struct gpiod_line *buzzers[], struct gpiod_chip *chip, bool *start)
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

void buzzers_free(struct gpiod_line *buzzers[])
{
    for (i = 0; i < buzzers_total(); i++) {
        gpiod_line_release(buzzers[i]);
    }
}
