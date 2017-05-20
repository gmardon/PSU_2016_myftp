#include "myftp.h"

void handle_list(char **parameters, t_client *client) 
{
    struct dirent *dirent_struct;
    DIR *directory;

printf("handle list\n");
    if (client->data_fd == -1)
        send_message(client, "425 Use PORT or PASV first\r\n");
    else 
    {
        directory = opendir(".");
        while ((dirent_struct = readdir(directory)))
        {
            send_data(client, "%s\r\n", dirent_struct->d_name);
        }
        close_data(client);
        send_message(client, "226 Directory send OK\r\n");
    }
}