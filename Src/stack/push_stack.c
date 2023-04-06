/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 18:05:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	push_stack(t_body *src, t_body *dest)
{
	t_stack	*tmp;

	tmp = src->head;
	if (!src || !dest)
		return ;
	src->head = src->head->next;
	ft_lstadd_front(dest, tmp);
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
