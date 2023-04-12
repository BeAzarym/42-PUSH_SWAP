/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:59:18 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 22:12:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		*(char *)s++ = 0;
}

char	*ft_strjoin(char *s1, char *s2, int *check_newline)
{
	char	*str;
	int		len_str;
	int		len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_str = len_s1 + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (*s1)
		*str++ = *s1++;
	free (s1 - len_s1);
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	if (len_str > 0 && *(str - 1) == '\n')
		*check_newline = 0;
	return (str - len_str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = -1;
	while (src[++i] != '\0' && dstsize > 1)
	{
		dst[i] = src[i];
		dstsize--;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}

char	*ft_gnldup(char *str, int *check_newline)
{
	char	*dup;
	int		i;
	int		len;

	i = -1;
	len = -1;
	while (str[++len])
	{
		if (str[len] == '\n')
		{
			len++;
			break ;
		}
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (++i < len)
		dup[i] = str[i];
	dup[i] = '\0';
	if (len > 0 && dup[i - 1] == '\n')
		*check_newline = i - 1;
	return (dup);
}
