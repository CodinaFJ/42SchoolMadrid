NAME = bsq

SRC = error_crtl.c extended_matrix.c free_malllocs.c ft.c ft_str.c main.c prints.c read_map.c solver.c

OBJS = $(SRC:.c=.o)

INCLUDE = bsq.h ft.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all $(NAME)

.PHONY: all clean fclean
