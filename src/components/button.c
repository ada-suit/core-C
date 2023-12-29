#include "button.h"
#include "../component.h"
#include "../errors.h"

struct Ports buttons_info[] = {
    {"cease"  ,  5}, // 0  terminate the program
    {"shiftB" , 24}, // 1  toggle shift mode
    {"buttest", 17}, // 2 
    {"buttest", 27}, // 3 
    {"buttest", 22}  // 4 
};

// return total count of all buttons
int buttons_total()
{
    size = sizeof(buttons_info) / sizeof(buttons_info[0]);
}

// initialise button array with Button input lines
void buttons_init(struct Button *buttons, struct gpiod_chip *chip, bool *start)
{
    int i, status;
    for (i = 0; i < leds_total(); i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown
        status = line_init(&buttons[i].call, chip, &buttons_info[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
            start = false;
        }
    }
}

// trigger different actions depending on button pressed
void button_call(int *id, bool *shift)
{
    int condition = (*id * 10) + *shift;  // id
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
void button_value_update(struct Button *buttons, int *count, uint *counter, bool *shift)
{
    int i = 1;
    for (i = 1; i < *count; i++) {
        if (buttons[i].sleep == 0) {
            int value = gpiod_line_get_value(buttons[i].call);

            if (value < 1) {
                buttons[i].sleep = *counter + 1; // one second delay 
                button_call(&i, shift);
            }
        }
    }
}

// manage button debounce
void button_state_update(struct Button *buttons, int *count, uint *counter)
{
    int i = 0;
    for (i = 0; i < *count; i++) {
        if (buttons[i].sleep <= *counter) {
            buttons[i].sleep = 0;
        }
    }
}

// release resource
void buttons_free(struct Button *buttons)
{
    for (i = 0; i < leds_total(); i++) {
        gpiod_line_release(buttons[i].call);
    }
}
