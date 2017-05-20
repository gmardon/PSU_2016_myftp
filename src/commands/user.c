#include "myftp.h"

void handle_user(char **parameters, t_client *client) 
{
    if (*parameters)
    {
        send_message(client, "331 Username okay, but need password\r\n");
        client->username = strdup(*parameters);
    }
}