NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FILE_PUSHSWAP = push_swap.c\
		swap_and_push.c\
		check.c\
		rotate.c\
		sort_1.c\
		utils_1.c\
		utils_2.c\
		opti_count.c
PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIB = -L ${PRINTF_PATH} -lftprintf -L ${LIBFT_PATH} -lft
OBJS = ${FILE_PUSHSWAP:.c=.o}

all: ${PRINTF} ${LIBFT} ${NAME}

${LIBFT}:
	make -sC ${LIBFT_PATH} all
${PRINTF}:
	make -sC ${PRINTF_PATH} all

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB}

clean:
	make -sC ${PRINTF_PATH} fclean
	make -sC ${LIBFT_PATH} fclean
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all