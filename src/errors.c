#include <stdio.h>
#include "errors.h"

char *description(int code) {

    // 10xx Errors related to GPIO connection (pin/chip/lines/etc.)
    // 11xx Errors related to running system commands
    // 12xx Errors related to file management (write/read/open/close)
    // 13xx Errors related to running external shell scripts

    switch (code) {
        case 1000:
            return "initialising GPIO chip";

        case 1001:
            return "opening GPIO line";

        case 1002:
            return "establishing GPIO line as INPUT";

        case 1003:
            return "establishing GPIO line as OUTPUT";

        case 1100:
            return "opening pipe for command execution";

        case 1101:
            return "reading command output from pipe";

        case 1103:
            return "closing pipe after command execution";

        default:
            return "UNKNOWN ERROR";
    }
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
