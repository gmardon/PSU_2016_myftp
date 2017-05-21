#include "myftp.h"

char *get_client_pwd(t_client *client)
{
    int index;
    char *cwd;

    cwd = my_malloc(256 * sizeof(char));
    memset(cwd, 0, 256 * sizeof(char));

    getcwd(cwd, 256);
    cwd[strlen(cwd)] = '/';
    index = 0;
    printf("client->home: %s\n", client->home);
    printf("cwd: %s\n", cwd);
    while (client->home[index] == cwd[index] 
        && client->home[index] != 0 && cwd[index] != 0)
        index++;
        

    return (strdup(cwd + index));
}

void handle_pwd(char **parameters, t_client *client) 
{
    send_message(client, "257 %s\r\n", get_client_pwd(client));
}