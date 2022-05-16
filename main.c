/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:34:04 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/12 18:21:24 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game;

	if (argc == 2)
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5) != 0)
		{
			ft_printf("Error!\nThere is no .ber file.");
			exit(1);
		}
		game.mlx = mlx_init();
		game.map_file = read_map(argv[1]);
		game.win = open_window(&game);
		valid_map(&game);
		init_game(&game);
		mlx_key_hook(game.win, key_hook, &game.mlx);
		mlx_hook(game.win, 17, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_printf("Error!\nThe number of arguments is wrong.");
		exit(1);
	}
}
