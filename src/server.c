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
    client->pwd = "/";
    client->username = NULL;
    client->password = NULL;
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

t_server		*get_socket(int port)
{
	t_server	*server;
	int			opt;

	opt = TRUE;
	if (!(server = (t_server*)malloc(sizeof(struct s_server))))
		return (NULL);
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

void init_server(int port, char *path)
{
	t_server *server;

	if (port > 0 && port <= MAX_PORT)
	{
		server = get_socket(port);
		printf("start on port %d, waiting for connections...\n", port);
		while (TRUE)
			accept_client(server);
	}
	else
		printf("Give me a real port..\n");
}