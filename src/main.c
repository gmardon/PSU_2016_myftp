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