/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:38:00 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/24 14:14:24 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	good_ending(t_map *map, t_game *game, t_sprite *spt)
{
	int	repeat;

	print_steps(game);
	ft_printf("Steps: %d\n", ++game->steps);
	repeat = 0;
	put_wall_and_ground(map, game, spt);
	while (repeat++ < 8000)
		mlx_put_image_to_window(game->mlx, game->window, spt->win1,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 16000)
		mlx_put_image_to_window(game->mlx, game->window, spt->win2,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 24000)
		mlx_put_image_to_window(game->mlx, game->window, spt->win3,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 32000)
		mlx_put_image_to_window(game->mlx, game->window, spt->win4,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 40000)
		mlx_put_image_to_window(game->mlx, game->window, spt->win5,
			map->player_x * 64, map->player_y * 64);
	ft_printf("VICTORY!!!\n");
	free_for_finish(map, game);
}

void	bad_ending(t_map *map, t_game *game, t_sprite *spt)
{
	int	repeat;

	repeat = 0;
	while (repeat++ < 8000)
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_d,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 16000)
		mlx_put_image_to_window(game->mlx, game->window, spt->death1,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 24000)
		mlx_put_image_to_window(game->mlx, game->window, spt->death2,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 32000)
		mlx_put_image_to_window(game->mlx, game->window, spt->death3,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 40000)
		mlx_put_image_to_window(game->mlx, game->window, spt->death4,
			map->player_x * 64, map->player_y * 64);
	while (repeat++ < 48000)
		mlx_put_image_to_window(game->mlx, game->window, spt->death5,
			map->player_x * 64, map->player_y * 64);
	ft_printf("GAME OVER =(\nTry again\n");
	free_for_finish(map, game);
}
