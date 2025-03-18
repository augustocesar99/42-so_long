/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:39:22 by acesar-m          #+#    #+#             */
/*   Updated: 2025/03/18 15:40:22 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->spt->finn_d != NULL)
		mlx_destroy_image(game->mlx, game->spt->finn_d);
	if (game->spt->finn_l != NULL)
		mlx_destroy_image(game->mlx, game->spt->finn_l);
	if (game->spt->finn_r != NULL)
		mlx_destroy_image(game->mlx, game->spt->finn_r);
	if (game->spt->finn_u != NULL)
		mlx_destroy_image(game->mlx, game->spt->finn_u);
	if (game->spt->coin != NULL)
		mlx_destroy_image(game->mlx, game->spt->coin);
	if (game->spt->wall != NULL)
		mlx_destroy_image(game->mlx, game->spt->wall);
	if (game->spt->ground != NULL)
		mlx_destroy_image(game->mlx, game->spt->ground);
	if (game->spt->iceking != NULL)
		mlx_destroy_image(game->mlx, game->spt->iceking);
	if (game->spt->bmo != NULL)
		mlx_destroy_image(game->mlx, game->spt->bmo);
}

void	free_exit(t_game *game)
{
	if (game->spt->exit1 != NULL)
		mlx_destroy_image(game->mlx, game->spt->exit1);
	if (game->spt->exit2 != NULL)
		mlx_destroy_image(game->mlx, game->spt->exit2);
	if (game->spt->exit3 != NULL)
		mlx_destroy_image(game->mlx, game->spt->exit3);
}

void	free_win(t_game *game)
{
	if (game->spt->win1 != NULL)
		mlx_destroy_image(game->mlx, game->spt->win1);
	if (game->spt->win2 != NULL)
		mlx_destroy_image(game->mlx, game->spt->win2);
	if (game->spt->win3 != NULL)
		mlx_destroy_image(game->mlx, game->spt->win3);
	if (game->spt->win4 != NULL)
		mlx_destroy_image(game->mlx, game->spt->win4);
	if (game->spt->win5 != NULL)
		mlx_destroy_image(game->mlx, game->spt->win5);
}

void	free_death(t_game *game)
{
	if (game->spt->death1 != NULL)
		mlx_destroy_image(game->mlx, game->spt->death1);
	if (game->spt->death2 != NULL)
		mlx_destroy_image(game->mlx, game->spt->death2);
	if (game->spt->death3 != NULL)
		mlx_destroy_image(game->mlx, game->spt->death3);
	if (game->spt->death4 != NULL)
		mlx_destroy_image(game->mlx, game->spt->death4);
	if (game->spt->death5 != NULL)
		mlx_destroy_image(game->mlx, game->spt->death5);
}
