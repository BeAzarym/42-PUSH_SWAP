/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/29 20:48:37 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**array;
	int 	i;
	t_stack *stack;
	
	stack = NULL;
	if (argc < 2)
		return (1);
	array = ft_get_arg(argc, argv);
	i = ft_tablen(array) - 1;
	while (i >= 0)
	{
		stack = push_stack(ft_atoi(array[i]), stack);
		i--;
	}
	free_tab(array);
	print_stack(stack);
	free_stack(stack);
	return (0);
}
