/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:09:39 by ados-rei          #+#    #+#             */
/*   Updated: 2022/03/22 13:34:22 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*read_file(int fd, char *file)
{
	char	*temp;
	int		cont;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	cont = 1;
	while (!ft_strchr(file, '\n') && cont != 0)
	{
		cont = read(fd, temp, BUFFER_SIZE);
		if (cont == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[cont] = '\0';
		file = ft_strjoin(file, temp);
	}
	free(temp);
	return (file);
}

char	*get_line(char *file)
{
	char	*line;
	int		cont;

	if (file == NULL)
		return (NULL);
	cont = 0;
	while (file[cont] != '\0' && file[cont] != '\n')
		cont++;
	if (file[0] == '\n')
		cont++;
	if (file[0] == '\n' && file[1] != '\0')
		line = ft_substr(file, 0, cont);
	else
		line = ft_substr(file, 0, cont + 1);
	line[ft_strlen(line) + 1] = '\0';
	return (line);
}

char	*save_file(char *file)
{
	char	*new_file;
	int		cont;
	int		c;

	cont = 0;
	c = 0;
	if (file == NULL)
	{
		free(file);
		return (NULL);
	}
	while (file[cont] && file[cont] != '\n')
		cont++;
	while (file[c] != '\0')
		c++;
	new_file = ft_substr(file, cont + 1, c);
	free(file);
	return (new_file);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*file;

	if (fd < 0)
		return (NULL);
	file = read_file(fd, file);
	line = get_line(file);
	file = save_file(file);
	return (line);
}
