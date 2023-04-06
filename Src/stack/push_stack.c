/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 16:17:24 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void	push_stack(t_structure *src, t_structure *dest)
{
	t_stack	*tmp;

	tmp = src->head;
	if (!src || !dest)
		return ;
	src->head = src->head->next;
	ft_lstadd_front(dest, tmp);
}

void	push_a(t_structure *src, t_structure *dest)
{
	push_stack(src, dest);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_structure *src, t_structure *dest)
{
	push_stack(src, dest);
	ft_putstr_fd("pb\n", 1);
}
