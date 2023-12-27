#include <stdio.h>
#include "errors.h"

char* description(int code) {
    char *description;

    // 10xx Errors related to GPIO connection (pin/chip/lines/etc.)
    // 11xx Errors related to running system commands
    // 12xx Errors related to file management (write/read/open/close)
    // 13xx Errors related to running external shell scripts

    switch (code) {
        case 1000:
            description = "initialising GPIO chip";
            break;

        case 1001:
            description = "opening GPIO line";
            break;

        case 1002:
            description = "establishing GPIO line as INPUT";
            break;

        case 1003:
            description = "establishing GPIO line as OUTPUT";
            break;

        case 1100:
            description = "opening pipe for command execution";
            break;

        case 1101:
            description = "reading command output from pipe";
            break;

        case 1103:
            description = "closing pipe after command execution";
            break;

        default:
            description = "UNKNOWN ERROR";
            break;
    }

    return description;
}

// print error
void printe(int code, char identifier[16], bool severe)
{
    int green = 0xFF;
    if (severe) {
        green = 0;
    }

    printf("\033[38;2;%d;%d;%dmError %d \033[0m", 0xFF, green, 0, code);     // [1]
    printf("\033[38;2;%d;%d;%dm [%s] \033[0m ", 0x62, 0xA0, 0xEA, identifier);
    printf("%s\n", description(code));
}
