/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:37:17 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 16:10:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_print_tab(char **array)
{
	int	i;
	int	len;

	len = 0;
	while (array[len] != NULL)
		len++;
	i = -1;
	while (++i < len)
		ft_printf("[%d]->|%s|\n", i, array[i]);
}

void	print_stack(t_structure *structure_a, t_structure *structure_b)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = structure_a->head;
	stack_b = structure_b->head;
	ft_printf("|------------|\n|      A     |\n|------------|\n\n");
	while (stack_a != NULL)
	{
		ft_printf("| %d \n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("|------------|\n|      B     |\n|------------|\n\n");
	while (stack_b != NULL)
	{
		ft_printf("| %d \n", stack_b->content);
		stack_b = stack_b->next;
	}
}
