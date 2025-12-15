/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/15 16:01:39 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
size_t	ft_strlen(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "";
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}*/

char	*ft_extract_rest(const char *s, int c)
{
	char	*rest;
	int		i;
	int		j;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		i++;
	j = 0;
	while (s[i + j] != '\0')
		j++;
	rest = (char *)malloc((j + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	rest[j] = '\0';
	while (j > 0)
	{
		j--;
		rest[j] = s[i + j];	
	}
	return (rest);
}

char	*ft_extract_line(const char *s, int c)
{
	char	*line;
	int			i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[i] = '\0';
	while (i > 0)
	{
		i--;
		line[i] = s[i];
	}
	return (line);
}

char	*ft_getstring(int fd, char *stash, int fnd)
{
	char	*temp;
	char	*buf;
	ssize_t	bytes;
	
	buf = malloc(BUFFER_SIZE +1);
	if (buf == NULL)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && (!stash || !ft_strchr(stash, fnd)))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{	
			free (stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		if (bytes > 0)
		{
			temp = stash;
			stash = ft_strjoin(temp, buf);
			free(temp);
			if (stash == NULL)
				return (NULL);
		}
	}
	free (buf);
	return (stash);
}

char	*get_next_line(size_t fd)
{
	static char	*stash[1000];
	char		*string;
	char		*line;
	char		*leftover;
	char		fnd;

	fnd = '\n';
	if(BUFFER_SIZE <= 0)
		return (NULL);
	string = ft_getstring(fd, stash[fd], fnd);
	if (string == NULL || string[0] == '\0')
	{
		free (string);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(string, fnd);
	leftover = ft_extract_rest(string, fnd);
	free(string);
	stash[fd] = leftover;
	return (line);
}


/*int main(void)
{
	//char str[] = "hello\n\n\n";
	size_t	fd;
	static char	*str1[10];
	int		fnd;
	char 	*text;

	fnd = '\n';
	fd = open("sample.txt", O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	text = ft_getstring(fd,str1[fd],fnd);
	if (text == NULL)
	{
		free(text);
		free(str1[fd]);
		return (0);
	}
	printf("%zu\n", fd);
	printf("%s", text);
	printf("\n\nHERE IS THE EXTRACT LINE:\n\n");
	printf("%s",ft_extract_line(text,'\n'));
	printf("\n\nHERE IS THE REST:\n\n");
	printf("%s",ft_extract_rest(text,'\n'));
	
	free(text);
	free(str1[fd]);
	close(fd);
	return (0);
}*/