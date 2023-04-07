/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/07 21:56:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**array;
	t_body	*structure_a;
	t_body	*structure_b;

	array = NULL;
	structure_a = NULL;
	structure_b = NULL;
	if (argc < 2)
		return (0);
	array = ft_get_arg(argc, argv);
	structure_a = init_body();
	structure_b = init_body();
	structure_a = fill_structure(array, structure_a);
	print_stack(structure_a, structure_b);
	reverse_rotate_a(structure_a);
	print_stack(structure_a, structure_b);
	free_stack(structure_a);
	free_stack(structure_b);
	return (0);
}
