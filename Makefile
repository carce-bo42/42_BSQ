SRCS    = check1.c check2.c check3.c controlcheck.c empy.c filetools.c main.c printer.c read.c search.c
OBJS    = ${SRCS:.c=.o}
INCS  	= ./
NAME    = bsq
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: 	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

run : 
	./${NAME}

clean :	
	${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o
