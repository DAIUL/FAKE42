NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I ./includes

#################################################################################

SRCS = parsing/parsing.c\
		parsing/parsing_2.c\
		parsing/parsing_3.c\
		parsing/parsing_utils.c\
		parsing/parsing_utils_2.c\
		parsing/parsing_error.c\
		recasting/recasting.c\
		recasting/recasting_utils.c\
		main.c
LIBX_PATH = Minilibx/
LIBFT_PATH = libft/
LIBFT = libft/libft.a
LIBX = Minilibx/libmlx.a
LIB = -L ${LIBFT_PATH} -lft
OBJS = ${SRCS:.c=.o}

#################################################################################

all: ${LIBFT} ${LIBX} ${NAME}

${LIBFT}:
	make -sC ${LIBFT_PATH} all
${LIBX}:
	make -C Minilibx/

#${LIBX}:
#make -C Minilibx/

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB} -L./Minilibx -lmlx -lXext -lX11

clean:
	make -sC ${LIBFT_PATH} fclean
	rm -f ${OBJS} ${LIBX}

fclean: clean
	rm -f ${NAME}

re: fclean all

#################################################################################