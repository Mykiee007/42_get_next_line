/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:37:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/15 15:50:44 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This main is for testing only, it is not included in the files to be submitted.
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/*int	main(int argc, char **argv)
{
	int		fd[4];
	char	*line;
	int		choice;
	int		i;

	if (argc != 5)
	{
		printf("Usage: %s file1 file2 file3 file4\n", argv[0]);
		return (1);
	}

	i = 0;
	while (i < 4)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] < 0)
		{
			printf("open");
			return (1);
		}
		i++;
	}

	printf("\nFiles opened:\n");
	printf("1 → %s\n", argv[1]);
	printf("2 → %s\n", argv[2]);
	printf("3 → %s\n", argv[3]);
	printf("4 → %s\n\n", argv[4]);

	while (1)
	{
		printf("CHOOSE fd (1-4) OR 0 TO EXIT: ");
		if (scanf("%d", &choice) != 1)
			break;
		if (choice == 0)
			break;
		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		line = get_next_line(fd[choice - 1]);
		if (!line)
		{
			printf("[EOF on fd %d]\n", choice);
			continue;
		}

		printf("fd %d: \n%s\n", choice, line);
		free(line);
	}

	i = 0;
	while (i < 4)
	{
		close(fd[i]);
		i++;
	}

	return (0);
}*/



//char *ft_extract_rest(const char *s, int c)
//{
//	int i;
//	int j;
//	int len;
//	char *leftover;
//
//	if (s == NULL || s[0] == '\0')
//		return (NULL);
//	i = 0;
//	while (s[i] != (char)c && s[i] != '\0')
//		i++;
//	if (s[i] == '\0')
//		return (NULL);
//	i++;
//	len = 0;
//	while (s[i] != '\0')
//		len++;
//	if (len == 0)
//		return (NULL);
//	leftover = (char *)malloc((len + 1)*sizeof(char));
//	if (leftover == NULL)
//		return (NULL);
//	j = 0;
//	while (j < len)
//	{
//		leftover[j] = s[i+j];
//		j++;
//	}
//	leftover[j] = '\0';
//	return (leftover);
//}


/*
int main(void)
{
	char *src;
	char *string = "hhhhhhhh";
	char *buff;
	char c = 'a';
	//char buf[10];
	//int	bytes;

	
	printf("ORIGINAL STRING:\n\n%s\n", string);
	src = ft_extract_line(string, c);
	printf("\nBEFORE CHR: \n\n%s\n", src);
	buff = ft_strchr(string, c);
    printf("\nft_strchr CHR: \n\n%s\n", buff);
	buff = ft_extract_rest(string, c);
    printf("\nft_extract_rest: \n\n%s\n", buff);
	buff = my_extract_rest(string, c);
    printf("\nmy_extract_rest: \n\n%s\n", buff);
	free(src);
//
//	buff = src;
//	src = ft_strchr(buff, c);
//    printf("After finding '%c', the string is: \n\n%s\n", c, src);

		//	if(argc < 2)
//		return (printf("ERROR: txt file missing\n"));
//	fd = open(argv[1], O_RDONLY);
//	if (fd < 0)
//		return (0);
//	src = get_next_line(fd);
//    while ((src = get_next_line(fd)) != NULL)
//    {
//        printf("%s", src);
//        free(src);
//    }
//	printf("%s", src);
	READ #1
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

//    close(fd);
	return (0);
}*/

int main(void)
{
    int     fd;
    char    *line;

    fd = open("sample.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}