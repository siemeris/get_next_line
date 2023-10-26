/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:44:44 by issierra          #+#    #+#             */
/*   Updated: 2023/10/26 16:12:20 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr_copy_reverse(char *s, int c);
char	*ft_strchr_copy(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);

char	*ft_free(char **tmp);
char	*next_line_data(char *ld);
char	*get_line_from_buffer(char *line_data);
char	*read_data_from_file(char *line_data, int fd);
char	*get_next_line(int fd);

#endif
