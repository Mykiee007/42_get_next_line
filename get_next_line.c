/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/12 12:41:46 by mvelasqu         ###   ########.fr       */
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
	int		len;
	char	*line;

	if (!s || s[0] == '\0')
		return (NULL);
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

t_list	*create_find_node(t_list **lst, int file_d)
{
	t_list	*list;
	t_list	*new;

	if (!lst)
		return (NULL);
	list = *lst;
	while (list)
	{
		if (list->fd == file_d)
			return (list);
		list = list->next;
	}
	new = ft_lstnew(file_d);
	if (new == NULL)
		return (NULL);
	ft_lstadd_back(lst, new);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
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
}
	//bytes = read(fd, stash, BUFFER_SIZE)
	// 	if stash has fnd or '\0' 
	//		if stash has leftover
	//			ft_extract_rest
	//				update stash node->content = ft_strjoin(rest, node)
	//		else
	//			ft_extract_line from stash. 
	//	else, loop again.
	//or
	// loop (check for fnd or '\0' if yes)
	// 		bytes = read(fd, stash, BUFFER_SIZE) until fnd or '\0' is found.
	// loop end if fnd or '\0' is fond. 
	// 
	// line = ft_extract_line;
	// rest = ft_extract_rest;
	// free things here
	// node->content = ft_strjoin(rest,node->content)
char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;
	char			*rest;
	char			*tmp;
	char			buf[BUFFER_SIZE + 1];
	int				fnd = '\n';
	int				bytes;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = create_find_node(&head, fd);
	if (!node)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && (!node->content || !ft_strchr(node->content, fnd)))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buf[bytes] = '\0';
		if (bytes > 0)
		{
			tmp = node->content;
			node->content = ft_strjoin(tmp, buf);
			free(tmp);
			if (!node->content)
				return (NULL);
		}
	}
	if (!node->content || node->content[0] == '\0')
		return (NULL);
	line = ft_extract_line(node->content, fnd);
	rest = ft_extract_rest(node->content, fnd);
	free(node->content);
	node->content = rest;
	return (line);
}
