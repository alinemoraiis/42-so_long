/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:26:39 by ados-rei          #+#    #+#             */
/*   Updated: 2022/03/22 13:13:45 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	if (!s)
		return (0);
	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	cont;
	size_t	cont2;

	if (s1 == NULL && s2[0] == '\0')
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	cont = -1;
	while (s1[++cont] != '\0')
		new[cont] = s1[cont];
	cont2 = 0;
	while (s2[cont2] != '\0')
		new[cont++] = s2[cont2++];
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	cont;
	size_t	c;

	if (start == len)
		return (NULL);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	cont = start;
	c = 0;
	while (cont < ft_strlen(s) && c < len)
	{
		ptr[c] = s[cont];
		c++;
		cont++;
	}
	ptr[c] = '\0';
	if (ptr[0] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
