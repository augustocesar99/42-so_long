/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/04/09 15:21:19 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_sprites(t_game *game, t_sprite *spt)
{
	spt->person_d = mlx_xpm_file_to_image(game->mlx, PERSON_D, &game->img_width,
			&game->img_height);
	spt->person_l = mlx_xpm_file_to_image(game->mlx, PERSON_L, &game->img_width,
			&game->img_height);
	spt->person_r = mlx_xpm_file_to_image(game->mlx, PERSON_R, &game->img_width,
			&game->img_height);
	spt->person_u = mlx_xpm_file_to_image(game->mlx, PERSON_U, &game->img_width,
			&game->img_height);
	spt->coin = mlx_xpm_file_to_image(game->mlx, COIN, &game->img_width,
			&game->img_height);
	spt->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &game->img_width,
			&game->img_height);
	spt->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width,
			&game->img_height);
	spt->zombie = mlx_xpm_file_to_image(game->mlx, ZOMBIE, &game->img_width,
			&game->img_height);
	spt->tel = mlx_xpm_file_to_image(game->mlx, TEL, &game->img_width,
			&game->img_height);
	if (spt->person_d == NULL || spt->person_l == NULL || spt->person_r == NULL
		|| spt->person_u == NULL || spt->coin == NULL || spt->ground == NULL
		|| spt->wall == NULL || spt->zombie == NULL || spt->tel == NULL)
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
