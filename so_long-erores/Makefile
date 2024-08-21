# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 17:32:31 by vtrubina          #+#    #+#              #
#    Updated: 2024/08/21 23:44:47 by vtrubina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 # -fsanitize=address
MFLAGS	= 	-L./mlx_linux -lmlx_Linux -lXext -lX11
IFLAGS  = 	-I. -I./libft -I./mlx_linux
LFLAGS	=	-L./libft -lft
BFLAGS	=	0
MLX_DIR = 	./mlx_linux

MLX		=	libmlx.a

SRC		=	srcs/main.c \
			srcs/exit.c \
			srcs/check.c \
			srcs/key_manager.c \
			srcs/parser.c \
			srcs/textures.c \
			srcs/images.c \
			srcs/bonus.c \
			srcs/utils.c \
			srcs/utils2.c \


OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ -D BONUS=$(BFLAGS)
			

$(NAME):	$(OBJ)
			$(MAKE) -C ./$(MLX_DIR)
			cp ./$(MLX_DIR)/$(MLX) .
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@


all:		$(NAME)

bonus:		BFLAGS = 1
bonus:		$(NAME)

clean:
			$(MAKE) -C libft clean
			rm -rf $(OBJ)
fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C ./$(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
