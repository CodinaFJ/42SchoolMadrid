#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: Libft																	#\
#########################################################################################

NAME = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDIR	=	includes
SDIR	=	srcs

########################################################################################\
Sources & objects for Libft
########################################################################################

FILES	=	Alloc_mem/ft_calloc \
			Arithmetic/ft_atoi \
			Arithmetic/ft_itoa \
			Arithmetic/ft_maxmin \
			Char_handle/ft_isalnum \
			Char_handle/ft_isalpha \
			Char_handle/ft_isascii \
			Char_handle/ft_isblank \
			Char_handle/ft_isdigit \
			Char_handle/ft_islower \
			Char_handle/ft_isprint \
			Char_handle/ft_isupper \
			Char_handle/ft_tolower \
			Char_handle/ft_toupper \
			IO_streams/ft_putchar_fd \
			IO_streams/ft_putendl_fd \
			IO_streams/ft_putnbr_fd \
			IO_streams/ft_putstr_fd \
			Str_cmp/ft_memcmp \
			Str_cmp/ft_strcmp \
			Str_cpycat/ft_bzero \
			Str_cpycat/ft_memccpy \
			Str_cpycat/ft_memcpy \
			Str_cpycat/ft_memmove \
			Str_cpycat/ft_memset \
			Str_cpycat/ft_split \
			Str_cpycat/ft_strcat \
			Str_cpycat/ft_strcpy \
			Str_cpycat/ft_strdup \
			Str_cpycat/ft_strlcat \
			Str_cpycat/ft_strlcpy \
			Str_cpycat/ft_strncat \
			Str_cpycat/ft_strncpy \
			Str_cpycat/ft_strtrim \
			Str_search/ft_memchr \
			Str_search/ft_memrchr \
			Str_search/ft_strchr \
			Str_search/ft_strjoin \
			Str_search/ft_strncmp \
			Str_search/ft_strnstr \
			Str_search/ft_strrchr \
			Str_search/ft_strstr \
			Str_search/ft_substr \
			Str_utils/frees \
			Str_utils/ft_striteri \
			Str_utils/ft_strlen \
			Str_utils/ft_strmapi \

SRCS	=	$(addprefix $(SRC_DIR)/, $(addsufix .c, $(FILES)))

OBJS	=	$(SRCS:.c=.o)
			
########################################################################################\
Bonus sources and objects for Libft
########################################################################################

BFILES	=	Bonus/ft_lstadd_back \
			Bonus/ft_lstadd_front \
			Bonus/ft_lstclear \
			Bonus/ft_lstdelone \
			Bonus/ft_lstiter \
			Bonus/ft_lstlast \
			Bonus/ft_lstmap \
			Bonus/ft_lstnew \
			Bonus/ft_lstsize \

BSRCS	=	$(addprefix $(SRC_DIR)/, $(addsufix .c, $(BFILES)))

BOBJS	=	$(BSRCS:.c=.o)

########################################################################################\
Colors
########################################################################################

CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################################################################################\
Rules
########################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

bonus: $(OBJS) $(BOBJS)
	$(AR) $(NAME) $(OBJS) $(BOBJS) 

clean:
	rm $(OBJS) $(BOBJS)

fclean: clean
	rm $(NAME)

re: fclean all