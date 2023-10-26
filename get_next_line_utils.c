/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:14:51 by issierra          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:27 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr_copy_reverse(char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		if (c != '\0')
			res = malloc(sizeof(char) * (i + 2));
		else
			res = malloc(sizeof(char) * (i + 1));
		if (!res)
			return (NULL);
		if (c != '\0')
			res[i + 1] = '\0';
		while (i >= 0)
		{
			res[i] = s[i];
			i--;
		}
		return (res);
	}
	return (0);
}

char	*ft_strchr_copy(char *s, int c)
{
	char	*res;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		res = malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
		if (!res)
			return (NULL);
		i++;
		while (i < ft_strlen(s))
		{
			res[j] = s[i];
			j++;
			i++;
		}
		res[j] = '\0';
		return (res);
	}
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}
