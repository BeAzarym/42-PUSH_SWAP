/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 20:41:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_double(long int nbr, t_body *structure)
{
	t_stack	*stack;

	stack = structure->head;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	while (stack)
	{
		if (stack->content == nbr)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

static int	is_valid_arg(int len, char **array)
{
	int	i;

	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (ft_isnumeric(array[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

char	**ft_get_arg(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 0;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		array = malloc(sizeof(char *) * argc);
		if (!array)
			return (NULL);
		while (++i < (argc + 1))
			array[i - 1] = ft_strdup(argv[i]);
	}
	if (!is_valid_arg(ft_tablen(array), array))
		ft_error(array, ARRAY);
	return (array);
}
