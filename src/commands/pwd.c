#include "myftp.h"

void handle_pwd(char **parameters, t_client *client) 
{
    send_data(client, "257 /\r\n");
}