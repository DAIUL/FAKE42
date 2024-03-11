MAKEFLAGS = --silent

NAME = zombie
SRC = Zombie.cpp\
		newZombie.cpp\
		randomChump.cpp\
		main.cpp
OBJ = ${SRC:.cpp=.o}
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}
		echo "\033[1;38;2;255;117;24m(づ ◕‿◕ )づ Files Updated (づ ◕‿◕ )づ\033[0m"

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME} \
			&& echo "\033[1;38;2;255;117;24m٩(◕‿◕)۶ $@ Compilation done ٩(◕‿◕)۶\033[0m"\
            || echo "\033[1;38;2;255;117;24m(・_・ ) $@ Compilation: Error (・_・ )\033[0m"

%.o: %.cpp
	${CC} ${FLAGS} -o $@ -c $<

clean:
	rm -rf ${OBJ} \
			&& echo "\033[1;38;2;255;117;24m˖⁺‧₊˚✦ Object clean ˖⁺‧₊˚✦\033[0m"\
            || echo "\033[1;38;2;255;117;24m(・_・ ) Object cleaning : Error (・_・ )\033[0m"

fclean: clean
	rm -rf ${NAME} \
			&& echo "\033[1;38;2;255;117;24m˖⁺‧₊˚✦ Executable clean ˖⁺‧₊˚✦\033[0m"\
            || echo "\033[1;38;2;255;117;24m(・_・ ) Executable cleaning : Error (・_・ )\033[0m"

re: fclean all