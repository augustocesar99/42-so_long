/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:50:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2025/03/18 12:15:23 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(int i, char *errormsg, int program_stage, t_game *game)
{
    if (program_stage >= 1 && game != NULL)
    {
        if (game->map != NULL)
            free_map(game->map);
        if (program_stage == 2)
        {
            if (game->mlx != NULL && game->window != NULL)
                mlx_destroy_window(game->mlx, game->window);
            free_images(game);
            free_exit(game);
            free_win(game);
            free_death(game);
            free_mlx(game);
        }
    }
    ft_printf("%s", errormsg);
    exit(i);
}

void	free_for_finish(t_map *map, t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_exit(game);
	free_win(game);
	free_death(game);
	free_map(map);
	free_mlx(game);
	exit(0);
}
