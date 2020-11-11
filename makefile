CC	=	gcc

SRCS	=	src/main.c	\
			src/copy.c  \

OBJS	=	$(SRCS:.c=.o)

CFLAGS  +=      -W -Wextra -Wall

CPPFLAGS +=     -I include/

NAME	=	CopyPastaFinder

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC)  $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re