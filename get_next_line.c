/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/11 16:19:02 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *my_extract_rest(const char *s, int c)
{
	int i;
	char *buf;
	int len;
	char *leftover;
	
	if (!s || s[0] == '\0')
		return (NULL);
	buf = ft_strchr(s, c);
	if (!buf || buf[1] == '\0')
        return (NULL);
	len = ft_strlen(buf);
	if (len == 0)
		return (NULL);
	leftover = (char *)malloc((len + 1)*sizeof(char));
	if (leftover == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		leftover[i] = buf[i+1];
		i++;
	}
	leftover[len] = '\0';
	return (leftover);
}

char *ft_extract_line(const char *s, int c)
{
	int i;
	int len;
	char *line;

	i = 0;
	while (s[i] != (char) c && s[i] != '\0')
		i++;
	len = i;
	if (s[i] == (char) c)
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (s[i] != (char) c && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == (char)c)
    {
        line[i] = s[i];
        i++;
    }
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	static t_list *head; // my pointer to my t_list

	return (0);
}	
