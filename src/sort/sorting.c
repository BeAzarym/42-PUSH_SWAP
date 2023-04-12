/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:56:50 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/12 11:21:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_highest_index(t_stack *stack)
{
	int		index;

	index = stack->expected_index;
	while (stack)
	{
		if (index < stack->expected_index)
			index = stack->expected_index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_body *stack)
{
	int	index;

	if (is_sorted(stack->head))
		return ;
	index = get_highest_index(stack->head);
	if (stack->head->expected_index == index)
		rotate_a(stack);
	else if (stack->head->next->expected_index == index)
		reverse_rotate_a(stack);
	if (stack->head->expected_index > stack->head->next->expected_index)
		swap_a(stack);
}

static void	push_all_but_three(t_body *stack_a, t_body *stack_b)
{
	int	i;
	int	count;
	int	size;

	size = stack_a->size;
	i = 0;
	count = 0;
	while (size > 6 && i < size && count < (size / 2))
	{
		if (stack_a->head->expected_index <= size / 2)
		{
			push_b(stack_a, stack_b);
			count++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (size - count > 3)
	{
		push_b(stack_a, stack_b);
		count++;
	}
}

static void	lift_stack(t_body *stack_a)
{
	int	lower_current;
	int	size;

	size = stack_a->size;
	lower_current = get_small_expected_index(stack_a);
	if (lower_current > size / 2)
	{
		while (lower_current < size)
		{
			reverse_rotate_a(stack_a);
			lower_current++;
		}
	}
	else
	{
		while (lower_current > 0)
		{
			rotate_a(stack_a);
			lower_current--;
		}
	}
}

void	sort(t_body *stack_a, t_body *stack_b)
{
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->head)
	{
		get_target_current(stack_a, stack_b);
		get_price(stack_a, stack_b);
		do_sales(stack_a, stack_b);
	}
	if (!is_sorted(stack_a->head))
		lift_stack(stack_a);
}
