#include "myftp.h"

int authenticate(t_client *client)
{
    if (strcmp(client->username, "Anonymous") == 0)
    {
        client->home = strdup(client->server->anonymous_path);
        chdir(client->home);
        client->connected = 1;
        return (1);
    }
    else
        return (0);
}

void handle_pass(char **parameters, t_client *client) 
{
    if (parameters[1] == NULL)
        client->password = "";
    else 
        client->password = parameters[1];

    if (authenticate(client))
    {
        send_message(client, "230 Successfully connected !\r\n");
    }
    else
    {
        send_message(client, "503 Permission denied\r\n");
        close_client(client);
    }
}