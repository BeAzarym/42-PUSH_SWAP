/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:59:13 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/12 13:51:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static int	check_endline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < 1025)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*get_line(char *line, char *buffer, int *check_newline, int fd)
{
	int		line_size;
	int		read_check;
	char	read_buffer[1026];

	while (*check_newline == -1)
	{
		ft_bzero(read_buffer, (501));
		read_check = read(fd, read_buffer, 500);
		if (read_check == -1)
		{
			free(line);
			ft_bzero(buffer, (501));
			return (NULL);
		}
		line_size = check_endline(read_buffer);
		ft_strlcpy(buffer, &read_buffer[line_size], (501));
		ft_strlcpy(read_buffer, read_buffer, line_size + 1);
		line = ft_strjoin(line, read_buffer, check_newline);
		if (read_check == 0)
		{
			ft_bzero(buffer, 501);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[501];
	char		*line;
	int			check_newline;

	if ((fd < 0 || fd >= FOPEN_MAX))
		return (NULL);
	check_newline = -1;
	line = ft_gnldup(buffer, &check_newline);
	if (!line)
		return (NULL);
	ft_strlcpy(buffer, &buffer[check_newline + 1], 501);
	line = get_line(line, buffer, &check_newline, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
