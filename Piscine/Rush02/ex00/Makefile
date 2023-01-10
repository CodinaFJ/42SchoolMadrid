NAME = rush-02
SRC = dict_lst.c digest_file.c free.c ft_putstr.c input_mgmt.c main.c strs_from_file_mgmt.c
OBJS = $(SRC:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror 

$(NAME) : $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) -Iincludes $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
