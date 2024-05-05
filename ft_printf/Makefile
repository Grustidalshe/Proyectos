# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 20:38:54 by vtrubina          #+#    #+#              #
#    Updated: 2023/11/18 00:48:18 by vtrubina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putchar.c ft_mix.c ft_found.c ft_printf.c
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
HEAD = ft_printf.h
LIB_GEN_CMD = ar -crs

all: $(NAME)

#%.o: %.c $(HEAD)
#	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIB_GEN_CMD) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
     
re: fclean all             

.PHONY: all clean fclean re bonus
