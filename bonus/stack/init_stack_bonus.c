/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:31 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 21:32:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static t_stack	*init_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->expected_index = 0;
	new->current_index = -1;
	new->target_current = -1;
	new->price_a = -1;
	new->price_b = -1;
	new->next = NULL;
	return (new);
}

static t_body	*create_stack(int nbr, t_body *structure)
{
	t_stack	*new;

	new = init_stack(nbr);
	if (!new)
		return (NULL);
	if (!structure->head)
	{
		structure->head = new;
		structure->tail = new;
	}
	else
	{
		new->next = structure->head;
		structure->head = new;
	}
	structure->size++;
	return (structure);
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

t_body	*init_body(void)
{
	t_body	*structure;

	structure = malloc(sizeof(t_body));
	structure->head = NULL;
	structure->tail = NULL;
	structure->size = 0;
	return (structure);
}
