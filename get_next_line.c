/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:14:53 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/06 16:13:18 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_a_line(char *line)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	if (line[i] == '\n')
		i = i + 1;
	size = i;
	i = 0;
	tmp = malloc(sizeof(char) * size + 1);
	if (!tmp)
		return NULL;
	while (i < size)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char *read_lines(int fd, char *line)
{
	char		*buff;
	int			reading;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
	{
		return NULL;
	}
	reading = 1;
	while (reading != 0 && ft_strchr(line, '\n') == 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == -1)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		if (reading != 0)
		{
			buff[reading] = '\0';
			line = ft_strjoin(line, buff);
		}
	}
	free(buff);
	return line;
}

char	*erase_line(char *line)
{
	char	*tmp;
	
	if (!line)
		return NULL;
	if (ft_strchr(line, '\n') != NULL)
	{
		tmp = ft_strdup(ft_strchr(line, '\n') + 1);
	}
	else
	{
		free(line);
		return NULL;
	}
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;

	line = read_lines(fd, line);
	tmp = get_a_line(line);
	line = erase_line(line);
	if (!tmp || *tmp == '\0')
	{
		free(tmp);
		free(line);
		return NULL;
	}
	return (tmp);
}
