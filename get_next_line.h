/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:57 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/12/11 16:20:48 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
} t_list;
char	*my_extract_rest(const char *s, int c);
char	*ft_extract_line(const char *s, int c);
t_list	*ft_lstnew(int file_d);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_fdchecker(t_list *lst, int fd);
size_t	ft_strlen(char const *src);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);


#endif

