#include "myftp.h"

void handle_auth(__UNUSED__ char **parameters, t_client *client) 
{
    send_message(client, "502 SSL/TLS authentication not allowed\r\n");
}