/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/30 15:05:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

t_stack		*init_stack(int	nbr)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->next = NULL;
	new->index = 0;
	return (new);
}

t_stack	*fill_stack(char **array, t_stack *stack)
{
	int		i;

	i = ft_tablen(array) - 1;
	while (i >= 0)
	{
		if (is_double(ft_atoi(array[i]), stack)  )
		{
			free_tab(array);
			ft_error(stack, T_STACK);
		}
		else
			stack = push_stack(ft_atoi(array[i]), stack);
		i--;
	}
	free_tab(array);
	return (stack);
}
