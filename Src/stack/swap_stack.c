/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:13:12 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 15:59:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	swap(t_body *structure)
{
	int tmp;
	
	if (!structure->head || !structure->head->next)
		return ;
	tmp = structure->head->content;
	structure->head->content = structure->head->next->content;
	structure->head->next->content = tmp;
	tmp = structure->head->expected_index;
	structure->head->expected_index = structure->head->next->expected_index;
	structure->head->next->expected_index = tmp;
}

void	swap_a(t_body *structure)
{
	swap(structure);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_body *structure)
{
	swap(structure);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_body *structure_a, t_body *structure_b)
{
	swap(structure_a);
	swap(structure_b);
	ft_putstr_fd("ss\n", 1);
}
