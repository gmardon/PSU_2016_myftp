/*
** help.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/commands/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

void handle_help(__UNUSED__ char **parameters, t_client *client) 
{
    send_message(client, "214-The following commands are recognized.\r\n");
    send_message(client, "AUTH FEAT LIST PASS PASV PORT PWD SYST TYPE USER\r\n");
    send_message(client, "214 Help OK.");
}