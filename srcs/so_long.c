/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/19 16:56:20 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_sprite	spt;

	game.map = &map;
	game.spt = &spt;
	map.file = argv[1];
	game.steps = 0;
	valid_open_map(argc, map.file, &map);
	get_map_size(&map);
	allocation(&map);
	valid_map_draw(&map);
	game_init(&game);
	take_sprites(&game, &spt);
	fill_map(&map, &game);
	gameplay(&game);
}
