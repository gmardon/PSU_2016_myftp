#include "myftp.h"

void handle_auth(char **parameters, t_client *client) 
{
    send_data(client, "502 SSL/TLS authentication not allowed\r\n");
}