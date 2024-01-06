#include <stdbool.h>
#include "include/trigger.h"
#include "components/include/led.h"
#include "components/include/button.h"
#include "components/include/buzzer.h"
#include "components/include/chip.h"

int main() 
{
    bool run = true;            // conditions to run the program
    uint counter = 0;           // setting up the counter
    bool button_shift = false;  // toggle shift state

    UNIT_CHIP *chip = chip_gen();           // initialising the chip
    UNIT_LINE **leds = leds_gen();          // initialising all LEDs
    UNIT_LINE **buzzers = buzzers_gen();    // initialising all buzzers
    Button *buttons = buttons_gen();        // initialising all buttons

    // main loop; runs forever unless requested to not run
    while (run) {
        // update the counter
        counter_update(&counter);

        // trigger actions
        const short status = buttons_update(&counter);
        button_action(status, &button_shift, &counter);
        automation(&counter);

        // check if the loop must continue
        run = run_program();
    }
    
    // release resources
    leds_free();
    buttons_free();
    buzzers_free();
    chip_free();

    return 0;
}
