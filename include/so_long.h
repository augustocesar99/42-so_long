/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:17:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2025/04/09 11:06:47 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <../libs/minilibx/mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAP_CHARS "01CEP"

# define FINN_D "./textures/person_down.xpm"
# define FINN_L "textures/person_left.xpm"
# define FINN_R "textures/person_right.xpm"
# define FINN_U "textures/person_up.xpm"
# define EXIT1 "textures/exit1.xpm"
# define EXIT2 "textures/exit2.xpm"
# define EXIT3 "textures/exit3.xpm"
# define GROUND "textures/ground.xpm"
# define WALL "textures/wall.xpm"
# define ICEKING "textures/zombie.xpm"
# define BMO "textures/count.xpm"
# define COIN "textures/coin.xpm"
# define DEATH1 "textures/death1.xpm"
# define DEATH2 "textures/death2.xpm"
# define DEATH3 "textures/death3.xpm"
# define DEATH4 "textures/death4.xpm"
# define DEATH5 "textures/death5.xpm"
# define WIN1 "textures/win1.xpm"
# define WIN2 "textures/win2.xpm"
# define WIN3 "textures/win3.xpm"
# define WIN4 "textures/win4.xpm"
# define WIN5 "textures/win5.xpm"

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		coin;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		path_check;
	int		check_format;
}			t_map;

typedef struct s_sprite
{
	void	*finn_d;
	void	*finn_l;
	void	*finn_r;
	void	*finn_u;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*ground;
	void	*wall;
	void	*zombie;
	void	*bmo;
	void	*coin;
	void	*death1;
	void	*death2;
	void	*death3;
	void	*death4;
	void	*death5;
	void	*win1;
	void	*win2;
	void	*win3;
	void	*win4;
	void	*win5;
}			t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			img_width;
	int			img_height;
	int			steps;
	t_sprite	*spt;
	t_map		*map;
}			t_game;

void	valid_open_map(int argc, char *map_path, t_map *map);
void	get_map_size(t_map *map);
void	allocs(t_map *map);
void	valid_map_draw(t_map *map);
void	draw_map(t_map *map);
int		check_for_wall_surround(t_map *map);
int		check_for_player(t_map *map);
int		check_for_exit(t_map *map);
int		check_for_coins(t_map *map);
int		check_for_dif_char(t_map *map);
void	copy_map(t_map *copy, t_map *map);
void	get_map_path(t_map *map, int y, int x);
void	read_map_lines(t_map *map);
void	validate_map_size(t_map *map);
void	validate_map_requirements(t_map *map);
void	initialize_copy_map(t_map *copy, t_map *map);
void	validate_map_paths(t_map *copy, t_map *map);
void	read_map(t_map *map, char *temp);

void	game_init(t_game *game);
void	take_sprites(t_game *game, t_sprite *spt);
void	take_exit(t_game *game, t_sprite *spt);
void	take_win(t_game *game, t_sprite *spt);
void	take_death(t_game *game, t_sprite *spt);

void	fill_map(t_map *map, t_game *game);
void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction);
void	put_coin_and_enemy(t_map *map, t_game *game, t_sprite *spt);
void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt);
void	put_exit(t_map *map, t_game *game, t_sprite *spt);
void	print_steps(t_game *game);

void	gameplay(t_game *game);
void	step_right(t_map *map, t_game *game);
void	step_left(t_map *map, t_game *game);
void	step_up(t_map *map, t_game *game);
void	step_down(t_map *map, t_game *game);

int		no_input(t_game *game);
int		key_pressed(int key, t_game *game);
int		x_press(t_game *game);

void	bad_ending(t_map *map, t_game *game, t_sprite *spt);
void	good_ending(t_map *map, t_game *game, t_sprite *spt);

void	free_map(t_map *map);
void	free_images(t_game *game);
void	free_exit(t_game *game);
void	free_win(t_game *game);
void	free_death(t_game *game);
void	free_mlx(t_game *game);
void	free_for_finish(t_map *map, t_game *game);
void	error_check(int i, char *errormsg, int program_stage, t_game *game);

#endif