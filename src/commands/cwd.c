#include "myftp.h"

void handle_cwd(char **parameters, t_client *client) 
{
    int chdir_result;
    if (*parameters)
    {
        chdir_result = chdir(*parameters);
        if (chdir_result == 0)
            send_message(client, "250 CWD Command successfull.\r\n");
        else 
            send_message(client, "500 Cannot execute CWD.\r\n");
    }
}