HEADIR = includes

SRCS 	= ft_printf.c ft_print_nbr.c ft_print_ptr.c ft_putnbrhex_fd.c ft_print_str.c leacks_cheker_ex.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADIR}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C libft
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar rcs ${NAME} ${OBJS}
	
all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME}
			${RM} libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re