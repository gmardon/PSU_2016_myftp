#include "myftp.h"

void handle_pass(char **parameters, t_client *client) 
{
    if (*parameters)
    {
        client->password = strdup(*parameters);
        if (strcmp(client->username, "Anonymous") == 0) 
        {
            send_message(client, "230 Successfully connected !\r\n");
            client->connected = 1;
        }
        else 
        {
            send_message(client, "503 Permission denied\r\n");
            close_client(client);
        }
    }
}