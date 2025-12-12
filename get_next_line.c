/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/12 15:20:52 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_rest(const char *s, int c)
{
	int		i;
	char	*buf;
	int		len;
	char	*leftover;

	if (!s || s[0] == '\0')
		return (NULL);
	buf = ft_strchr(s, c);
	if (!buf || buf[1] == '\0')
		return (NULL);
	len = ft_strlen(buf + 1);
	if (len == 0)
		return (NULL);
	leftover = (char *)malloc((len + 1) * sizeof(char));
	if (leftover == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		leftover[i] = buf[i + 1];
		i++;
	}
	leftover[len] = '\0';
	return (leftover);
}

char	*ft_extract_line(const char *s, int c)
{
	int		i;
	char	*line;

	if (!s || s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != (char) c && s[i] != '\0')
		i++;
	if (s[i] == (char) c)
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (s[i] != (char) c && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == (char)c)
		line[i++] = c;
	line[i] = '\0';
	return (line);
}

char	*ft_getstring(int fd, char *string, int fnd)
{
	int		byte;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	byte = 1;
	while (byte > 0 && (!string || !ft_strchr(string, fnd)))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free (string);
			return (NULL);
		}
		buf[byte] = '\0';
		if (byte > 0)
		{
			temp = string;
			string = ft_strjoin(temp, buf);
			free (temp);
			if (!string)
				return (NULL);
		}
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char		*string[1000];
	char			*line;
	char			*leftover;
	char			*temp;
	int				fnd;

	fnd = '\n';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_getstring(fd, string[fd], fnd);
	if (temp == NULL || temp[0] == '\0')
	{
		free(temp);
		string[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(temp, fnd);
	leftover = ft_extract_rest(temp, fnd);
	free (temp);
	string[fd] = leftover;
	return (line);
}
