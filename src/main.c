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

    chip_gen();       // initialising the chip
    leds_gen();       // initialising all LEDs
    buzzers_gen();    // initialising all buzzers
    buttons_gen();    // initialising all buttons

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
    chip_free();      // release the chip
    leds_free();      // free all LEDs connections and memory
    buzzers_free();   // free all buzzers connections and memory
    buttons_free();   // free all buttons connections and memory

    return 0;
}
