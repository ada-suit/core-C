#include <stdio.h>
#include <string.h>
#include "include/sysinfo.h"
#include "include/errors.h"

// run shell commands to process their output
int run_command(const char *command, char *buffer, const short buffer_size)
{
    FILE *cmd_output = popen(command, "r");
    
    if (cmd_output == NULL) {
        return 1100;
    }

    if (fgets(buffer, buffer_size, cmd_output) == NULL) {
        return 1101;
    }
    
    if (pclose(cmd_output) == -1) {
        return 1103;
    }

    return 0;
}

// check if power is indeed stable (throttled=0x0)
int power_stable()
{
    const short buffer_size = 17;
    char buffer[buffer_size];

    const int status = run_command("vcgencmd get_throttled", buffer, buffer_size);

    if (status != 0) {
        printe(status, "power LED", NOTSEVERE);
        return 0;
    }
    
    return !strcmp(buffer, "throttled=0x0\n");
}
