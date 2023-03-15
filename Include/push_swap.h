/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:44:02 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/15 16:06:29 by cchabeau         ###   ########.fr       */
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
	int				content;
	struct s_stack *next;
}		t_stack;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_convert(char type, va_list ap);
int		ft_print_char(char c);
int		ft_printf(const char *format, ...);
void	ft_print_tab(char **array, int len);
int		ft_isnumeric(char *str);

#endif