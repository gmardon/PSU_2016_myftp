#include "myftp.h"

void send_data(t_client *client, char *msg, ...)
{
    char *content;
    char *buffer;
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

void close_client(t_client *client)
{
	close(client->fd);
	printf("Client disconnected <%s:%d>\n", get_client_addr(client->in), get_client_port(client->in));
	exit(0);
}

void handle_client(t_client *client)
{
	char *buffer;
	int	read_size;

	read_size = 0;

	printf("New client connected from <%s:%d>\n", get_client_addr(client->in), get_client_port(client->in));
    send_data(client, "220 Hello my friend\r\n");
    while (42)
	{
        buffer = get_next_line(client->fd);
		if (buffer)
		{
            printf("> %s\n", buffer);
			//if (client->receiving)
			//	receiving_file(client, buffer, res);
			//else
			//{
				//print_received(client, buffer);
				handle_command(buffer, client);
				//memset(buffer, '\0', BUFFER_SIZE);
			//}
		}
		else
			close_client(client);
	}
}