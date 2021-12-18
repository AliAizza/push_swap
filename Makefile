SRC=  error_check.c find.c moves.c push_swap.c sort.c sort_100.c sort_3.c sort_5.c sort_check.c sort_utils.c utils.c

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
