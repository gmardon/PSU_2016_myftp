/*
** main.c for myftp in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_myftp/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 28 13:18:53 2016 Guillaume MARDON
** Last update Fri Dec 16 17:46:00 2016 Guillaume MARDON
*/
#include "myftp.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
		init_server(atoi(argv[1]), argv[2]);
	else
	{
		printf("You must give me an arg as listen port ");
		printf("and if you want a custom start path !\n");
        return (1);
    }
	return (0);
}