/*
** client.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

void send_data(t_client *client, char *msg, ...)
{
    char *content;
    int len;
    va_list args;

	if (client->data_fd)
	{
        va_start(args, msg);
        len = vasprintf(&content, msg, args);
        printf("< [DATA] %s", content);
        write(client->data_fd, content, len);
        va_end(args);
    }
}

void send_message(t_client *client, char *msg, ...)
{
    char *content;
    int len;
    va_list args;

	if (client->fd)
	{
        va_start(args, msg);
        len = vasprintf(&content, msg, args);
        printf("< %s", content);
        write(client->fd, content, len);
        va_end(args);
    }
}

void close_data(t_client *client)
{
    if (client->data_fd != -1)
	    close(client->data_fd);
    client->data_fd = -1;
}

void close_client(t_client *client)
{
    if (client->data_fd != -1)
        close(client->data_fd);

    if (client->fd != -1)
	    close(client->fd);

	printf("Client disconnected <%s:%d>\n",
        get_client_addr(client->in), get_client_port(client->in));
	exit(0);
}

void handle_client(t_client *client)
{
	char *buffer;

	printf("New client connected from <%s:%d>\n",
        get_client_addr(client->in), get_client_port(client->in));
    send_message(client, "220 Hello my friend\r\n");
    while (42)
	{
        buffer = get_next_line(client->fd);
		if (buffer)
		{
            printf("> %s\n", buffer);
            if (!handle_command(buffer, client))
            {
                send_message(client, "500 Unknown command.\r\n");
            }
		}
		else
			close_client(client);
	}
}