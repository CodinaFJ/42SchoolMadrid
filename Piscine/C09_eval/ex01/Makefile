NAME = libft.a

CUR_DIR	=	$(shell pwd)

SRC_DIR	=	$(CUR_DIR)/srcs

H_DIR	=	$(CUR_DIR)/includes

MY_SOURCES	=	$(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_swap.c

MY_OBJECTS	=	$(MY_SOURCES:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror

all: libft.a

libft.a: $(MY_OBJECTS)
	ar rc libft.a $(MY_OBJECTS)

$(SRC_DIR)/ft_putchar.o: $(SRC_DIR)/ft_putchar.c $(H_DIR)/ft.h
	cc -c $(SRC_DIR)/ft_putchar.c -o $(SRC_DIR)/ft_putchar.o $(CFLAGS)

$(SRC_DIR)/ft_putstr.o: $(SRC_DIR)/ft_putstr.c $(H_DIR)/ft.h
	cc -c $(SRC_DIR)/ft_putstr.c -o $(SRC_DIR)/ft_putstr.o $(CFLAGS)

$(SRC_DIR)/ft_strlen.o: $(SRC_DIR)/ft_strlen.c $(H_DIR)/ft.h
	cc -c $(SRC_DIR)/ft_strlen.c -o $(SRC_DIR)/ft_strlen.o $(CFLAGS)

$(SRC_DIR)/ft_strcmp.o: $(SRC_DIR)/ft_strcmp.c $(H_DIR)/ft.h
	cc -c $(SRC_DIR)/ft_strcmp.c -o $(SRC_DIR)/ft_strcmp.o $(CFLAGS)

$(SRC_DIR)/ft_swap.o: $(SRC_DIR)/ft_swap.c $(H_DIR)/ft.h
	cc -c $(SRC_DIR)/ft_swap.c -o $(SRC_DIR)/ft_swap.o $(CFLAGS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all