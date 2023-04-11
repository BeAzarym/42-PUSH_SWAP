/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 20:35:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
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
		return (0);
	array = ft_get_arg(argc, argv);
	structure_a = init_body();
	structure_a = fill_structure(array, structure_a);
	structure_b = init_body();
	computing_theorical_postion(structure_a->head, (structure_a->size + 1));
	do_sort(structure_a, structure_b, structure_a->size);
	print_stack(structure_a, structure_b);
	free_stack(structure_a);
	free_stack(structure_b);
	return (0);
}
