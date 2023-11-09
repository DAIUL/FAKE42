# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:49:04 by qpuig             #+#    #+#              #
#    Updated: 2023/10/23 16:49:04 by qpuig            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################################

MAKEFLAGS = --silent

GCC = gcc
CFLAGS = -Werror -Wall -Wextra -pthread
RM = rm -f

###############################################

NAME = philo
SRCS = philo.c\
		thread.c\
		utils.c\
		time.c
OBJS = ${SRCS:.c=.o}

###############################################

all: ${NAME}
	echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Je pense donc je suis (づ ◕‿◕ )づ\033[0m"

${NAME}: ${OBJS}
	${GCC} ${CFLAGS} ${OBJS} -o ${NAME} -g

clean: 
	${RM} ${OBJS}
	echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Tout propre (づ ◕‿◕ )づ\033[0m"

fclean: clean
	${RM} ${NAME}
	echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Je pense donc j'essuie (づ ◕‿◕ )づ\033[0m"

re: fclean all

###############################################