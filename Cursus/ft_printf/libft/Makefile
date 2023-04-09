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
SRC_DIR	=	.

########################################################################################\
Sources & objects for Libft
########################################################################################

FILES	=	ft_memcmp \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_split \
			ft_strdup \
			ft_strlcat \
			ft_strlcpy \
			ft_strtrim \
			ft_calloc \
			ft_atoi \
			ft_itoa \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_tolower \
			ft_toupper \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putnbr_base \
			ft_putnbr_hex \
			ft_putstr_fd \
			ft_memchr \
			ft_strchr \
			ft_strjoin \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_substr \
			ft_striteri \
			ft_strlen \
			ft_strmapi \

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addsuffix .o, $(FILES))
			
########################################################################################\
Bonus sources and objects for Libft
########################################################################################

BFILES	=	ft_lstadd_back_bonus \
			ft_lstadd_front_bonus \
			ft_lstclear_bonus \
			ft_lstdelone_bonus \
			ft_lstiter_bonus \
			ft_lstlast_bonus \
			ft_lstmap_bonus \
			ft_lstnew_bonus \
			ft_lstsize_bonus \

BSRCS	=	$(addsuffix .c, $(BFILES))
BOBJS	=	$(addsuffix .o, $(BFILES))

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
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $(NAME)\n"

%.o:%.c
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY: all bonus clean fclean re