/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:34:04 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/12 17:06:49 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *file)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error!\nThere is no .ber file.");
		exit(1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error!\nThe .ber file is empty.");
		exit(1);
	}
	while (line != NULL)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	return (map);
}

int	get_width(t_game *game)
{
	int	width;

	width = 0;
	while (game->map_file[width] != '\n')
		width++;
	return (width * 60);
}

void	error_game(t_game *game)
{
	ft_printf("Error!\nThe map is not retangular.");
	close_game(game);
}

int	get_height(t_game *game)
{
	int	height;
	int	cont;
	int	len;
	int	ii;

	height = 1;
	cont = 0;
	len = 0;
	ii = 0;
	while (game->map_file[len] != '\n')
		len++;
	while (game->map_file[cont] != '\0')
	{
		ii++;
		if (game->map_file[cont] == '\n')
		{
			height++;
			if ((ii - 1) != len)
				error_game(game);
			ii = 0;
		}
		cont++;
	}
	return (height * 60);
}

char	*open_window(t_game *game)
{
	game->width = get_width(game);
	game->height = get_height(game);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	return (game->win);
}
