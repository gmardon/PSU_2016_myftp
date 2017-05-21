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
  for (ipsta = ipaddr; *ipsta != '\0'; ipsta++)
    if (*ipsta == '.')
      *ipsta = ',';
  ipaddr = stick_addr(ipaddr, port1, port2, len);
  return (ipaddr);
}