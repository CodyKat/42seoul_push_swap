CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c					\
	   parsing.c				\
	   sort.c					\
	   sort_big_case.c			\
	   sort_big_case_2.c		\
	   sort_case_4.c			\
	   clean_commands.c			\
	   command1.c				\
	   command2.c				\
	   check_is_sorted.c		\
	   ft_itoa.c				\
	   ft_split.c				\
	   util.c					\
	   set_pivots.c				\
	   sort_small_size.c		\
	   move_block_upsidedown.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS}

clean : 
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
