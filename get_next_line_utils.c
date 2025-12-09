/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:28 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/09 11:37:23 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *src, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)src;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t n)
{
	size_t	total;
	void	*ptr;

	if (n != 0 && SIZE_MAX / n < count)
		return (NULL);
	total = count * n;
	ptr = (void *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
