/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/06 18:08:43 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

t_stack	*init_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->next = NULL;
	new->index = 0;
	return (new);
}

t_body	*fill_structure(char **array, t_body *structure)
{
	int	i;
	
	i = ft_tablen(array) - 1;
	while (i >= 0)
	{
		if (is_double(ft_atoi(array[i]), structure))
		{
			free_tab(array);
			ft_error(structure, T_STACK);
		}
		else
			structure = create_stack(ft_atoi(array[i]), structure);
		i--;
	}
	free_tab(array);
	return (structure);
}

t_body *init_body()
{
	t_body *structure;
	structure = malloc(sizeof(t_body));
	structure->head = NULL;
	structure->tail = NULL;
	return (structure);
}
