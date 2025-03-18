/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:32:08 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/27 14:54:12 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_sprites(t_game *game, t_sprite *spt)
{
	spt->finn_d = mlx_xpm_file_to_image(game->mlx, FINN_D, &game->img_width,
			&game->img_height);
	spt->finn_l = mlx_xpm_file_to_image(game->mlx, FINN_L, &game->img_width,
			&game->img_height);
	spt->finn_r = mlx_xpm_file_to_image(game->mlx, FINN_R, &game->img_width,
			&game->img_height);
	spt->finn_u = mlx_xpm_file_to_image(game->mlx, FINN_U, &game->img_width,
			&game->img_height);
	spt->coin = mlx_xpm_file_to_image(game->mlx, COIN, &game->img_width,
			&game->img_height);
	spt->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &game->img_width,
			&game->img_height);
	spt->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width,
			&game->img_height);
	spt->iceking = mlx_xpm_file_to_image(game->mlx, ICEKING, &game->img_width,
			&game->img_height);
	spt->bmo = mlx_xpm_file_to_image(game->mlx, BMO, &game->img_width,
			&game->img_height);
	if (spt->finn_d == NULL || spt->finn_l == NULL || spt->finn_r == NULL
		|| spt->finn_u == NULL || spt->coin == NULL || spt->ground == NULL
		|| spt->wall == NULL || spt->iceking == NULL || spt->bmo == NULL)
		error_check(11, "Error\nFail to take images!\n", 2, game);
	take_exit(game, spt);
	take_win(game, spt);
	take_death(game, spt);
}

void	take_exit(t_game *game, t_sprite *spt)
{
	spt->exit1 = mlx_xpm_file_to_image(game->mlx, EXIT1, &game->img_width,
			&game->img_height);
	spt->exit2 = mlx_xpm_file_to_image(game->mlx, EXIT2, &game->img_width,
			&game->img_height);
	spt->exit3 = mlx_xpm_file_to_image(game->mlx, EXIT3, &game->img_width,
			&game->img_height);
	if (spt->exit1 == NULL || spt->exit2 == NULL || spt->exit3 == NULL)
		error_check(11, "Error\nFail to take images!\n", 2, game);
}

void	take_win(t_game *game, t_sprite *spt)
{
	spt->win1 = mlx_xpm_file_to_image(game->mlx, WIN1, &game->img_width,
			&game->img_height);
	spt->win2 = mlx_xpm_file_to_image(game->mlx, WIN2, &game->img_width,
			&game->img_height);
	spt->win3 = mlx_xpm_file_to_image(game->mlx, WIN3, &game->img_width,
			&game->img_height);
	spt->win4 = mlx_xpm_file_to_image(game->mlx, WIN4, &game->img_width,
			&game->img_height);
	spt->win5 = mlx_xpm_file_to_image(game->mlx, WIN5, &game->img_width,
			&game->img_height);
	if (spt->win1 == NULL || spt->win2 == NULL || spt->win3 == NULL
		|| spt->win4 == NULL || spt->win5 == NULL)
		error_check(11, "Error\nFail to take images!\n", 2, game);
}

void	take_death(t_game *game, t_sprite *spt)
{
	spt->death1 = mlx_xpm_file_to_image(game->mlx, DEATH1, &game->img_width,
			&game->img_height);
	spt->death2 = mlx_xpm_file_to_image(game->mlx, DEATH2, &game->img_width,
			&game->img_height);
	spt->death3 = mlx_xpm_file_to_image(game->mlx, DEATH3, &game->img_width,
			&game->img_height);
	spt->death4 = mlx_xpm_file_to_image(game->mlx, DEATH4, &game->img_width,
			&game->img_height);
	spt->death5 = mlx_xpm_file_to_image(game->mlx, DEATH5, &game->img_width,
			&game->img_height);
	if (spt->death1 == NULL || spt->death2 == NULL || spt->death3 == NULL
		|| spt->death4 == NULL || spt->death5 == NULL)
		error_check(11, "Error\nFail to take images!\n", 2, game);
}
