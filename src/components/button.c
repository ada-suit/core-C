#include "button.h"
#include "../errors.h"

// initialise button array with Button input lines
void buttons_init(Button *buttons, UNIT_CHIP *chip, bool *start)
{
    const Port list[] = {
        {"cease"  , 25}, // 0  terminate the program
        {"input1" , 17}, // 1  ports forwarded for virtual buttons
        {"input2" , 27}, // 2  ports forwarded for virtual buttons
        {"input3" , 22}, // 3  ports forwarded for virtual buttons
        // ...add new buttons here
        {"shiftB" , 24} // 4  toggle shift mode
    };

    for (int i = 0; i < BUTTONS_COUNT; i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown

        const int status = line_init(&buttons[i].call, chip, list[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
            start = false;
        }
    }
}

// check if a button has been pressed
short buttons_update(Button *buttons, const uint *counter)
{
    short condition = 0;

    for (int i = 1; i < BUTTONS_COUNT; i++) {
        if (buttons[i].sleep == 0) {
            const int value = gpiod_line_get_value(buttons[i].call);

            condition *= 10;

            if (value == 1) {
                buttons[i].sleep = *counter + 60;
                condition += 1;
            }
        } else if (buttons[i].sleep <= *counter) {
            buttons[i].sleep = 0;
        }
    }

    /* condition digits = vvvt
        v = redirect to Virtual button
        t = Toggle shift
    */

    return condition;
}

// release resource
void buttons_free(Button *buttons)
{
    for (int i = 0; i < BUTTONS_COUNT; i++) {
        gpiod_line_release(buttons[i].call);
    }
}
