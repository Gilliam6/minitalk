SOURCE	=	server.c client.c

HEADER	=	includes/minitalk.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	minitalk.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc ${CFLAGS} -Ilibft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean bonus