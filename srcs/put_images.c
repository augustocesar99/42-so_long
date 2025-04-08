/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/08 14:30:42 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction)
{
	if (direction == 'r')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_r,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'l')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_l,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'u')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_u,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'd')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_d,
			map->player_x * 64, map->player_y * 64);
}

void	put_coin_and_enemy(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, spt->coin,
					x * 64, y * 64);
			else if (map->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->window, spt->zombie,
					x * 64, y * 64);
		}
	}
}

void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (y == 0 && x == 0)
					mlx_put_image_to_window(game->mlx, game->window, spt->bmo,
						0, 0);
				else
					mlx_put_image_to_window(game->mlx, game->window, spt->wall,
						x * 64, y * 64);
			}
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, spt->ground,
					x * 64, y * 64);
		}
	}
}

void	put_exit(t_map *map, t_game *game, t_sprite *spt)
{
	int	delay;

	delay = 0;
	while (delay++ < 4000)
		mlx_put_image_to_window(game->mlx, game->window, spt->exit1,
			map->exit_x * 64, map->exit_y * 64);
	while (delay++ < 8000)
		mlx_put_image_to_window(game->mlx, game->window, spt->exit2,
			map->exit_x * 64, map->exit_y * 64);
	while (delay++ < 12000)
		mlx_put_image_to_window(game->mlx, game->window, spt->exit3,
			map->exit_x * 64, map->exit_y * 64);
}

void	print_steps(t_game *game)
{
	char	*steps;
	int		len;
	int		x;
	int		y;

	steps = ft_itoa(game->steps);
	len = ft_strlen(steps);
	x = 32 - (len * len);
	y = 30;
	mlx_string_put(game->mlx, game->window, x, y, 0x21ccbb, steps);
	free(steps);
}
