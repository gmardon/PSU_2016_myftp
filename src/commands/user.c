#include "myftp.h"

void handle_user(char **parameters, t_client *client) 
{
    if (strcmp(*parameters, "Anonymous") == 0) 
    {
        send_data(client, "331\r\n");
    }
    else
    {
        send_data(client, "503 Permission denied\r\n");
        close_client(client);
    }
}