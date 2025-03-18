/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_draw2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:13 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/24 07:22:53 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_for_nopath(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->coin_count++;
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
		return ;
	map->map[y][x] = '1';
	if (map->map[y - 1][x] == 'E' || map->map[y + 1][x] == 'E' ||
		map->map[y][x - 1] == 'E' || map->map[y][x + 1] == 'E')
		map->path_check = 1;
	if (ft_strchr("1X", map->map[y - 1][x]) == NULL)
		check_for_nopath(map, y - 1, x);
	if (ft_strchr("1X", map->map[y + 1][x]) == NULL)
		check_for_nopath(map, y + 1, x);
	if (ft_strchr("1X", map->map[y][x - 1]) == NULL)
		check_for_nopath(map, y, x - 1);
	if (ft_strchr("1X", map->map[y][x + 1]) == NULL)
		check_for_nopath(map, y, x + 1);
}
