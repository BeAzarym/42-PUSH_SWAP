/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 19:37:02 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	ft_lstadd_front(t_body *structure, t_stack *stack)
{
	if (!structure || !stack)
		return ;
	if (!structure->head)
	{
		structure->head = stack;
		structure->tail = stack;
		stack->next = NULL;
	}
	else
	{
		stack->next = structure->head;
		structure->head = stack;
	}
}

static void	push_stack(t_body *src, t_body *dest)
{
	t_stack	*tmp;

	tmp = src->head;
	if (!src || !dest)
		return ;
	src->head = src->head->next;
	ft_lstadd_front(dest, tmp);
	src->size--;
	dest->size++;
}

void	push_a(t_body *src, t_body *dest)
{
	if (!src->head)
		return;
	push_stack(src, dest);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_body *src, t_body *dest)
{
	if (!src->head)
		return ;
	push_stack(src, dest);
	ft_putstr_fd("pb\n", 1);
}
