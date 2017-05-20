#include "myftp.h"

void handle_help(char **parameters, t_client *client) 
{
    send_message(client, "214-The following commands are recognized.\r\n");
    send_message(client, "AUTH FEAT LIST PASS PASV PORT PWD SYST TYPE USER\r\n");
    send_message(client, "214 Help OK.");
}