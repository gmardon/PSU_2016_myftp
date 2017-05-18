#include "myftp.h"

void handle_pass(char **parameters, t_client *client) 
{
    if (strcmp(*parameters, "") == 0) 
    {
        send_data(client, "230 Successfully connected !\r\n");
        client->connected = 1;
    }
    else
    {
        send_data(client, "503 Permission denied\r\n");
        close_client(client);
    }
}