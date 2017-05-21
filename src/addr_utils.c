/*
** addr_utils.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

char *stick_addr(char *ipaddr, char *port1, char *port2, int len)
{
  ipaddr = strcat(ipaddr, ",");
  ipaddr = strcat(ipaddr, port1);
  ipaddr = strcat(ipaddr, ",");
  ipaddr = strcat(ipaddr, port2);
  ipaddr[len - 1] = '\0';
  return (ipaddr);
}

char *seek_addr(char *ipaddr, int porta, int portb)
{
  char *ipsta;
  int len;
  char *port1;
  char *port2;

  sprintf(port1, "%d", porta);
  sprintf(port2, "%d", portb);
  len = strlen(ipaddr) + strlen(port1) + strlen(port2) + 3;
  ipaddr = realloc(ipaddr, len * sizeof(char));
  while (*ipsta != '\0')
  {
    if (*ipsta == '.')
      *ipsta = ',';
     ipsta++;
  }
  ipaddr = stick_addr(ipaddr, port1, port2, len);
  return (ipaddr);
}