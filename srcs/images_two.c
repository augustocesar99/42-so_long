/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:14 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/11 17:10:37 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*gamecontent;

	
}

int	game_on(t_game *gamecontent, t_maps *mapcontent)
{
	gamecontent->col = 0;
	while (mapcontent->mapfile[gamecontent->col] != NULL)
		gamecontent->col++;
	gamecontent->mlx_ptr = mlx_init(ft_strlen(mapcontent->mapfile[0]) * WIDTH,
			gamecontent->col * HEIGHT, "so_long", true);
	gamecontent->texture_player_icon = mlx_load_png("./textures/player_icon.png");
	mlx_set_icon(gamecontent->mlx_ptr, gamecontent->texture_player_icon);
	put_png_to_tex(gamecontent);
	put_tex_to_ima(gamecontent);
	put_right_size(gamecontent, mapcontent);
	put_ima_to_win(gamecontent, mapcontent);
	put_player(gamecontent, mapcontent);
	mlx_key_hook(gamecontent->mlx_ptr, my_keyhook, gamecontent);
	mlx_loop(gamecontent->mlx_ptr);
	close_hook(gamecontent);
	mlx_delete_texture(gamecontent->texture_player_icon);
	mlx_terminate(gamecontent->mlx_ptr);
	return (EXIT_SUCCESS);
}