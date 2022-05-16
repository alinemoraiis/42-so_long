/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:51:54 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/03 16:40:20 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int		map_position;

	map_position = 0;
	map_position = ((game->player_line / 60) * (game->width / 60))
		+ ((game->player_position / 60) + (game->player_line / 60));
	if (game->map_file[map_position + 1] == 'E'
		&& game->total_coins > game->coins)
		put_image(game, game->player_position, game->player_line);
	else if (game->map_file[map_position + 1] != '1')
	{
		if (game->map_file[map_position + 1] == 'C')
		{
			game->map_file[map_position + 1] = '0';
			game->coins++;
		}
		else if (game->map_file[map_position + 1] == 'E'
			&& game->total_coins == game->coins)
			close_game(game);
		put_image(game, game->player_position + 60, game->player_line);
		game->player_position = game->player_position + 60;
		game->movements++;
	}
	else
		put_image(game, game->player_position, game->player_line);
}

void	move_left(t_game *game)
{
	int	map_position;

	map_position = 0;
	map_position = ((game->player_line / 60) * (game->width / 60))
		+ ((game->player_position / 60) + (game->player_line / 60));
	if (game->map_file[map_position - 1] == 'E' && game->total_coins
		> game->coins)
		put_image(game, game->player_position, game->player_line);
	else if (game->map_file[map_position - 1] != '1')
	{
		if (game->map_file[map_position - 1] == 'C')
		{
			game->map_file[map_position - 1] = '0';
			game->coins++;
		}
		else if (game->map_file[map_position - 1] == 'E'
			&& game->total_coins == game->coins)
			close_game(game);
		put_image(game, game->player_position - 60, game->player_line);
		game->player_position = game->player_position - 60;
		game->movements++;
	}
	else
		put_image(game, game->player_position, game->player_line);
}

void	move_down(t_game *game)
{
	int	map_position;

	map_position = 0;
	map_position = ((game->player_line / 60) * (game->width / 60))
		+ ((game->player_position / 60) + (game->player_line / 60));
	if (game->map_file[map_position + (game->width / 60) + 1] == 'E'
		&& game->total_coins > game->coins)
		put_image(game, game->player_position, game->player_line);
	else if (game->map_file[map_position + (game->width / 60) + 1] != '1')
	{
		if (game->map_file[map_position + (game->width / 60) + 1] == 'C')
		{
			game->map_file[map_position + (game->width / 60) + 1] = '0';
			game->coins++;
		}
		else if (game->map_file[map_position + (game->width / 60) + 1] == 'E'
			&& game->total_coins == game->coins)
			close_game(game);
		put_image(game, game->player_position, game->player_line + 60);
		game->player_line = game->player_line + 60;
		game->movements++;
	}
	else
		put_image(game, game->player_position, game->player_line);
}

void	move_up(t_game *game)
{
	int	map_position;

	map_position = 0;
	map_position = ((game->player_line / 60) * (game->width / 60))
		+ ((game->player_position / 60) + (game->player_line / 60));
	if (game->map_file[map_position - (game->width / 60) - 1] == 'E'
		&& game->total_coins > game->coins)
		put_image(game, game->player_position, game->player_line);
	else if (game->map_file[map_position - (game->width / 60) - 1] != '1')
	{
		if (game->map_file[map_position - (game->width / 60) - 1] == 'C')
		{
			game->map_file[map_position - (game->width / 60) - 1] = '0';
			game->coins++;
		}
		else if (game->map_file[map_position - (game->width / 60) - 1] == 'E'
			&& game->total_coins == game->coins)
			close_game(game);
		put_image(game, game->player_position, game->player_line - 60);
		game->player_line = game->player_line - 60;
		game->movements++;
	}
	else
		put_image(game, game->player_position, game->player_line);
}

int	close_game(t_game *game)
{
	free(game->map_file);
	exit(0);
	return (0);
}
