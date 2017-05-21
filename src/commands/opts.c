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
            send_message(client, "200 %s set to %s.\r\n", parameters[0], parameters[1]);
    }
}