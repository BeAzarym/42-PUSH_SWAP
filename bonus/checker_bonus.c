/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:53:00 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/13 20:25:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static void	clean_all(t_body *stack_a, t_body *stack_b, char *line)
{
	if (stack_a && !stack_b)
		free_stack(stack_a);
	else if (stack_b && !stack_a)
		free_stack(stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
	if (line)
		free(line);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

static int	checker(t_body *stack_a, t_body *stack_b)
{
	char	*line;
	int		result;

	result = 1;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		result = do_op(stack_a, stack_b, line);
		if (result == 0)
			clean_all(stack_a, stack_b, line);
		free(line);
	}
	if (is_sorted(stack_a->head))
	{
		result = 0;
		ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
	return (result);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_body	*structure_a;
	t_body	*structure_b;
	int		result;

	structure_b = NULL;
	if (argc < 2)
		return (0);
	array = ft_get_arg(argc, argv);
	if (!array)
		ft_error(array, ARRAY);
	structure_a = init_body();
	if (!structure_a)
	{
		free(array);
		ft_error(structure_a, T_STACK);
	}
	structure_a = fill_structure(array, structure_a);
	structure_b = init_body();
	if (!structure_b)
		clean_all(structure_a, structure_b, NULL);
	result = checker(structure_a, structure_b);
	free_stack(structure_a);
	free_stack(structure_b);
	return (result);
}
