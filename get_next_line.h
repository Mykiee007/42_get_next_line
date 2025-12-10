/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:57 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/10 16:16:38 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
} t_list;
void	ft_bzero(void *src, size_t n);
void	*ft_calloc(size_t count, size_t n);
char	*get_next_line(int fd);

#endif

