/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:10:33 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/16 14:49:36 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_images(t_game *game)
{
	read_wall(game);
	read_coin(game);
	read_player(game);
	read_background(game);
	read_exit(game);
}

void	set_background(t_game *game)
{
	int		cont;
	int		line;
	int		position;

	cont = 0;
	line = 0;
	position = 0;
	while (game->map_file[cont] != '\0')
	{
		if (game->map_file[cont] == '\n')
		{
			line = line + 60;
			position = 0;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->background,
			position, line);
		cont++;
		position = position + 60;
	}
}

void	set_components(t_game *game, char map_file_cont, int position, int line)
{
	if (map_file_cont == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			position, line);
	else if (map_file_cont == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			position, line);
		game->total_coins++;
	}
	else if (map_file_cont == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_close,
			position, line);
	else if (map_file_cont == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			position, line);
		game->player_position = position;
		game->player_line = line;
	}
}

void	init_game(t_game *game)
{
	int		cont;
	int		position;
	int		line;

	cont = 0;
	position = 0;
	line = 0;
	game->coins = 0;
	game->total_coins = 0;
	game->movements = 0;
	read_images(game);
	set_background(game);
	while (game->map_file[cont] != '\0')
	{
		if (game->map_file[cont] == '\n')
		{
			line = line + 60;
			position = -60;
		}
		set_components(game, game->map_file[cont], position, line);
		cont++;
		position = position + 60;
	}
	mlx_string_put(game->mlx, game->win, game->width - 40, 20, 1, "0");
}
