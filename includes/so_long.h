#ifndef SO_LONG_H
# define SO_LONG_H

// * LIBS
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// * CONSTANTS
# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define MOVEMENT_LOG "Movement count: %i\n"

// * STRUCTURES
typedef struct s_map
{
    char        **grid;
    int         width;
    int         height;
    int         player_x;
    int         player_y;
    int         collectible_count;
    int         exit_count;
    int         player_count;
}               t_map;

typedef struct s_mlx_data
{
    void        *connect;
    void        *window;
    t_map       map;
    t_map       flooded_map;
    int         player_movement_count;
    void        *images[5];
}               t_mlx_data;

// * FUNCTION PROTOTYPES
int     check_player_on_exit(t_mlx_data *data, int x, int y);
int     is_a_wall(char *line);
int     is_cell_valid(char cell);
void    check_exit(t_mlx_data *data);
void    clean_grid(char **grid);
void    throw_error(char *msg);
void    clean_exit(t_mlx_data *data, char *msg);
void    clean_exit_fd(int fd, char *msg);
void    read_map(t_mlx_data *data, char *map_path);
void    validate_map(t_mlx_data *data, t_map *map, t_map *flooded_map);
void    render_map(t_mlx_data *data);
void    render_image(t_mlx_data *data, char cell, int x, int y);
void    handle_movement(t_mlx_data *data, int x, int y);
int     on_keypress(int keysym, t_mlx_data *data);
int     on_destroy(int keysym, t_mlx_data *data);

#endif