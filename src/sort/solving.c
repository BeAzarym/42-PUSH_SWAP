/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:05:20 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 20:42:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	do_rrr(t_body *stack_a, t_body *stack_b, int *price_a, int *price_b)
{
	while (*price_a < 0 && *price_b < 0)
	{
		(*price_a)++;
		(*price_b)++;
		reverse_rotate_ab(stack_a, stack_b);
	}
}

static void	do_rr(t_body *stack_a, t_body *stack_b, int *price_a, int *price_b)
{
	while (*price_a > 0 && *price_b > 0)
	{
		(*price_a)--;
		(*price_b)--;
		rotate_ab(stack_a, stack_b);
	}
}

static void	do_ra(t_body *stack_a, int *price_a)
{
	while (*price_a)
	{
		if (*price_a > 0)
		{
			rotate_a(stack_a);
			(*price_a)--;
		}
		else if (*price_a < 0)
		{
			reverse_rotate_a(stack_a);
			(*price_a)++;
		}
	}
}

static void	do_rb(t_body *stack_b, int *price_b)
{
	while (*price_b)
	{
		if (*price_b > 0)
		{
			rotate_b(stack_b);
			(*price_b)--;
		}
		else if (*price_b < 0)
		{
			reverse_rotate_b(stack_b);
			(*price_b)++;
		}
	}
}

void	solve(t_body *stack_a, t_body *stack_b, int price_a, int price_b)
{
	if (price_a < 0 && price_b < 0)
		do_rrr(stack_a, stack_b, &price_a, &price_b);
	else if (price_a > 0 && price_b > 0)
		do_rr(stack_a, stack_b, &price_a, &price_b);
	do_ra(stack_a, &price_a);
	do_rb(stack_b, &price_b);
	push_a(stack_b, stack_a);
}
