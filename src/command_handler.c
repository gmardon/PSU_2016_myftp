#include "myftp.h"

int handle_command(char *buffer, t_client *client) 
{
    int index = 0;
    char **command = strsplit(buffer, "\n\r ");
    while (commands[index].name) {
        if (strcmp(commands[index].name, *command) == 0) {
            (commands[index].handler)(command + 1, client);
        }
        index++;
    }
    return (0);
}