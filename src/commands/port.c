#include "myftp.h"

void handle_port(char **parameters, t_client *client) 
{
    client->active_mode = 1;
    // TODO get host-port
    send_data(client, "200 Use active mode\r\n");
}