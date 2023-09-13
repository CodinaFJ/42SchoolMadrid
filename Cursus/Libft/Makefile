#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: Libft																	#\
#########################################################################################

NAME = libft.a

CC	= cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	.
SRC_DIR	=	srcs/

########################################################################################\
Sources & objects for Libft
########################################################################################

FILES	=	Str_cmp/ft_memcmp \
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
			Alloc_mem/ft_calloc \
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
			Char_handle/ft_isspace \
			Char_handle/ft_isupper \
			Char_handle/ft_tolower \
			Char_handle/ft_toupper \
			IO_streams/ft_putchar_fd \
			IO_streams/ft_putendl_fd \
			IO_streams/ft_putnbr_fd \
			IO_streams/ft_putstr_fd \
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

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))
			
########################################################################################\
Bonus sources and objects for Libft
########################################################################################

BFILES	=	Bonus/ft_lstadd_back_bonus \
			Bonus/ft_lstadd_front_bonus \
			Bonus/ft_lstclear_bonus \
			Bonus/ft_lstdelone_bonus \
			Bonus/ft_lstiter_bonus \
			Bonus/ft_lstlast_bonus \
			Bonus/ft_lstmap_bonus \
			Bonus/ft_lstnew_bonus \
			Bonus/ft_lstsize_bonus \

BSRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(BFILES)))
BOBJS	=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(BFILES)))

########################################################################################\
Colors
########################################################################################

DEF_COLOR = \033[0;39m
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
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

$(SRC_DIR)%.o:$(SRC_DIR)%.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

bonus: $(OBJS) $(BOBJS)
	@$(AR) $(NAME) $(OBJS) $(BOBJS)
	@echo "\n$(G)Library with bonus compiled!$(DEF_COLOR)-> $(NAME)\n"

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all