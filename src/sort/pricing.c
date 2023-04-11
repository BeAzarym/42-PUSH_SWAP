/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pricing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:30:19 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 20:43:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_price(t_body *stack_a, t_body *stack_b)
{
	t_stack	*tmp_b;

	tmp_b = stack_b->head;
	while (tmp_b)
	{
		tmp_b->price_b = tmp_b->current_index;
		if (tmp_b->current_index > (stack_b->size / 2))
			tmp_b->price_b = (stack_b->size - tmp_b->current_index) * -1;
		tmp_b->price_a = tmp_b->target_current;
		if (tmp_b->target_current > (stack_a->size / 2))
			tmp_b->price_a = (stack_a->size - tmp_b->target_current) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_sales(t_body *stack_a, t_body *stack_b)
{
	t_stack	*tmp;
	int		price;
	int		price_a;
	int		price_b;

	tmp = stack_b->head;
	price = INT_MAX;
	while (tmp)
	{
		if (ABS(tmp->price_a) + ABS(tmp->price_b) < ABS(price))
		{
			price = ABS(tmp->price_b) + ABS(tmp->price_a);
			price_a = tmp->price_a;
			price_b = tmp->price_b;
		}
		tmp = tmp->next;
	}
	solve(stack_a, stack_b, price_a, price_b);
}
