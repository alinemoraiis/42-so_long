/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ados-rei <ados-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:27:54 by ados-rei          #+#    #+#             */
/*   Updated: 2022/05/16 14:49:32 by ados-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movement(t_game *game)
{
	char	*str;

	str = ft_itoa(game->movements);
	mlx_string_put(game->mlx, game->win, game->width - 40, 20, 1,
		str);
	free (str);
}
