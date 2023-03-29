/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:44 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/29 20:26:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	is_double(int len, char **array)
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

int	is_validArg(int len, char **array)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_isnumeric(array[i]))
			i++;
		else
			return (0);
	}
	return (1);	
}

char	**ft_get_arg(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 0;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
	{
		array = malloc(sizeof(char *) * argc);
		if (!array)
			return (NULL);
		while (++i < argc)
			array[i - 1] = ft_strdup(argv[i]);
	}
	if (!is_validArg(ft_tablen(array), array) || is_double(ft_tablen(array), array))
		ft_error(array, ARRAY);
	return (array);
}
