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
        // update
        counter_update(&counter);
        leds_update(&counter);
        buzzers_update(&counter);
        const short status = buttons_update(&counter);

        // trigger actions
        call_action(status, &button_shift, &counter);
        auto_action(&counter);

        // check if the loop must continue
        run = keep_running();
    }
    
    // release resources
    chip_free();      // release the chip
    leds_free();      // free all LEDs connections and memory
    buzzers_free();   // free all buzzers connections and memory
    buttons_free();   // free all buttons connections and memory

    return 0;
}
