/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:37:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/10 16:16:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This main is for testing only, it is not included in the files to be submitted.

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *src;
	//char buf[10];
	//int	bytes;
	
	if(argc < 2)
		return (printf("ERROR: txt file missing\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	src = get_next_line(fd);
    while ((src = get_next_line(fd)) != NULL)
    {
        printf("%s", src);
        free(src);
    }
	printf("%s", src);

/*	READ #1
    bytes = read(fd, buf, 9);
    buf[bytes] = '\0';
    printf("READ 1: %s\n", buf);

    // READ #2
    bytes = read(fd, buf, 5);
    buf[bytes] = '\0';
    printf("READ 2: %s\n", buf);

    // READ #3
    bytes = read(fd, buf, 9);
    buf[bytes] = '\0';
    printf("READ 3: %s\n", buf);

    // READ #4
    bytes = read(fd, buf, 5);
    buf[bytes] = '\0';
    printf("READ 4: %s\n", buf);
*/
    close(fd);
	return (0);
}