/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:57 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/12 15:12:53 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char const *src);
char	*ft_strchr(const char *s, int c);
char	*ft_extract_rest(const char *s, int c);
char	*ft_extract_line(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getstring(int fd, char *string, int fnd);
char	*get_next_line(int fd);

#endif
