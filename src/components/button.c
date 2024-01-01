#include "button.h"
#include "../errors.h"

Ports buttons_info[] = {
    {"cease"  ,  5}, // 0  terminate the program
    {"shiftB" , 24}, // 1  toggle shift mode
    {"input1" , 17}, // 2  ports forwarded for virtual buttons
    {"input2" , 27}, // 3  ports forwarded for virtual buttons
    {"input3" , 22}  // 4  ports forwarded for virtual buttons
};

// return total count of all buttons
int buttons_total()
{
    return sizeof(buttons_info) / sizeof(buttons_info[0]);
}

// initialise button array with Button input lines
void buttons_init(Button *buttons, UNIT_CHIP *chip, bool *start)
{
    int i, status;
    for (i = 0; i < buttons_total(); i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown
        status = line_init(&buttons[i].call, chip, &buttons_info[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
            start = false;
        }
    }
}

// trigger different actions depending on button pressed
void button_call(short condition)
{
    switch (condition) {
        case 10: // 10 = button 1 & toggle shift off
            break;

        case 11:
            break;
        
        default:
            break;
    }
}

// check if a button has been pressed
void buttons_update(Button *buttons, int *count, uint *counter, bool *shift)
{
    int i = 1;
    short condition = *shift;

    for (i = 1; i < *count; i++) {
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

    button_call(condition);
}

// release resource
void buttons_free(Button *buttons)
{
    int i = 0;
    for (i = 0; i < buttons_total(); i++) {
        gpiod_line_release(buttons[i].call);
    }
}
