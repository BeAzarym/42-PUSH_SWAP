/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:31:33 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 21:34:56 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static void	reverse_rotate(t_body *structure)
{
	t_stack	*tmp;

	if (!structure->head || structure->size < 3)
		return ;
	tmp = structure->head;
	while (tmp && tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	structure->tail->next = structure->head;
	structure->head = structure->tail;
	structure->tail = tmp;
}

void	reverse_rotate_a(t_body *structure)
{
	reverse_rotate(structure);
}

void	reverse_rotate_b(t_body *structure)
{
	reverse_rotate(structure);
}

void	reverse_rotate_ab(t_body *structure_a, t_body *structure_b)
{
	reverse_rotate(structure_a);
	reverse_rotate(structure_b);
}
