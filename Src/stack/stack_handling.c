/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:20:23 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/30 00:22:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

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