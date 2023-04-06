/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 16:18:55 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	char		**array;
	t_structure	*structure_a;
	t_structure *structure_b;

	array = NULL;
	structure_a = NULL;
	structure_b = NULL;
	if (argc < 2)
		return (0);
	array = ft_get_arg(argc, argv);
	structure_a = init_structure();
	structure_b = init_structure();
	structure_a = fill_structure(array, structure_a);
	print_stack(structure_a, structure_b);
	swap_a(structure_a);
	push_b(structure_a, structure_b);
	push_b(structure_a, structure_b);
	push_b(structure_a, structure_b);
	push_a(structure_b, structure_a);
	print_stack(structure_a, structure_b);
	free_stack(structure_a);
	free(structure_b);
	return (0);
}
