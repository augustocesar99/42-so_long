/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:51:36 by acesar-m          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:02 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef SO_LONG_H
#  define SO_LONG_H

# define WIDTH 64
# define HEIGHT 64

# include "../libs/libft/libft.h"
# include "../libs/mlx42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

struct s_mapsvalidation
{
	char	**mapfile;
	char	*filecontent;
	int		player_line;
	int		player_column;
	int		movements_count;
	int		collectibles_count;
	int		collectibles_taken;
	int		player_count;
};

typedef struct s_mapsvalidation t_maps;

struct s_gaming
{
	mlx_t					*mlx_ptr;
	mlx_texture_t	*textute_wallpaper;
	mlx_texture_t	*textute_wall;
	mlx_texture_t	*textute_collectible;
	mlx_texture_t	*textute_exit;
	mlx_texture_t	*textute_player;
	mlx_texture_t	*textute_player_icon;
	mlx_image_t		*image_wallpaper;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_player;
	int						col;
	int						line;
	t_maps			*mapstruct;
};

typedef struct s_gaming t_game;

// map file_validation.c
int		file_validation(char **argv, t_maps *mapcontent);
int		is_extension_valid(char *argv);
char	*read_file(int file_descriptor);
char	*open_file(char *filename);
int		is_there_space(char *text);

// utils.c
void	printmap(char **mapfile);
char	*ft_strchr_inverse(const char *str, int c);

#endif