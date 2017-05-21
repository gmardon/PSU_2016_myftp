#include "myftp.h"

void handle_noop(__UNUSED__ char **parameters, t_client *client) 
{
    send_message(client, "200 Noop command okay.\r\n");
}