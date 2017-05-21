#include "myftp.h"

char *get_file_type(struct dirent *dirent_struct)
{
    if (dirent_struct->d_type == DT_DIR)
        return ("dir");
    else if (dirent_struct->d_type == DT_REG)
        return ("file");
    return ("");
}

void handle_mlsd(char **parameters, t_client *client) 
{
    struct dirent *dirent_struct;
    DIR *directory;
    struct stat file;
    char modes[11];
    
    if (client->data_fd == -1)
        send_message(client, "425 Use PORT or PASV first\r\n");
    else 
    {
        directory = opendir(".");
        while ((dirent_struct = readdir(directory)))
        {
            if (stat(dirent_struct->d_name, &file) == 0)
	        {
                set_modes(&modes, &file);
                send_data(client, "Size=%d;Modify=19990929011440;Perm=%s;Type=%s; %s\r\n", file.st_size, modes, get_file_type(dirent_struct), dirent_struct->d_name);
            }
        }
        close_data(client);
        send_message(client, "226 Directory send OK\r\n");
    }
}