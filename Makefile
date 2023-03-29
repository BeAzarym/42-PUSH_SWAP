NAME	=	push_swap

SRC	=	main.c \
		parsing/parsing.c \
		print/ft_print_tab.c \
		print/ft_printf.c \
		print/ft_printf_utils.c \
		print/ft_putstr_fd.c \
		utils/ft_split.c \
		utils/ft_strlen.c \
		utils/ft_isnumeric.c \
		utils/ft_strcmp.c \
		utils/ft_strdup.c \
		utils/ft_atoi.c \
		error/ft_error.c \
		stack/init_stack.c \
		stack/stack_handling.c \

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