# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 04:38:05 by vtrubina          #+#    #+#              #
#    Updated: 2024/04/24 06:14:57 by vtrubina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./includes
RM = rm -rf
SERVER = server
CLIENT = client
LIBFT = ./libft

OBJ_S = server.o
OBJ_C = client.o
%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

all: $(LIBFT) 
	$(MAKE) $(SERVER) 
	$(MAKE) $(CLIENT)

$(SERVER): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_S) $(LIBFT)

$(CLIENT): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) -o  $(CLIENT) $(OBJ_C) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT)

clean:
	$(RM) $(OBJ_S) $(OBJ_C)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
