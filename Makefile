SERVER = server
CLIENT = client
LIB = libft/libft.a
FLG = -Wall -Wextra -Werror

all:		$(SERVER) $(CLIENT)

$(LIB):
			make -C libft

$(SERVER):	$(LIB)
			gcc $(FLG) server.c -o $(SERVER) $(LIB)

$(CLIENT):	$(LIB)
			gcc $(FLG) client.c -o $(CLIENT) $(LIB)

clean:
			rm -f server
			rm -f client

fclean:		clean
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
