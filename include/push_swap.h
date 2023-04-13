/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:44:02 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/13 11:50:36 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(Value) (Value < 0 ? -Value : Value)

enum				e_type
{
	T_STACK = 1,
	ARRAY = 2
};

typedef struct s_structure
{
	struct s_stack	*head;
	struct s_stack	*tail;
	int				size;
}					t_body;

typedef struct s_stack
{
	int				content;
	int				expected_index;
	int				current_index;
	int				target_current;
	int				price_a;
	int				price_b;
	struct s_stack	*next;
}					t_stack;

//	UTILS
char				**ft_split(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isnumeric(char *str);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_tablen(char **array);
size_t				stack_len(t_stack *stack);
void				ft_putstr_fd(char *s, int fd);
long int			ft_atoi(const char *str);

//	PRINT
size_t				ft_convert(char type, va_list ap);
int					ft_print_char(char c);
int					ft_printf(const char *format, ...);

//	ERROR
void				free_tab(char **array);
void				free_stack(t_body *structure);
void				ft_error(void *ptr, int type);

//	PARSING
int					is_double(long int nbr, t_body *structure);
char				**ft_get_arg(int argc, char **argv);

//	STACK
t_body				*init_body(void);
t_body				*fill_structure(char **array, t_body *structure);
void				computing_theorical_postion(t_stack *stack, int size);

//	OPERATION
void				swap_a(t_body *structure);
void				swap_b(t_body *structure);
void				swap_ab(t_body *structure_a, t_body *structure_b);
void				push_a(t_body *src, t_body *dest);
void				push_b(t_body *src, t_body *dest);
void				rotate_a(t_body *structure);
void				rotate_b(t_body *structure);
void				rotate_ab(t_body *structure_a, t_body *structure_b);
void				reverse_rotate_a(t_body *structure);
void				reverse_rotate_b(t_body *structure);
void				reverse_rotate_ab(t_body *structure_a, t_body *structure_b);

// SORT
int					is_sorted(t_stack *stack);
void				sort_three(t_body *stack);
void				sort(t_body *stack_a, t_body *stack_b);
int					get_small_expected_index(t_body *stack);
void				get_target_current(t_body *stack_a, t_body *stack_b);
void				get_price(t_body *stack_a, t_body *stack_b);
void				do_sales(t_body *stack_a, t_body *stack_b);
void				solve(t_body *stack_a, t_body *stack_b, int price_a,
						int price_b);

#endif