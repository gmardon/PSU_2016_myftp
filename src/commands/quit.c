#include "myftp.h"

void handle_quit(__UNUSED__ char **parameters, t_client *client) 
{
    send_message(client, "221 Service closing control connection.\r\n");
    close_client(client);
}