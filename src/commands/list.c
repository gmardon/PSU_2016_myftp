/*
** list.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/commands/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
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