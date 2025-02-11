/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:03:15 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/11 15:32:26 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_maps	mapcontent;
	t_game	gamecontent;
	
	if (argc != 2)
		ft_printf("Error\nInvalid number of arguments\n");
	else
	{
		if (file_validation(argv, &mapcontent) == 0);
			return (0);
		gamecontent.mapstruct = &mapcontent;
		mapcontent.mapfile = ft_split(mapcontent.filecontent, '\n');
		free (mapcontent.filecontent);
		if (mapcontent.mapfile == NULL)
			return (0);
		if (is_map_valid(&mapcontent) == 0)
			return (0);
		mapcontent.movements_count = 0;
		ft_printf("Movements: %d\n", mapcontent.movements_count);
		if (game_on(&gamecontent, &mapcontent) == 0)
			return (0);
	}
	return (0);
}