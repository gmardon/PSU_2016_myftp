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

	printf("Client disconnected <%s:%d>\n", get_client_addr(client->in), get_client_port(client->in));
	exit(0);
}

void handle_client(t_client *client)
{
	char *buffer;

	printf("New client connected from <%s:%d>\n", get_client_addr(client->in), get_client_port(client->in));
    send_message(client, "220 Hello my friend\r\n");
    while (42)
	{
        buffer = get_next_line(client->fd);
		if (buffer)
		{
            printf("> %s\n", buffer);
            if(!handle_command(buffer, client)) {
                send_message(client, "500 Unknown command.\r\n");
            }
		}
		else
			close_client(client);
	}
}