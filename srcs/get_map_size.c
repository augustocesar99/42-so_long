/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:07:15 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/09 12:17:00 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_line_format(t_map *map, char *line)
{
	if (map->width == 0)
		map->width = ft_strlen(line) - 1;
	if (map->width != (int)(ft_strlen(line) - 1) && line[map->width] != '\0')
		map->check_format = 1;
	map->height++;
}

void	get_map_size(t_map *map)
{
	char	*line;

	map->width = 0;
	map->height = 0;
	map->fd = open(map->file, O_RDONLY);
	if (map->fd < 0)
		error_check(3, "Error\nFailed to open map file!\n", 0, NULL);
	map->check_format = 0;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		check_line_format(map, line);
		free(line);
		line = get_next_line(map->fd);
	}
	if (map->check_format == 1)
		error_check(4, "Error\nIt doesn't match the requirements!\n", 0, NULL);
	if (map->height > 16 || map->width > 30)
		error_check(5, "Error\nMap is too big!\n", 0, NULL);
	map->size = map->width * map->height;
	close(map->fd);
}
