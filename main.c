/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:37:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/11 16:02:49 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This main is for testing only, it is not included in the files to be submitted.
#include <stdio.h>
#include <stdlib.h>
//#include "get_next_line.h"

size_t	ft_strlen(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char *ft_extract_line(const char *s, int c)
{
	int i;
	int len;
	char *line;

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

char *my_extract_rest(const char *s, int c)
{
	int i;
	char *buf;
	int len;
	char *leftover;
	
	if (!s || s[0] == '\0')
		return (NULL);
	buf = ft_strchr(s, c);
	if (!buf || buf[1] == '\0')
        return (NULL);
	len = ft_strlen(buf);
	if (len == 0)
		return (NULL);
	leftover = (char *)malloc((len + 1)*sizeof(char));
	if (leftover == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		leftover[i] = buf[i+1];
		i++;
	}
	leftover[len] = '\0';
	return (leftover);
}

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
//    close(fd);
	return (0);
}