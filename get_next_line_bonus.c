/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:47:43 by issierra          #+#    #+#             */
/*   Updated: 2023/10/26 16:09:23 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h> //open
//#include <stdio.h> //printf

#include "get_next_line_bonus.h"

char	*ft_free(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

char	*next_line_data(char *ld)
{
	char	*new_line_data;
	char	*aux;
	int		len;

	aux = ft_strchr(ld, '\n');
	if (!aux)
	{
		new_line_data = NULL;
		return (ft_free(&ld));
	}
	else
		len = (aux - ld) + 1;
	if (!ld[len])
		return (ft_free(&ld));
	new_line_data = ft_strchr_copy(ld, '\n');
	ft_free(&ld);
	if (new_line_data == NULL)
		return (NULL);
	return (new_line_data);
}

char	*get_line_from_buffer(char *line_data)
{
	char	*line_data_clean;

	if (!ft_strchr(line_data, '\n'))
	{
		line_data_clean = ft_strchr_copy_reverse(line_data, '\0');
		if (!line_data_clean)
			return (NULL);
		return (line_data_clean);
	}
	line_data_clean = ft_strchr_copy_reverse(line_data, '\n');
	if (!line_data_clean)
		return (NULL);
	return (line_data_clean);
}

char	*read_data_from_file(char *line_data, int fd)
{
	int		num_bytes_read;
	char	*buffer;

	num_bytes_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&line_data));
	buffer[0] = '\0';
	while (num_bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes_read > 0)
		{
			buffer[num_bytes_read] = '\0';
			line_data = ft_strjoin(line_data, buffer);
		}
	}
	free(buffer);
	if (num_bytes_read == -1)
		return (ft_free(&line_data));
	return (line_data);
}

char	*get_next_line(int fd)
{
	static char	*line_data[MAX_FD];
	char		*line_data_clean;

	if (fd < 0)
		return (NULL);
	if (!line_data[fd] || (line_data[fd] && !ft_strchr(line_data[fd], '\n')))
		line_data[fd] = read_data_from_file(line_data[fd], fd);
	if (!line_data[fd])
		return (NULL);
	line_data_clean = get_line_from_buffer(line_data[fd]);
	if (!line_data_clean)
		return (ft_free(&line_data[fd]));
	line_data[fd] = next_line_data(line_data[fd]);
	return (line_data_clean);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("variable_nls.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }