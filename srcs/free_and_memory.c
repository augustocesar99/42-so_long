/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/09 11:06:47 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocs(t_map *map)
{
	int	i;
	int	j;

	map->map = malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		error_check(7, "Error\nFail to allocate memory!", 0, NULL);
	i = -1;
	while (++i < map->height)
	{
		if (i == map->height - 1)
			map->map[i] = malloc((map->width + 1) * sizeof(char));
		else
			map->map[i] = malloc((map->width + 2) * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(map->map[j]);
			free(map->map);
			error_check(7, "Error\nFail to allocate memory!", 0, NULL);
		}
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->map);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
