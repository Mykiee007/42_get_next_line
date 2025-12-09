/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:37:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/09 15:57:06 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This main is for testing only, it is not included in the files to be submitted.

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *src;
	
	if(argc < 2)
		return (printf("ERROR: txt file missing\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
    while ((src = get_next_line(fd)) != NULL)
    {
        printf("%s", src);
        free(src);
    }
    close(fd);
	return (0);
}