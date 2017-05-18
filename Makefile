NAME	=	server

CC	=	gcc

DIR	=	src/

SRC	=	$(DIR)main.c $(DIR)server.c $(DIR)utils.c $(DIR)client.c $(DIR)client_utils.c $(DIR)get_next_line.c $(DIR)commands/user.c $(DIR)command_handler.c $(DIR)commands/pass.c

OBJS	=	$(SRC:.c=.o)

CFLAGS  = 	-Wall -Wextra -I./include/ 

RM	=	rm -f


all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
