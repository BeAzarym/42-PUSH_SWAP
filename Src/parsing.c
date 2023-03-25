/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/24 15:28:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	is_double(char **array, int len)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while (i < len)
	{
		while (j < len)
		{
			if (ft_strcmp(array[i],array[j]) != 0)
				j++;
			else
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	is_validArg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumeric(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);	
}

