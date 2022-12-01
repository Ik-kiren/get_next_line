/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:52:47 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/01 14:27:20 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 100
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *source);