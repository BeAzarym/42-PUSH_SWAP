/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:44:02 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/29 16:54:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
}		t_stack;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_convert(char type, va_list ap);
int		ft_print_char(char c);
int		ft_printf(const char *format, ...);
void	ft_print_tab(char **array);
int		ft_isnumeric(char *str);
int		is_double(int len, char **array);
int		ft_strcmp(const char *s1, const char *s2);
int		is_validArg(int len, char **array);
void	free_tab(char **array);
char	*ft_strdup(const char *s);
char	**ft_get_arg(int argc, char **argv);
size_t	ft_tablen(char **array);
void	ft_putstr_fd(char *s, int fd);
t_stack	*init_stack(int	nbr);
t_stack	*push_stack(int nbr, t_stack *stack);
t_stack	*pop_stack(t_stack *stack);
void	print_stack(t_stack *stack);
int		ft_atoi(const char *str);


#endif