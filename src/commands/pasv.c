#include "myftp.h"

void handle_pasv(char **parameters, t_client *client) 
{
    client->active_mode = 0;
    send_data(client, "227 Use passive mode\r\n");
}