/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:55:47 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/09 14:45:00 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get_next_line returns whats inside the fd, but prints it one at a time. 

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int src;
	int cnt;
	char *buff;
	
	buff = (char *)ft_calloc(100, sizeof(char));
	cnt = 10;
	src = read(fd, buff, cnt);
	printf("%s",src);
	return (src);
}	
