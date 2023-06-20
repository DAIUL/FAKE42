# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpuig <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:17:24 by qpuig             #+#    #+#              #
#    Updated: 2023/03/13 14:55:52 by qpuig            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	chardigit.c\
	hexa.c\

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
