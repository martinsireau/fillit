NAME = fillit.a

SRC =	libft.a\
		main.c\

SRCO = $(SRC:.c=.o);

all: $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean :
	rm -f $(SRCO);

fclean : clean
	rm -f $(NAME);

re : fclean all

