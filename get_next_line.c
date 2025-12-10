/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/10 16:16:41 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *head; // my pointer to my t_list
	char *buff;

	if (head == NULL)
	{	
		head = ft_lstnew(fd);
	} 
	else if (ft_fdchecker(head,fd)) // 1 if there is already, 0 if fd is not there
	{

	}


	return (buff);
}	
