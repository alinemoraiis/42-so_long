/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:50:06 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/12 18:19:24 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game)
{
	if (game->keycode == 2)
		move_right(game);
	else if (game->keycode == 0)
		move_left(game);
	else if (game->keycode == 1)
		move_down(game);
	else if (game->keycode == 13)
		move_up(game);
}

void	render_components(t_game *game, char map_file_cont, int position,
	int line)
{
	if (map_file_cont == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			position, line);
	else if (map_file_cont == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			position, line);
	else if (map_file_cont == 'E')
	{
		if (game->total_coins == game->coins)
			mlx_put_image_to_window(game->mlx, game->win, game->exit_open,
				position, line);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->exit_close,
				position, line);
	}
	else if (map_file_cont == 'P')
		move_player(game);
}

void	render_game(t_game *game)
{
	int		cont;
	int		position;
	int		line;

	cont = 0;
	position = 0;
	line = 0;
	read_images(game);
	set_background(game);
	while (game->map_file[cont] != '\0')
	{
		if (game->map_file[cont] == '\n')
		{
			line = line + 60;
			position = -60;
		}
		render_components(game, game->map_file[cont], position, line);
		cont++;
		position = position + 60;
	}
	print_movement(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit(0);
		return (0);
	}
	if (keycode == 2 || keycode == 0 || keycode == 1 || keycode == 13)
	{
		mlx_clear_window(game->mlx, game->win);
		game->keycode = keycode;
		render_game(game);
	}
	return (0);
}
