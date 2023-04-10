/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:16:40 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/10 23:20:43 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static t_body	*pop_stack(t_body *structure)
{
	t_stack	*tmp;

	tmp = structure->head;
	structure->head = structure->head->next;
	free(tmp);
	structure->size--;
	return (structure);
}

void	free_tab(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_stack(t_body *structure)
{
	while (structure->size != 0)
		structure = pop_stack(structure);
	free(structure);
}

void	ft_error(void *ptr, int type)
{
	if (type == ARRAY)
		free_tab(ptr);
	else if (type == T_STACK)
		free_stack(ptr);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
