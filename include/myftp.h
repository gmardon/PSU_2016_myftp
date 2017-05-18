#ifndef _MY_FTP_H_
#define _MY_FTP_H_
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#define TRUE	1
#define FALSE	0
#define MAX_PORT 65535
#define bool int
#define BUFFER_SIZE 2048

typedef struct s_file
{
	struct stat	*file;
	char *name;
	int	size;
	int	offset;
	void *content;
}						t_file;

typedef struct s_server
{
	int fd;
	struct sockaddr_in in;
	char *path;
}						t_server;

typedef struct s_client
{
	int fd;
	struct sockaddr_in in;
	bool connected;
	char *remote_host;
	int remote_port;
	fd_set read_fds;
	t_file *current_file;
	int len;
	char tmp[2048];
	bool receiving;
	bool sending;
	t_server *server;
}						t_client;

typedef struct s_command
{
	char *name;
	void (*handler)(char **parameters, t_client *client);
}						t_command;

void print_error(char *msg, int exit_code);
void init_server(int port, char *path);
void handle_child(t_client *client);
char *get_client_addr(struct sockaddr_in client);
int get_client_port(struct sockaddr_in client);
char *get_next_line(int fd);
void *my_malloc(int size);
char **strsplit(const char* str, const char* delim);
void close_client(t_client *client);

// command handlers //
void handle_user(char **parameters, t_client *client);
void handle_pass(char **parameters, t_client *client);
#endif