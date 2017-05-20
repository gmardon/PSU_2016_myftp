#include "myftp.h"

void handle_syst(char **parameters, t_client *client) 
{
    send_message(client, "215 UNIX SYSTEM\r\n");
}