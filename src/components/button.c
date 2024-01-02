#include "button.h"
#include "../errors.h"


// initialise button array with Button input lines
void buttons_init(Button *buttons, UNIT_CHIP *chip, bool *start)
{
    Port list[] = {
        {"cease"  , 25}, // 0  terminate the program
        {"input1" , 17}, // 1  ports forwarded for virtual buttons
        {"input2" , 27}, // 2  ports forwarded for virtual buttons
        {"input3" , 22}, // 3  ports forwarded for virtual buttons
        // ...add new buttons here
        {"shiftB" , 24} // 4  toggle shift mode
    };

    int i, status;
    for (i = 0; i < BUTTONS_COUNT; i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown
        
        status = line_init(&buttons[i].call, chip, list[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
            start = false;
        }
    }
}

// trigger different actions depending on button pressed
void button_call(short condition, bool *shift)
{
    condition = (condition * 10) + *shift;
    switch (condition) {
        // ======== toggle shift ======== //
        case 10: // shift off
            *shift = true;
            break;

        case 11: // shift on
            *shift = false;
            break;
        
        // ========== button 1 ========== //
        case 100: // shift off
            break;

        case 101: // shift on
            break;

        // ========== button 2 ========== //
        case 1000: // shift off
            break;

        case 1001: // shift on
            break;

        // ========== button 3 ========== //
        case 1100: // shift off
            break;

        case 1101: // shift on
            break;

        // ========== button 4 ========== //
        case 10000: // shift off
            break;

        case 10001: // shift on
            break;

        // ========== button 5 ========== //
        case 10100: // shift off
            break;

        case 10101: // shift on
            break;

        // ========== button 6 ========== //
        case 11000: // shift off
            break;

        case 11001: // shift on
            break;

        // ========== button 7 ========== //
        case 11100: // shift off
            break;

        case 11101: // shift on
            break;
        
        default:
            break;
    }
}

// check if a button has been pressed
void buttons_update(Button *buttons, uint *counter, bool *shift)
{
    int i = 1;
    short condition = 0;

    for (i = 1; i < BUTTONS_COUNT; i++) {
        if (buttons[i].sleep <= *counter) {
            buttons[i].sleep = 0;

        } else if (buttons[i].sleep == 0) {
            int value = gpiod_line_get_value(buttons[i].call);

            if (value == 1) {
                buttons[i].sleep = *counter + 1; // one second delay 
                condition *= 10;
                condition += 1;
            }
        }
    }

    /* condition digits = vvvt
        v = redirect to Virtual button
        t = Toggle shift
    */

    if (condition != 0) {
        // dont call the function if no button is pressed
        button_call(condition, shift);
    }
}

// release resource
void buttons_free(Button *buttons)
{
    int i = 0;
    for (i = 0; i < BUTTONS_COUNT; i++) {
        gpiod_line_release(buttons[i].call);
    }
}
