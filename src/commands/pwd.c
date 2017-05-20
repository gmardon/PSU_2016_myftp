#include "myftp.h"

void handle_pwd(char **parameters, t_client *client) 
{
    send_message(client, "257 %s\r\n", client->pwd);
}