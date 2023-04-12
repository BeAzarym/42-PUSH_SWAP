/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:48:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/12 16:14:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

int do_op(t_body *stack_a, t_body *stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		swap_ab(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_b(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_a(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		reverse_rotate_ab(stack_a, stack_b);
	else
		return(0);
	return (1);
}
