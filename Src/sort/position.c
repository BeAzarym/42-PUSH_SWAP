/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:29:19 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 23:48:55 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	get_index(t_body *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		tmp->current_index = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_small_expected_index(t_body *stack)
{
	int	lower_current_index;
	int	lower_expected_index;
	t_stack *tmp;

	lower_expected_index = INT_MAX;
	get_index(stack);
	tmp = stack->head;
	lower_current_index = tmp->current_index;
	while (tmp)
	{
		if (tmp->expected_index < lower_expected_index)
		{
			lower_current_index = tmp->current_index;
			lower_expected_index = tmp->expected_index;
		}
		tmp = tmp->next;
	}
	return (lower_current_index);
}

static int	catch_current_index(t_body *stack_a, int index_b, int expected,
		int current)
{
	t_stack	*tmp;

	tmp = stack_a->head;
	while (tmp)
	{
		if (tmp->expected_index > index_b && tmp->expected_index < expected)
		{
			expected = tmp->expected_index;
			current = tmp->current_index;
		}
		tmp = tmp->next;
	}
	if (expected != INT_MAX)
		return (current);
	tmp = stack_a->head;
	while (tmp)
	{
		if (tmp->expected_index < expected)
		{
			expected = tmp->expected_index;
			current = tmp->current_index;
		}
		tmp = tmp->next;
	}
	return (current);
}
void	get_target_current(t_body *stack_a, t_body *stack_b)
{
	t_stack	*tmp;
	int		current;

	tmp = stack_b->head;
	get_index(stack_a);
	get_index(stack_b);
	current = 0;
	while (tmp)
	{
		current = catch_current_index(stack_a, tmp->expected_index, INT_MAX,
				current);
		tmp->target_current = current;
		tmp = tmp->next;
	}
}
