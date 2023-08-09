MAKEFLAGS += --silent

CC = cc
CFLAGS = -Wall -Wextra -Werror
FILE_CL = client.c
FILE_SE = server.c
CLIENT = client
SERVER = server
PRINTF_PATH = ft_printf/
PRINTF = ft_printf/libftprintf.a
LIB = -L ${PRINTF_PATH} -lftprintf
OBJS_C = ${FILE_CL:.c=.o}
OBJS_S = ${FILE_SE:.c=.o}

all: ${PRINTF} ${CLIENT} ${SERVER}

${PRINTF}:
	make -sC ${PRINTF_PATH} all

${CLIENT}: ${OBJS_C}
	${CC} ${CFLAGS} ${OBJS_C} ${LIB} -o ${CLIENT} \
	&& echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Mes clients au bord de l'eau ca fait un radeau (づ ◕‿◕ )づ\033[0m"

${SERVER}: ${OBJS_S}
	${CC} ${CFLAGS} ${OBJS_S} ${LIB} -o ${SERVER} \
	&& echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Pareil le server (づ ◕‿◕ )づ\033[0m"

clean:
	make -sC ${PRINTF_PATH} fclean
	rm -f ${OBJS_C} ${OBJS_S}

fclean: clean
	rm -f ${CLIENT} ${SERVER} \
	&& echo "\033[1;38;2;255;95;31m°˖✧◝(⁰▿⁰)◜✧˖° Voila c'est tout propre °˖✧◝(⁰▿⁰)◜✧˖°\033[0m"

re: fclean all
