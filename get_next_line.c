/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:04:31 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/29 17:48:00 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*read_line(int fd, char line)
{
	char	*buff;
	int		readed;

	readed = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (readed != 0 && ft_strchr(buff, '\n') == NULL)
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
	return (line);
}

char	*get_line(char *str, int size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * size + 2);
	while (i <= size + 1)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (ft_strchr(line, '\n') == NULL)
	{
		read_line(fd, line);
	}
	return (get_line(line, ft_strchr(line, '\n')));
}

int main ()
{
	int fd;
	fd = open("texte.txt", O_RDONLY);

	if (!fd)
		return 0;
	printf("(%s)" ,read_line(fd));
}
