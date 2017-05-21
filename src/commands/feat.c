#include "myftp.h"

void handle_feat(char **parameters, t_client *client) 
{
    send_message(client, "211-Extensions supported:\r\n LIST\r\n211 END\r\n");
}