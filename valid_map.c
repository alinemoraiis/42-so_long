/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:44:02 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/16 14:51:58 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_components(t_map *map)
{
	if (map->other != 0)
		ft_printf("Error!\nThere is an incorrect character in the map.ber.");
	else if (map->wall == 0)
		ft_printf("Error!\nThere is no wall (1) in map.ber.");
	else if (map->banana == 0)
		ft_printf("Error!\nThere is no collectible (C) in map.ber.");
	else if (map->exit == 0)
		ft_printf("Error!\nThere is no exit (E) in map.ber.");
	else if (map->player == 0)
		ft_printf("Error!\nThere is no starting position (P) in map.ber.");
	else
		return (0);
	return (1);
}

void	count_components(t_game *game, t_map *map)
{
	int		cont;

	cont = 0;
	while (game->map_file[cont] != '\0')
	{
		if (game->map_file[cont] == '1')
			map->wall++;
		else if (game->map_file[cont] == 'C')
			map->banana++;
		else if (game->map_file[cont] == '0')
			map->empty_space++;
		else if (game->map_file[cont] == 'E')
			map->exit++;
		else if (game->map_file[cont] == 'P')
			map->player++;
		else if (game->map_file[cont] == '\n')
			map->lines++;
		else
			map->other++;
		cont++;
	}
	if (check_components(map) == 1)
		close_game(game);
}

int	check_border(t_game *game, t_map *map)
{
	int		cont;
	int		line;

	cont = 0;
	line = 0;
	while (game->map_file[cont] != '\0')
	{
		if (line == 0)
			if (game->map_file[cont] != '1' && game->map_file[cont] != '\n')
				return (1);
		if (line == map->lines)
			if (game->map_file[cont] != '1')
				return (1);
		if (game->map_file[cont] == '\n')
		{
			if (game->map_file[cont - 1] != '1'
				|| game->map_file[cont + 1] != '1')
				return (1);
			line++;
		}
		cont++;
	}
	return (0);
}

void	valid_map(t_game *game)
{
	t_map	map;

	map.empty_space = 0;
	map.wall = 0;
	map.banana = 0;
	map.exit = 0;
	map.player = 0;
	map.other = 0;
	map.lines = 0;
	count_components(game, &map);
	if (check_border(game, &map) == 1)
	{
		ft_printf("Error!\nMap isn't surrounded by wall.");
		close_game(game);
	}
}
