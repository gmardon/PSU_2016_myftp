#include "myftp.h"

void handle_list(__UNUSED__ char **parameters, t_client *client) 
{
    struct dirent *dirent_struct;
    DIR *directory;
    struct stat file;
    char buffer[1024];
    
    if (client->data_fd == -1)
        send_message(client, "425 Use PORT or PASV first\r\n");
    else 
    {
        directory = opendir(".");
        while ((dirent_struct = readdir(directory)))
        {
            if (stat(dirent_struct->d_name, &file) == 0)
	        {
                 memset(&buffer, 0, 1024);
                 write_file_infos(dirent_struct->d_name, buffer, &file);
                 send_data(client, "%s\r\n", buffer);
            }
        }
        close_data(client);
        send_message(client, "226 Directory send OK\r\n");
    }
}