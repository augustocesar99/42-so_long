/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/08 11:53:51 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_check(9, "Error\nCouldn't connect with Xserver!\n", 1, game);
	game->window = mlx_new_window(game->mlx, (game->map->width * 64),
			(game->map->height * 64), "The Walking Dead!");
	if (game->window == NULL)
	{
		free(game->mlx);
		error_check(10, "Error\nCouldn't open the window!\n", 1, game);
	}
}
