/*
** server.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

t_client *alloc_new_client(int socket, struct sockaddr_in in, t_server *server)
{
	t_client	*client;

	if (!(client = (t_client*)malloc(sizeof(t_client))))
		return (NULL);
	client->fd = socket;
	client->in = in;
    client->data_fd = -1;
	client->connected = TRUE;
	client->current_file = NULL;
	client->receiving = FALSE;
	client->server = server;
    client->username = NULL;
    client->password = NULL;
    client->opts = my_malloc(128 * sizeof(t_opt));
    client->home = "";
    memset(client->opts, 0, 128);
	return (client);
}

void accept_client(t_server *server)
{
	t_client *client;
	socklen_t length;
	int socket;
	struct sockaddr_in in;
	pid_t child_pid;

	length = sizeof(in);
	if ((socket = accept(server->fd, (struct sockaddr*)&in, &length)) == -1)
		print_error("Can't accept one client connection", -1);
	else
	{
		if (!(client = alloc_new_client(socket, in, server)))
			return ;
		child_pid = fork();
		if (child_pid == 0) {
            server->pid = getpid();
			handle_client(client);
        }
	}
}

t_server *get_socket(int port)
{
	t_server	*server;
	int			opt;

	opt = TRUE;
	server = (t_server*)my_malloc(sizeof(struct s_server));
	if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		print_error("Can't create socket", -1);
	server->in.sin_family = AF_INET;
	server->in.sin_addr.s_addr = INADDR_ANY;
	server->in.sin_port = htons(port);
	if ((setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) < 0)
		print_error("Can't allow multiple connection on socket", -1);
	if ((bind(server->fd, (struct sockaddr *)&server->in, sizeof(server->in))) < 0)
		print_error("Can't bind socket", -1);
	if ((listen(server->fd, 3)) == -1)
		print_error("Can't listen the socket", -1);
	return (server);
}

void init_server(int port, char *anonymous_path)
{
	t_server *server;
    char *path;

	if (port > 0 && port <= MAX_PORT)
	{
		server = get_socket(port);
        path = my_malloc(256 * sizeof(char));
        getcwd(path, 256);
        server->anonymous_path = concat_path(path, anonymous_path);
		printf("start on port %d, waiting for connections...\n", port);
		while (TRUE)
			accept_client(server);
	}
	else
		printf("Give me a real port..\n");
}