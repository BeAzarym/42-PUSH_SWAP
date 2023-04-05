/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:37 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/05 15:09:47 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static void push_stack(t_structure *src, t_structure *dest)
{		
	if (!src || !dest)
		return;
	ft_lstadd_front(dest, src->head);
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
