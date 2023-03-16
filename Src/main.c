/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/16 10:44:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		array = malloc(sizeof(char *) * argc);
		if (!array)
			return (2);
		while (++i < argc)
		{
			if (ft_isnumeric(argv[i]))
				array[i - 1] = argv[i];
			else
				return (3);
		}
	}
	if (is_double(array, ft_tablen(array)))
		return (4);
	else
		ft_print_tab(array);
}
