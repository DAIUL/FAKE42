NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I ./includes

#################################################################################

SRCS = parsing/parsing.c\
		parsing/parsing_2.c\
		parsing/parsing_utils.c\
		main.c
#LIBX_PATH = Minilibx/
LIBFT_PATH = libft/
LIBFT = libft/libft.a
#LIBX = Minilibx/libmlx.a
LIB = -L ${LIBFT_PATH} -lft
OBJS = ${SRCS:.c=.o}

#################################################################################

all: ${LIBFT} ${NAME}

${LIBFT}:
	make -sC ${LIBFT_PATH} all

#${LIBX}:
#make -C Minilibx/

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB} 

clean:
	make -sC ${LIBFT_PATH} fclean
	rm -f ${OBJS} ${LIBX}

fclean: clean
	rm -f ${NAME}

re: fclean all

#################################################################################