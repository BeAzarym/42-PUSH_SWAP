/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:56:50 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 23:41:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static int	get_highest_index(t_stack *stack)
{
	int	index;

	index = stack->expected_index;
	while (stack->next)
	{
		if (index < stack->next->expected_index)
			index = stack->expected_index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_body *stack)
{
	int	index;

	index = get_highest_index(stack->head);
	if (stack->head->expected_index == index)
		rotate_a(stack);
	else if (stack->head->next->expected_index == index)
		reverse_rotate_a(stack);
	if (stack->head->expected_index > stack->head->next->expected_index)
		swap_a(stack);
}
static void	push_all_but_three(t_body *stack_a, t_body *stack_b, int size)
{
	t_stack *stack;
	int i;
	int	count;

	i = 0;
	count = 0;
	stack = stack_a->head;
	while (size > 6 && i < size && count < size / 2)
	{
		if (stack->expected_index <= size / 2)
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
	t_stack *tmp;


	push_all_but_three(stack_a, stack_b, size);
	tmp = stack_b->head;
	sort_three(stack_a); 
	while (tmp)
	{
		get_target_current(stack_a, stack_b);
		tmp = tmp->next;
	}
}
