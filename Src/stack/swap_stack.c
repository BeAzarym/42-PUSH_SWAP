/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:12 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 16:33:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	swap(t_body *structure)
{
	t_stack	*first;
	t_stack *second;
	t_stack *third;

	if (!structure)
		return ;
	first = structure->head;
	second = structure->head->next;
	third = structure->head->next->next;

	structure->head = second;
	structure->head->next = first;
	structure->head->next->next = third;
}

void	swap_a(t_body *structure)
{
	if (!structure->head || !structure->head->next)
		return ;
	swap(structure);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_body *structure)
{
	if (!structure->head || !structure->head->next)
		return ;
	swap(structure);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_body *structure_a, t_body *structure_b)
{
	if (!structure_a->head || !structure_a->head->next)
		return ;
	if (!structure_b->head || !structure_b->head->next)
		return ;
	swap(structure_a);
	swap(structure_b);
	ft_putstr_fd("ss\n", 1);
}
