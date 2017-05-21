/*
** client_utils.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

char *get_client_addr(struct sockaddr_in client)
{
	return (inet_ntoa(client.sin_addr));
}

int get_client_port(struct sockaddr_in client)
{
	return (ntohs(client.sin_port));
}