/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:20:19 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 21:22:07 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

int	ft_isnumeric(char *str)
{
	if (*str == 45)
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
			return (0);
	}
	return (1);
}
