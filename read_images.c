/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:56:35 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/03 16:47:46 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_wall(t_game *game)
{
	int	pos[2];

	game->wall = mlx_xpm_file_to_image(game->mlx, "images/fence.xpm",
			&pos[0], &pos[1]);
}

void	read_coin(t_game *game)
{
	int	pos[2];

	game->coin = mlx_xpm_file_to_image(game->mlx, "images/banana.xpm",
			&pos[0], &pos[1]);
}

void	read_player(t_game *game)
{
	int	pos[2];

	game->player = mlx_xpm_file_to_image(game->mlx, "images/minion.xpm",
			&pos[0], &pos[1]);
}

void	read_background(t_game *game)
{
	int	pos[2];

	game->background = mlx_xpm_file_to_image(game->mlx, "images/background.xpm",
			&pos[0], &pos[1]);
}

void	read_exit(t_game *game)
{
	int	pos[2];

	game->exit_close = mlx_xpm_file_to_image(game->mlx,
			"images/closed-door.xpm", &pos[0], &pos[1]);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "images/open-door.xpm",
			&pos[0], &pos[1]);
}
