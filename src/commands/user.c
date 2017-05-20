#include "myftp.h"

void handle_user(char **parameters, t_client *client) 
{
    if (strcmp(*parameters, "Anonymous") == 0) 
    {
        send_message(client, "331 Username okay, but need password\r\n");
    }
    else
    {
        send_message(client, "503 Permission denied\r\n");
        close_client(client);
    }
}