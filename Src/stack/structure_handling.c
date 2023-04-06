/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:30 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 16:14:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_lstadd_front(t_structure *structure, t_stack *stack)
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

void	ft_lstadd_back(t_structure *structure, t_stack *stack)
{
	if (!stack || !structure)
		return ;
	if (!structure->tail)
	{
		structure->tail = stack;
		structure->head = stack;
		return ;
	}
	else
	{
		structure->tail->next = stack;
		structure->tail = stack;
	}
}