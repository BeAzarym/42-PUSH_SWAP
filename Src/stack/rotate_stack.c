/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:31:38 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 15:59:38 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	rotate(t_body *structure)
{
	t_stack	*tmp;

	if (!structure->head || structure->size < 2)
		return ;
	tmp = structure->head->next;
	structure->head->next = NULL;
	structure->tail->next = structure->head;
	structure->tail = structure->head;
	structure->head = tmp;
}

void	rotate_a(t_body *structure)
{
	rotate(structure);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_body *structure)
{
	rotate(structure);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_body *structure_a, t_body *structure_b)
{
	rotate(structure_a);
	rotate(structure_b);
	ft_putstr_fd("rr\n", 1);
}