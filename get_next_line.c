/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:04:31 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/01 16:27:35 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*read_line(int fd, char *line)
{
	char	*buff;
	int		readed;

	readed = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (line == NULL)
	{
		line = malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	while (readed != 0 && ft_strchr(line, '\n') == NULL)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		line = ft_strjoin(line, buff);
	}
	//if (readed == 0)
		//return NULL;
	return (line);
}

char	*get_line(char *str)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	size = i;
	i = 0;
	tmp = malloc(sizeof(char) * size + 2);
	while (i <= size && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*erase_line(char *line)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(ft_strchr(line, '\n')));
	if (ft_strchr(line, '\n') != NULL)
	{
		tmp = ft_strdup(ft_strchr(line, '\n') + 1);
	}
	else
		tmp = ft_strdup(ft_strchr(line, '\0') + 1);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (ft_strchr(line, '\n') != NULL)
	{
		line = erase_line(line);
	}
	if (ft_strchr(line, '\n') == NULL)
	{
		line = read_line(fd, line);
	}
	return (get_line(line));
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
