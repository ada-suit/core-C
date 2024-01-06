#include <stdio.h>
#include <time.h>
#include "include/errors.h"

char *description(const int code) {

    // 10xx Errors related to GPIO connection (pin/chip/lines/etc.)
    // 11xx Errors related to running system commands
    // 12xx Errors related to managing memory
    // 13xx Errors related to running external shell scripts
    // 14xx Errors related to file management (write/read/open/close)
    // 99xx Errors related to misusing defined functions

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

        case 1200:
            return "allocating memory in the heap";

        case 9900:
            return "invalid function argument";

        default:
            return "UNKNOWN ERROR";
    }
}

// print error
void printe(const int code, const char identifier[16], const bool severe)
{
    time_t rawtime;
    time(&rawtime);
    const struct tm *timeinfo = localtime(&rawtime);

    const int green = !severe * 0xFF;

    printf("Current time: %02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("\033[38;2;%d;%d;%dmError %d \033[0m", 0xFF, green, 0, code);
    printf("\033[38;2;%d;%d;%dm [%s] \033[0m ", 0x62, 0xA0, 0xEA, identifier);
    printf("%s\n", description(code));
}
