NAME = libft.a

SOURCES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
			ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncat.c \
			ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_isspace.c ft_maxmin.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_split.c frees.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_isblank.c ft_ispunct.c ft_memrchr.c

BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

MY_OBJECTS	=	$(SOURCES:.c=.o)

MY_BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

bonus: $(MY_OBJECTS) $(MY_BONUS_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS) $(MY_BONUS_OBJECTS) 

clean:
	rm $(MY_OBJECTS)

fclean: clean
	rm $(NAME)

re: fclean all