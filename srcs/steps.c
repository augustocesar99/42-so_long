/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:40:36 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/24 14:12:39 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_right(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1XE", map->map[y][x + 1]) != NULL)
	{
		if (map->map[y][x + 1] == 'X')
			bad_ending(map, game, game->spt);
		else if (map->map[y][x + 1] == 'E' && map->coin == 0)
		{
			map->map[y][x] = '0';
			map->player_x++;
			good_ending(map, game, game->spt);
		}
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y][x + 1] == 'C')
		map->coin--;
	map->map[y][x + 1] = 'P';
	map->player_x++;
	put_wall_and_ground(map, game, game->spt);
	put_player(map, game, game->spt, 'r');
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_left(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1XE", map->map[y][x - 1]) != NULL)
	{
		if (map->map[y][x - 1] == 'X')
			bad_ending(map, game, game->spt);
		else if (map->map[y][x - 1] == 'E' && map->coin == 0)
		{
			map->map[y][x] = '0';
			map->player_x--;
			good_ending(map, game, game->spt);
		}
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y][x - 1] == 'C')
		map->coin--;
	map->map[y][x - 1] = 'P';
	map->player_x--;
	put_wall_and_ground(map, game, game->spt);
	put_player(map, game, game->spt, 'l');
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_down(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1XE", map->map[y + 1][x]) != NULL)
	{
		if (map->map[y + 1][x] == 'X')
			bad_ending(map, game, game->spt);
		else if (map->map[y + 1][x] == 'E' && map->coin == 0)
		{
			map->map[y][x] = '0';
			map->player_y++;
			good_ending(map, game, game->spt);
		}
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y + 1][x] == 'C')
		map->coin--;
	map->map[y + 1][x] = 'P';
	map->player_y++;
	put_wall_and_ground(map, game, game->spt);
	put_player(map, game, game->spt, 'd');
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_up(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1XE", map->map[y - 1][x]) != NULL)
	{
		if (map->map[y - 1][x] == 'X')
			bad_ending(map, game, game->spt);
		else if (map->map[y - 1][x] == 'E' && map->coin == 0)
		{
			map->map[y][x] = '0';
			map->player_y--;
			good_ending(map, game, game->spt);
		}
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y - 1][x] == 'C')
		map->coin--;
	map->map[y - 1][x] = 'P';
	map->player_y--;
	put_wall_and_ground(map, game, game->spt);
	put_player(map, game, game->spt, 'u');
	ft_printf("Steps: %d\n", ++game->steps);
}
