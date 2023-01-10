NAME = libft.a

SRC_DIR	=	./srcs/

H_DIR	=	./includes/

MY_SOURCES_F	=	ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c

SOURCES = $(addprefix $(SRC_DIR), $(MY_SOURCES_F))

MY_OBJECTS	=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	cc -c -I $(H_DIR) $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	ar rc $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re