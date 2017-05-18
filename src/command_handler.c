#include "myftp.h"

int handle_command(char *buffer, t_client *client) 
{
    int index = 0;
    t_command commands[] = {
        {"USER", handle_user},
        {"PASS", handle_pass},
        {0, 0}
    };
    char **command = strsplit(buffer, "\n\r ");
    while (commands[index].name) {
        if (strcmp(commands[index].name, *command) == 0) {
            (commands[index].handler)(command + 1, client);
        }
        index++;
    }
}