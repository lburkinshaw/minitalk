# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 13:24:48 by lburkins          #+#    #+#              #
#    Updated: 2024/05/03 15:50:04 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=		server
CLIENT		=		client

LIBFT		=		libft/libft.a

CLIENT_SRC	=		client.c
SERVER_SRC	=		server.c

CLIENT_OBJ	=		$(CLIENT_SRC:.c=.o)
SERVER_OBJ	=		$(SERVER_SRC:.c=.o)

CC			=		cc

RM			=		rm -f

CFLAGS		=		-Wall -Wextra -Werror

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENT_OBJ)
				make -C ./libft
				$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

$(SERVER):	$(SERVER_OBJ)
				make -C ./libft
				$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)

clean:
				make clean -C libft
				$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean:		clean
				make fclean -C libft
				$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
