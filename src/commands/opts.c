/*
** in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

void append_to_opts(t_client *client, char *key, char *value)
{
    int index;
    t_opt *opt;

    index = 0;
    while (!client->opts[index].key && index < 128)
        index++;
    if (index == 128)
        return;
    opt = my_malloc(sizeof(t_opt));
    opt->key = strdup(key);
    opt->value = strdup(value);
    client->opts[index] = *opt;
}

void handle_opts(char **parameters, t_client *client) 
{
    if (*parameters)
    {
        append_to_opts(client, parameters[0], parameters[1]);
        if (strcmp(*parameters, "UTF8") == 0)
        {
            send_message(client, "200 Always in UTF8 mode.\r\n");
        }
        else
            send_message(client, "200 %s set to %s.\r\n"
            , parameters[0], parameters[1]);
    }
}