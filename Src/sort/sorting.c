/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:56:50 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 19:40:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	sort_three(t_body *stack)
{
	if (stack->head->expected_index == 2)
		rotate_a(stack);
	else if (stack->head->next->expected_index == 2)
		reverse_rotate_a(stack);
	if (stack->head->expected_index > stack->head->next->expected_index)
		swap_a(stack);
}
static void	push_all_but_three(t_body *stack_a, t_body *stack_b, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (size > 6 && i < size && count < (size / 2))
	{
		if (stack_a->head->expected_index <= (size / 2))
		{
			push_b(stack_a, stack_b);
			count++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while ((size - count) > 3)
	{
		push_b(stack_a, stack_b);
		count++;
	}
}

void	sort(t_body *stack_a, t_body *stack_b, int size)
{
	push_all_but_three(stack_a, stack_b, size);
	sort_three(stack_a);
}
