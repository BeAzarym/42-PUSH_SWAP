/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/30 15:21:17 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**array;
	t_stack *stack;
	
	stack = NULL;
	if (argc < 2)
		return (0);
	array = ft_get_arg(argc, argv);
	stack = fill_stack(array, stack);
	print_stack(stack);
	free_stack(stack);
	return (0);
}
