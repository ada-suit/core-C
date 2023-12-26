#include "trigger.h"

void button_call(int *id, bool *shift, bool *run)
{
    int condition = (*id * 10) + *shift;  // id
    switch (condition) {
        case 0:  // 00 = button 0 & toggle shift off
            *run = false;
            break;

        case 1:  // 01 = button 0 & toggle shift on
            break;

        case 10: // 10 = button 1 & toggle shift off
            break;

        case 11:
            break;
        
        default:
            break;
    }
}

void button_value_update(struct Button *buttons, bool *run, bool *shift, int *count, uint *counter)
{
    int i = 0;
    for (i = 0; i < *count; i++) {
        if (buttons[i].sleep == 0) {
            int value = gpiod_line_get_value(buttons->call);

            if (value < 1) {
                buttons[i].sleep = *counter + 1; // one second delay 
                button_call(&i, shift, run);
            }
        }
    }
}

void button_state_update(struct Button *buttons, int *count, uint *counter)
{
    int i = 0;
    for (i = 0; i < *count; i++) {
        if (buttons[i].sleep <= *counter) {
            buttons[i].sleep = 0;
        }
    }
}

// increment counter with time (seconds)
void counter_update(time_t *ntime, time_t *ltime, struct Counter *counter) 
{
    time(ntime);

    if (*ntime == *ltime) {
        counter->flag = 0;
    } else {
        *ltime = *ntime;
        counter->value++;
        counter->flag = 1;
    }
}
