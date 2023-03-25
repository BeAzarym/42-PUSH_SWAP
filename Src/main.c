/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/25 20:49:35 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**array;

	array = NULL;
	i = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		array = malloc(sizeof(char *) * argc);
		if (!array)
			return (3);
		while (i < argc - 1)
		{
			array[i] = ft_strdup(argv[i + 1]);
			i++;
		}
	}
	if (!is_validArg(argc - 1, array))
		return (2);
	if (is_double(array, argc - 1))
		return (4);
	else
		ft_print_tab(array);
	free_tab(array);
}
