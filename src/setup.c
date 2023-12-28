#include "setup.h"
#include "errors.h"

struct Ports leds_info[] = {
    {"power"  , 26}, // 0  indicate power stability
    {"network", 21}, // 1  indicate internet connectivity
    {"shiftL",  23}  // 2  indicate shift status
};

struct Ports buttons_info[] = {
    {"cease"  ,  5}, // 0  terminate the program
    {"shiftB" , 24}, // 1  toggle shift mode
    {"buttest", 17}, // 2 
    {"buttest", 27}, // 3 
    {"buttest", 22}  // 4 
};

struct Ports buzzers_info[] = {
    {"all"    , 13}  // only buzzer I am using; used for all purpose
};

// get total number of each component
int component_total(int component)
{
    int size;
    switch(component) {
        case 0: // LEDS
            size = sizeof(leds_info) / sizeof(leds_info[0]);
            break;
        
        case 1: // BUTTONS
            size = sizeof(buttons_info) / sizeof(buttons_info[0]);
            break;
            
        case 2: // BUZZERS
            size = sizeof(buzzers_info) / sizeof(buzzers_info[0]);
            break;

        default:
            size = 0;
            break;
    }
    
    return size;
}

// initialise the gpio chip
void chip_init(struct gpiod_chip **chip, bool *start)
{
    *chip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);
    if (*chip == NULL) {
        printe(1001, "GPIO chip", SEVERE);
        start = false;
    }
}

// initalise lines and configure them for input/output
int line_init(struct gpiod_line **line, struct gpiod_chip *chip, struct Ports *port, bool mode)
{
    *line = gpiod_chip_get_line(chip, port->pin);
    if (!(*line)) {
        gpiod_chip_close(chip);
        return 1001;
    }
    if (mode) {
        // input
        if (gpiod_line_request_input(*line, port->name) < 0) {
            gpiod_line_release(*line);
            gpiod_chip_close(chip);
            return 1002;
        }    
    } else {
        // output
        if (gpiod_line_request_output(*line, port->name, 0) < 0) {
            gpiod_line_release(*line);
            gpiod_chip_close(chip);
            return 1003;
        }
    }

    return 0;
}

// initialise LED array with LED output lines
void leds_init(struct gpiod_line *leds[], struct gpiod_chip *chip, bool *start)
{
    int size = component_total(0);
    int i, status;

    for (i = 0; i < size; i++) {
        status = line_init(&leds[i], chip, &leds_info[i], OUTPUT);
        if (status != 0) {
            printe(status, "LED init", SEVERE);
            start = false;
        }
    }
}

// initialise button array with Button input lines
void buttons_init(struct Button *buttons, struct gpiod_chip *chip, bool *start)
{
    int size = component_total(1);
    int i, status;

    for (i = 0; i < size; i++) {
        buttons[i].sleep = 0; // by default buttons aren't on cooldown
        status = line_init(&buttons[i].call, chip, &buttons_info[i], INPUT);
        if (status != 0) {
            printe(status, "Button init", SEVERE);
            start = false;
        }
    }
}

// initialise Buzzer array with Buzzer output lines
void buzzers_init(struct gpiod_line *buzzers[], struct gpiod_chip *chip, bool *start)
{
    int size = component_total(2);
    int i, status;

    for (i = 0; i < size; i++) {
        status = line_init(&buzzers[i], chip, &buzzers_info[i], OUTPUT);
        if (status != 0) {
            printe(status, "Buzzer init", SEVERE);
            start = false;
        }
    }
}

// release all components
void clean_resources(struct gpiod_line *leds[], struct Button *buttons, struct gpiod_line *buzzers[])
{
    int i = 0;

    for (i = 0; i < component_total(0); i++) {
        gpiod_line_release(leds[i]);
    }

    for (i = 0; i < component_total(1); i++) {
        gpiod_line_release(buttons[i].call);
    }

    for (i = 0; i < component_total(2); i++) {
        gpiod_line_release(buzzers[i]);
    }
}
