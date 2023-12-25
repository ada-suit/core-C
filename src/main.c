#include "main.h"

int main() 
{
    struct Counter counter = {0, 1};
    time_t time_now, time_last;
    time(&time_last);

    struct gpiod_chip *chip;
    chip_init(&chip);

    struct gpiod_line *buzzer;
    line_init(&buzzer, chip, "buzzer", 17, 'o');

    struct gpiod_line *led_power;
    line_init(&led_power, chip, "power stability", 26, 'o');

    struct gpiod_line *b_terminate;
    line_init(&b_terminate, chip, "terminate button", 24, 'i');
    
    int stop = 0;
    while (!stop) {
        // trigger every 5 minutes
        if (counter.value % FIVE_MIN == 0 && counter.flag) {
            gpiod_line_set_value(led_power, power_stable());
        }

        int v_terminate = gpiod_line_get_value(b_terminate);
        if (v_terminate < 1) {
            printf("%d\n", v_terminate);
            break;
        }

        stop = counter.value == 20;
        counter_update(&time_now, &time_last, &counter);
    }

    // Release resources
    gpiod_line_release(led_power);
    gpiod_line_release(buzzer);
    gpiod_chip_close(chip);

    return 0;
}

// increment counter with time
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
