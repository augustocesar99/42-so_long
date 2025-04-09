/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/09 12:16:18 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_open_map(int argc, char *map_path, t_map *map)
{
	int		len;
	char	temp[1];

	if (argc != 2)
		error_check(1, "Error\nInput must be: ./so_long maps/<file.ber>\n",
			0, NULL);
	len = ft_strlen(map_path);
	if (len <= 9 || (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0))
		error_check(2, "Error\nInvalid map name!\n", 0, NULL);
	map->file = map_path;
	map->fd = open(map_path, O_RDONLY);
	if (map->fd < 0 || read(map->fd, temp, 1) == 0)
	{
		close(map->fd);
		error_check(3, "Error\nMap doesn't exist!\n", 0, NULL);
	}
	close(map->fd);
}

void	read_map_lines(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		if (map->width == 0)
			map->width = ft_strlen(line) - 1;
		if (map->width != (int)(ft_strlen(line) - 1)
				&& line[map->width] != '\0')
			map->check_format = 1;
		map->height++;
		free(line);
		line = get_next_line(map->fd);
	}
}

void	valid_map_draw(t_map *map)
{
	t_map	copy;

	map->fd = open(map->file, O_RDONLY);
	draw_map(map);
	if (check_for_wall_surround(map) == 0 || check_for_player(map) == 0
		|| check_for_exit(map) == 0 || check_for_coins(map) == 0
		|| check_for_dif_char(map) == 0 || map->check_format == 1)
	{
		free_map(map);
		error_check(8, "Error\nMap does not meet the requirements!\n", 0, NULL);
	}
	copy.height = map->height;
	copy.width = map->width;
	allocs(&copy);
	copy_map(&copy, map);
	copy.path_check = 0;
	copy.coin_count = 0;
	get_map_path(&copy, map->player_y, map->player_x);
	if (copy.coin_count != map->coin || copy.path_check != 1)
	{
		free_map(&copy);
		free_map(map);
		error_check(8, "Error\nIt doesn't match the requirements!\n", 0, NULL);
	}
	free_map(&copy);
}

void	draw_map(t_map *map)
{
	int		x_count;
	int		y_count;
	char	*temp;

	temp = malloc(1 * sizeof(char));
	if (temp == NULL)
		return ;
	y_count = -1;
	while (++y_count < map->height)
	{
		x_count = -1;
		while (++x_count <= map->width)
		{
			if (read(map->fd, temp, 1) == 0)
			{
				free(temp);
				map->map[y_count][x_count] = '\0';
				return ;
			}
			map->map[y_count][x_count] = *temp;
		}
	}
	map->map[y_count][x_count] = '\0';
	free(temp);
	close(map->fd);
}

void	copy_map(t_map *copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j <= map->width)
			copy->map[i][j] = map->map[i][j];
	}
}
