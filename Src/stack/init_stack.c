/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/29 22:15:51 by cchabeau         ###   ########.fr       */
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

t_stack		*push_stack(int nbr, t_stack *stack)
{
	t_stack	*new;

	new = init_stack(nbr);
	if (!new)
		return (NULL);
	new->next = stack;
	return (new);	
}

t_stack		*pop_stack(t_stack *stack)
{
	t_stack *tmp;
	tmp = stack;
	stack = stack->next;
	free(tmp);
	return (stack);
}

void	print_stack(t_stack *stack)
{
	ft_printf("|------------|\n|      A     |\n|------------|\n\n");
	while (stack != NULL)
	{
		ft_printf("| %d \n",stack->content);
		stack = stack->next;
	}
}
