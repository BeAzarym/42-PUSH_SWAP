/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:37:17 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/25 20:55:51 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_print_tab(char **array)
{
	int	i;
	int	len;

	len = 0;
	while (array[len] != NULL)
		len++;
	i = -1;
	while (++i < len)
		ft_printf("[%d]->|%s|\n", i, array[i]);
}
