#include "myftp.h"

void handle_feat(char **parameters, t_client *client) 
{
    send_message(client, "211-Extensions supported:\r\n MLST size*;create;modify*;perm;media-type\r\n211 END\r\n");
}