NAME = push_swap
CHECK = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
FILE_PUSHSWAP = push_swap.c\
		swap_and_push.c\
		check.c\
		rotate.c\
		sort_1.c\
		sort_2.c\
		utils_1.c\
		utils_2.c\
		opti_count.c\
		params.c\
		opti_count_2.c
FILE_CHECKER = checker.c\
				swap_and_push.c\
				check.c\
				rotate.c\
				swap_and_push2.c\
				params.c\
				rotate2.c\
				sort_1.c\
				sort_2.c\
				utils_1.c\
				utils_2.c\
				opti_count.c\
				opti_count_2.c\
				get_next_line/get_next_line_bonus.c\
				get_next_line/get_next_line_utils_bonus.c
PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIB = -L ${PRINTF_PATH} -lftprintf -L ${LIBFT_PATH} -lft
OBJS = ${FILE_PUSHSWAP:.c=.o}
OBJSCH = ${FILE_CHECKER:.c=.o}

all: ${PRINTF} ${LIBFT} ${NAME}

bonus: ${PRINTF} ${LIBFT} ${NAME} ${CHECK}

${LIBFT}:
	make -sC ${LIBFT_PATH} all
${PRINTF}:
	make -sC ${PRINTF_PATH} all

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB}

${CHECK}: ${OBJSCH}
	${CC} ${CFLAGS} ${OBJSCH} -o ${CHECK} ${LIB}

clean:
	make -sC ${PRINTF_PATH} fclean
	make -sC ${LIBFT_PATH} fclean
	rm -f ${OBJS}
	rm -f ${OBJSCH}

fclean: clean
	rm -f ${NAME}
	rm -f ${CHECK}

re: fclean all