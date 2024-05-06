# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 13:24:48 by lburkins          #+#    #+#              #
#    Updated: 2024/05/06 14:09:22 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		=		server
CLIENT		=		client

LIBFT		=		libft/libft.a

CLIENT_SRC	=		client_bonus.c
SERVER_SRC	=		server_bonus.c

CLIENT_OBJ	=		$(CLIENT_SRC:.c=.o)
SERVER_OBJ	=		$(SERVER_SRC:.c=.o)

CC			=		cc

RM			=		@rm -f

CFLAGS		=		-Wall -Wextra -Werror

ANSI_GREEN := \033[0;32m
ANSI_CYAN := \033[0;36m
ANSI_RESET := \033[0m

all:		$(LIBFT) $(CLIENT) $(SERVER)
	
$(LIBFT):
				@make -C ./libft

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT):	$(CLIENT_OBJ)
				@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)
				@echo "** $(ANSI_GREEN)MiniTalk Client Compiled$(ANSI_RESET) ✅ **"

$(SERVER):	$(SERVER_OBJ)
				@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)
				@echo "** $(ANSI_GREEN)MiniTalk Server Compiled$(ANSI_RESET) ✅ **"

clean:
				@make clean -C libft
				$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
				@echo "** $(ANSI_CYAN)MiniTalk Cleaning Complete$(ANSI_RESET) 🧹 **"

fclean:		clean
				@make fclean -C libft
				$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(SERVER) $(CLIENT)
				@echo "** $(ANSI_CYAN)MiniTalk F Cleaning Complete$(ANSI_RESET) 🧹 **"

re:			fclean all

.PHONY:		all clean fclean re
