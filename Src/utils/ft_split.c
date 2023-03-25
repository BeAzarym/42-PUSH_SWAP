/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:54:20 by cchabeau          #+#    #+#             */
/*   Updated: 2023/03/16 13:13:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*ft_free_all_tab(char **strs, int size)
{
	while (--size >= 0)
		free(strs[size]);
	free(strs);
	return (NULL);
}

static char	*ft_extract_word(const char *s, char c)
{
	char		*word;
	const char	*save;
	size_t		i;

	save = s;
	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	word = ft_substr(save, 0, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	**save;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char const *) * (ft_count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	save = strs;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (!*s)
			break ;
		*strs = ft_extract_word(s, c);
		if (!*strs)
			return (ft_free_all_tab(save, (strs - save) + 1));
		strs++;
		while (*s && (*s != c))
			s++;
	}
	*strs = NULL;
	return (save);
}
