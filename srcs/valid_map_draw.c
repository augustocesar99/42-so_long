/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:40:46 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_player(t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->player++;
				map->player_x = j;
				map->player_y = i;
			}
		}
	}
	if (map->player != 1)
		return (0);
	return (1);
}

int	check_for_exit(t_map *map)
{
	int	i;
	int	j;

	map->exit = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'E')
			{
				map->exit++;
				map->exit_x = j;
				map->exit_y = i;
			}
		}
	}
	if (map->exit != 1)
		return (0);
	return (1);
}

int	check_for_coins(t_map *map)
{
	int	i;
	int	j;

	map->coin = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->map[i][j] == 'C')
				map->coin++;
	}
	if (map->coin < 1)
		return (0);
	return (1);
}
