/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:14:53 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/02 15:14:22 by cdupuis          ###   ########.fr       */
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
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
	}
	size = i;
	i = 0;
	tmp = malloc(sizeof(char) * size + 2);
	while (i <= size)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*erase_line(char *line)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(ft_strchr(line, '\n')));
	if (!tmp)
		return (NULL);
	if (ft_strchr(line, '\n') != NULL)
	{
		tmp = ft_strdup(ft_strchr(line, '\n') + 1);
	}
	else
	{
		free(tmp);
		return NULL;
	}
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*tmp;
	int			reading;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return NULL;
	reading = 1;
	while (reading != 0 && ft_strchr(line, '\n') == 0)
	{
		reading = read(fd, buff, BUFFER_SIZE);
		if (reading == -1)
		{
			free(buff);
			return (NULL);
		}
		if (reading != 0)
		{
			buff[reading] = '\0';
			line = ft_strjoin(line, buff);
		}
	}
	tmp = get_a_line(line);
	line = erase_line(line);
	if (!tmp)
	{
		free(tmp);
		free(line);
		free(buff);
		return NULL;
	}
	return (tmp);
}

int main ()
{
	int fd;
	fd = open("texte.txt", O_RDONLY);

	if (!fd)
		return 0;
	printf("I(%s)" ,get_next_line(fd));
	printf("II(%s)" ,get_next_line(fd));
	printf("III(%s)" ,get_next_line(fd));
	printf("IV(%s)" ,get_next_line(fd));
	printf("V(%s)" ,get_next_line(fd));
	printf("VI(%s)" ,get_next_line(fd));
	printf("VII(%s)" ,get_next_line(fd));
}
