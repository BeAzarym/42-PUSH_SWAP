NAME	=	push_swap

SRC	=	parsing.c \
		main.c \
		utils/ft_split.c \
		utils/ft_strlen.c \
		ft_printf/ft_print_tab.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_utils.c \
		utils/ft_isdigit.c \
		utils/ft_strcmp.c \
		utils/ft_free_tab.c\
		utils/ft_strdup.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

INC_DIR = Include
SRC_DIR = Src

CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -I $(INC_DIR) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all re clean fclean bonus