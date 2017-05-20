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
#include <stdarg.h>
#include <string.h>
#include <dirent.h>
#define TRUE	1
#define FALSE	0
#define MAX_PORT 65535
#define bool int
#define BUFFER_SIZE 2048
#define _GNU_SOURCE 

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
	int data_fd;
	struct sockaddr_in in;
	bool connected;
	char *remote_host;
	int active_mode;
	int remote_port;
	t_file *current_file;
	bool receiving;
	char *transfert_type;
	t_server *server;
	char *pwd;
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
void send_data(t_client *client, char *msg, ...);
void send_message(t_client *client, char *msg, ...);
void close_data(t_client *client);
//char *get_ip();

// command handlers //
void handle_user(char **parameters, t_client *client);
void handle_pass(char **parameters, t_client *client);
void handle_auth(char **parameters, t_client *client);
void handle_syst(char **parameters, t_client *client);
void handle_feat(char **parameters, t_client *client);
void handle_pwd(char **parameters, t_client *client);
void handle_type(char **parameters, t_client *client);
void handle_port(char **parameters, t_client *client);
void handle_pasv(char **parameters, t_client *client);
void handle_list(char **parameters, t_client *client);

static const t_command commands[] = {
	{"USER", handle_user},
	{"PASS", handle_pass},
	{"AUTH", handle_auth},
	{"SYST", handle_syst},
	{"FEAT", handle_feat},
	{"PWD", handle_pwd},
	{"TYPE", handle_type},
	{"PORT", handle_port},
	{"PASV", handle_pasv},
	{"LIST", handle_list},
	{0, 0}
};
#endif