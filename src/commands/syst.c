#include "myftp.h"

void handle_syst(char **parameters, t_client *client) 
{
    send_data(client, "215 UNIX SYSTEM\r\n");
}