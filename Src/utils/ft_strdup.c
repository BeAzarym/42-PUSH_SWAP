/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:58 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/25 20:50:11 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (NULL);
	while (*s != '\0')
		*dup++ = *s++;
	*dup = '\0';
	return (dup - slen);
}
