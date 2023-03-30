/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:36:57 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/30 18:42:35 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
		if ((result * sign) < INT_MIN || result > INT_MAX)
			break;
	}
	return (result * sign);
}
