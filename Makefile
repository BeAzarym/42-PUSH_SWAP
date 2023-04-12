NAME	=	push_swap
BONUS	=	checker

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
		stack/swap_stack.c \
		stack/push_stack.c \
		stack/rotate_stack.c \
		stack/reverse_rotate_stack.c \
		sort/sorting.c \
		sort/position.c \
		sort/pricing.c \
		sort/solving.c \

SRC_BONUS = checker_bonus.c \
			parsing/parsing_bonus.c \
			error/ft_error_bonus.c \
			utils/ft_putstr_fd_bonus.c \
			utils/ft_split_bonus.c \
			utils/ft_strlen_bonus.c \
			utils/ft_isnumeric_bonus.c \
			utils/ft_strcmp_bonus.c \
			utils/ft_strdup_bonus.c \
			utils/ft_atoi_bonus.c \
			stack/init_stack_bonus.c \
			stack/swap_stack_bonus.c \
			stack/push_stack_bonus.c \
			stack/rotate_stack_bonus.c \
			stack/reverse_rotate_stack_bonus.c \
			operation/do_op.c \
			gnl/get_next_line_bonus.c \
			gnl/get_next_line_utils_bonus.c \


SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
SRCS_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS))

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

INC_DIR = include
SRC_DIR = src
BONUS_DIR = bonus

CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

bonus:	$(BONUS)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJS)

$(BONUS):	$(OBJS_BONUS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(BONUS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re:	fclean all

.PHONY:	all re clean fclean bonus