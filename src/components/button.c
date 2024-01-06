#include "include/button.h"
#include "include/chip.h"

#define BUTTONS_COUNT 5

// initialise button array with Button input lines
void buttons_init(Button *buttons)
{
    const Port list[] = {
        {"cease"  , 25}, // 0  terminate the program
        {"input1" , 17}, // 1  ports forwarded for virtual buttons
        {"input2" , 27}, // 2  ports forwarded for virtual buttons
        {"input3" , 22}, // 3  ports forwarded for virtual buttons
        // ...add new buttons here
        {"shiftB" , 24} // 4  toggle shift mode
    };

    UNIT_CHIP *chip = chip_gen();

    for (int i = 0; i < BUTTONS_COUNT; i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown

        const int status = line_init(&buttons[i].call, chip, list[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
        }
    }
}

Button* buttons_gen()
{
    static bool generate = true;
    static Button *buttons;

    if (generate) {
        buttons = (Button *)malloc(BUTTONS_COUNT * sizeof(Button));

        if (buttons == NULL) {
            printe(1200, "LED init", SEVERE);
        }

        buttons_init(buttons);
        generate = false;
    }

    return buttons;
}

// check if a button has been pressed
short buttons_update(const uint *counter)
{
    Button *buttons = buttons_gen();
    short condition = 0;

    for (int i = 1; i < BUTTONS_COUNT; i++) {
        if (buttons[i].sleep == 0) {
            const int value = gpiod_line_get_value(buttons[i].call);

            condition *= 10;

            if (value == 1) {
                buttons[i].sleep = *counter + 12345;
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

bool run_program()
{
    Button *buttons = buttons_gen();
    return !gpiod_line_get_value(buttons[0].call);
}


// release resource
void buttons_free()
{
    Button *buttons = buttons_gen();

    for (int i = 0; i < BUTTONS_COUNT; i++) {
        gpiod_line_release(buttons[i].call);
    }

    free(buttons);
}
