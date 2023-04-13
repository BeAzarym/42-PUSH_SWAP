/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/13 21:25:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clean_all(t_body *stack_a, t_body *stack_b)
{
	if (stack_a && !stack_b)
		free_stack(stack_a);
	else if (stack_b && !stack_a)
		free_stack(stack_b);
	else if (stack_a && stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

static void	do_sort(t_body *structure_a, t_body *structure_b, int size)
{
	if (size == 2 && !is_sorted(structure_a->head))
		swap_a(structure_a);
	else if (size == 3)
		sort_three(structure_a);
	else if (size > 3 && !is_sorted(structure_a->head))
		sort(structure_a, structure_b);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_body	*structure_a;
	t_body	*structure_b;

	structure_b = NULL;
	if (argc < 2)
		return (1);
	array = ft_get_arg(argc, argv);
	if (!array)
		ft_error(array, ARRAY);
	structure_a = init_body();
	if (!structure_a)
	{
		free_tab(array);
		ft_error(structure_a, T_STACK);
	}
	structure_a = fill_structure(array, structure_a);
	structure_b = init_body();
	if (!structure_b)
		clean_all(structure_a, structure_b);
	computing_theorical_postion(structure_a->head, (structure_a->size + 1));
	do_sort(structure_a, structure_b, structure_a->size);
	free_stack(structure_a);
	free_stack(structure_b);
	return (0);
}
