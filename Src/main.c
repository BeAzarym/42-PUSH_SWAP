/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/05 16:55:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	char		**array;
	t_structure	*structure_a;

	// t_stack *stack_b;
	array = NULL;
	structure_a = NULL;
	// stack_b = NULL;
	if (argc < 2)
		return (0);
	array = ft_get_arg(argc, argv);
	structure_a = init_structure(array);
	print_stack(structure_a);
	swap_a(structure_a);
	print_stack(structure_a);
	free_stack(structure_a);
	return (0);
}
