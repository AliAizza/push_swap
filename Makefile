SRC=  push_swap.c moves.c sort.c sort_check.c utils.c utils1.c

NAME= push_swap.a

OBJ= ${SRC:.c=.o}

CC= gcc

FLAGS= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${SRC}
		${CC} ${FLAGS} -c ${SRC}
		ar -rc ${NAME} ${OBJ}

clean:
		rm -f ${OBJ}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
