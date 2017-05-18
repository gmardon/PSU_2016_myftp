#include "myftp.h"

char *get_client_addr(struct sockaddr_in client)
{
	return (inet_ntoa(client.sin_addr));
}

int get_client_port(struct sockaddr_in client)
{
	return (ntohs(client.sin_port));
}