/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:44:02 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 16:11:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum				e_type
{
	T_STACK = 1,
	ARRAY = 2
};

typedef struct s_structure
{
	struct s_stack	*head;
	struct s_stack	*tail;
}					t_structure;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

//	UTILS
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isnumeric(char *str);
char				*ft_strdup(const char *s);
size_t				ft_tablen(char **array);
void				ft_putstr_fd(char *s, int fd);
long int			ft_atoi(const char *str);

//	PRINT
size_t				ft_convert(char type, va_list ap);
int					ft_print_char(char c);
int					ft_printf(const char *format, ...);
void				ft_print_tab(char **array);
void				print_stack(t_structure *structure_a, t_structure *structure_b);

//	ERROR
void				free_tab(char **array);
void				free_stack(t_structure *structure);
void				ft_error(void *ptr, int type);

//	PARSING
int					is_double(long int nbr, t_structure *structure);
char				**ft_get_arg(int argc, char **argv);

//	STACK
t_stack				*init_stack(int nbr);
t_structure			*init_structure();
t_structure			*create_stack(int nbr, t_structure *structure);
t_structure			*pop_stack(t_structure *structure);
t_structure			*fill_structure(char **array, t_structure *structure);
void				ft_lstadd_front(t_structure *structure, t_stack *stack);
void				ft_lstadd_back(t_structure *structure, t_stack *stack);

//	OPERATION
void				swap_a(t_structure *structure);
void				swap_b(t_structure *structure);
void				swap_ab(t_structure *structure_a, t_structure *structure_b);
void				push_a(t_structure *src, t_structure *dest);
void				push_b(t_structure *src, t_structure *dest);

#endif