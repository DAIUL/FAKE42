NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FILE_SOLONG = so_long.c\
		mapping.c\
		check.c\
		move.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		enemies.c\
		sprite.c
PRINTF_PATH = ft_printf/
LIBX_PATH = Minilibx/
LIBFT_PATH = libft/
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIBX = Minilibx/libmlx.a
LIB = -L ${PRINTF_PATH} -lftprintf -L ${LIBFT_PATH} -lft
OBJS = ${FILE_SOLONG:.c=.o}

all: ${PRINTF} ${LIBFT} ${LIBX} ${NAME}

${LIBFT}:
	make -sC ${LIBFT_PATH} all
${PRINTF}:
	make -sC ${PRINTF_PATH} all
${LIBX}:
	make -C Minilibx/

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB} -L./Minilibx -lmlx -lXext -lX11

clean:
	make -sC ${PRINTF_PATH} fclean
	make -sC ${LIBFT_PATH} fclean
	rm -f ${OBJS} ${LIBX}

fclean: clean
	rm -f ${NAME}

re: fclean all
