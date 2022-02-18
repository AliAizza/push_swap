SRC=  error_check.c find.c moves.c push_swap.c sort.c sort_3.c sort_5.c sort_100.c sort_check.c sort_utils.c utils.c utils1.c utils2.c

CHECKER_SRC= get_next_line.c get_next_line_utils.c checker.c error_check.c sort_100.c find.c moves.c sort.c sort_3.c sort_5.c sort_check.c sort_utils.c utils.c utils1.c utils2.c

NAME= push_swap

CHECKER_NAME= checker

CC= gcc

FLAGS= -Wall -Wextra -Werror

all:		${NAME}

checker:	${CHECKER_SRC}
			@${CC} ${FLAGS} ${CHECKER_SRC} -o ${CHECKER_NAME}

${NAME}:	${SRC}
			@${CC} ${FLAGS} ${SRC} -o ${NAME}

clean:
			rm -f ${NAME}

fclean:
			rm -f ${NAME} ${CHECKER_NAME}

re:			fclean all

.PHONY:		all clean fclean re
