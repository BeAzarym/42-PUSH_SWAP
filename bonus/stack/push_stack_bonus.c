/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 21:35:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static void	push_stack(t_body *src, t_body *dest)
{
	t_stack	*tmp;

	if (!src->head)
		return ;
	tmp = src->head->next;
	src->head->next = dest->head;
	dest->head = src->head;
	if (dest->size == 0)
		dest->tail = dest->head;
	if (src->size == 1)
		src->tail = NULL;
	src->head = tmp;
	src->size--;
	dest->size++;
}

void	push_a(t_body *src, t_body *dest)
{
	push_stack(src, dest);
}

void	push_b(t_body *src, t_body *dest)
{
	push_stack(src, dest);
}
