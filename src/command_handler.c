/*
** command_handler.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

int handle_command(char *buffer, t_client *client)
{
    int index = 0;
    char **command = strsplit(buffer, "\n\r ");
    int handled = 0;
    while (commands[index].name) {
        if (strcmp(commands[index].name, *command) == 0) {
            (commands[index].handler)(command + 1, client);
            handled++;
        }
        index++;
    }
    return (handled);
}