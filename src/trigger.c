#include "update.h"

void button_call(int *id, int *shift)
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

void button_value_update(struct Button *buttons, bool *run, bool *shift, int *count, int *counter)
{
    int i = 0;
    for (i = 0; i < *count; i++) {
        if (button.pause == 0) {
            int value = gpiod_line_get_value(button.call);

            if (value < 1) {
                button.sleep = *counter + 1; // one second delay 
                button_call(&i, shift);
            }
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
