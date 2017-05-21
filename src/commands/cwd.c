/*
** cwd.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/commands/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

void handle_cwd(char **parameters, t_client *client) 
{
    int chdir_result;
    if (*parameters)
    {
        chdir_result = chdir(*parameters);
        if (chdir_result == 0)
            send_message(client, "250 CWD Command successfull.\r\n");
        else 
            send_message(client, "500 Cannot execute CWD.\r\n");
    }
}