/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:37:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/09 15:01:18 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This main is for testing only, it is not included in the files to be submitted.

#include "get_next_line.h"

int main(int argc, char *argv)
{
	int fd;
	
	if(argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	close (fd);
	return (0);
}