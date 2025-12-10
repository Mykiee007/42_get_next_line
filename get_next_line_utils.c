/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:28 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/10 16:16:40 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(int file_d)
{
	t_list	*node;
	char	*src;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> fd = file_d;
	node -> content = read(file_d,src, BUFFER_SIZE);
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

int		ft_fdchecker(t_list *lst, int fd)
{
	int		i;
	
	while (lst->next != NULL)
	{
		if (lst->fd == fd)
			return (1);
		lst = lst->next;
	}
	return (0);
}

char	*ft_fdreader(t_list *lst, int fd)
{
	char *current;
	char *leftover;
	int i;

	while (lst->next != NULL)
	{
		if (lst->fd == fd)
		{
			current = lst->content;
			while (current[i] != '\0' || current[i] != '\n')
			{
				//to be continued
			}			
		}
		else
			lst = lst->next;
	}
	return (NULL);
}