/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:56:50 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 17:06:30 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	sort_three(t_body *stack)
{
	if (stack->head->sorted_index == 2)
		rotate_a(stack);
	else if (stack->head->next->sorted_index == 2)
		reverse_rotate_a(stack);
	if (stack->head->sorted_index > stack->head->next->sorted_index)
		swap_a(stack);
}
