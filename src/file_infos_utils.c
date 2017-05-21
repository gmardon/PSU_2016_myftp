#include "myftp.h"

void set_modes(char *mode, struct stat *file)
{
    mode[1] = (file->st_mode & S_IRUSR) ? 'r' : '-';
    mode[2] = (file->st_mode & S_IWUSR) ? 'w' : '-';
    mode[3] = (file->st_mode & S_IXUSR) ? 'x' : '-';
    mode[4] = (file->st_mode & S_IRGRP) ? 'r' : '-';
    mode[5] = (file->st_mode & S_IWGRP) ? 'w' : '-';
    mode[6] = (file->st_mode & S_IXGRP) ? 'x' : '-';
    mode[7] = (file->st_mode & S_IROTH) ? 'r' : '-';
    mode[8] = (file->st_mode & S_IWOTH) ? 'w' : '-';
    mode[9] = (file->st_mode & S_IXOTH) ? 'x' : '-';
}

int write_file_infos(char *filename, char *buffer, struct stat *file)
{
    char date[16];
    char mode[11];
    int b_mask;
    struct group *group_info;
    struct passwd *pass_info;

    memset(mode, '-', 11);
    group_info = getgrgid(file->st_gid);
    pass_info = getpwuid(file->st_uid);
    if (pass_info != NULL && group_info != NULL)
    {
        b_mask = file->st_mode & S_IFMT;
        mode[0] = b_mask == S_IFDIR ? 'd' : b_mask == S_IFREG ? '-' : -1;
        if (mode[0] == -1)
            return (-1);
        set_modes(mode, file);
        strftime(date, 13, "%b %d %H:%M", localtime(&(file->st_mtime)));
        sprintf(buffer,"%s %3d %-4s %-4s %8d %12s %s\r\n", mode, file->st_nlink, pass_info->pw_name, group_info->gr_name, file->st_size, date, filename);
    }
    return (1);
}