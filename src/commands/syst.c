#include "myftp.h"

void handle_syst(char **parameters, t_client *client) 
{
    send_message(client, "215 UNIX Type: %s\r\n", client->transfert_type);
}