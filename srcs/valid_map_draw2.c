/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_draw2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/08 11:10:53 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_wall_surround(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map->height)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
	return (1);
}

int	check_for_dif_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (ft_strchr(MAP_CHARS, map->map[i][j]) == NULL)
				return (0);
	}
	return (1);
}

void	get_map_path(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->coin_count++;
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
		return ;
	map->map[y][x] = '1';
	if (map->map[y - 1][x] == 'E' || map->map[y + 1][x] == 'E' ||
		map->map[y][x - 1] == 'E' || map->map[y][x + 1] == 'E')
		map->path_check = 1;
	if (ft_strchr("1XE", map->map[y - 1][x]) == NULL)
		get_map_path(map, y - 1, x);
	if (ft_strchr("1XE", map->map[y + 1][x]) == NULL)
		get_map_path(map, y + 1, x);
	if (ft_strchr("1XE", map->map[y][x - 1]) == NULL)
		get_map_path(map, y, x - 1);
	if (ft_strchr("1XE", map->map[y][x + 1]) == NULL)
		get_map_path(map, y, x + 1);
}
