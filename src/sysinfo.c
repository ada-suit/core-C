#include "sysinfo.h"

int run_command(const char *command, char *buffer, short buffer_size)
{
    FILE *cmd_output = popen(command, "r");
    
    if (cmd_output == NULL) {
        perror("Error opening pipe");
        return -1;
    }

    if (fgets(buffer, buffer_size, cmd_output) == NULL) {
        perror("Error reading command output");
        return -1;
    }
    
    if (pclose(cmd_output) == -1) {
        perror("Error closing pipe");
        return -1;
    }

    return 0;
}

