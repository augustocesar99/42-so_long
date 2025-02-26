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

// * ENUMS
typedef enum e_cell_type
{
    EMPTY = '0',
    WALL = '1',
    COLLECTIBLE = 'C',
    EXIT = 'E',
    PLAYER = 'P',
    WALKED = '-'
}           t_cell_type;

typedef enum e_asset_index
{
    BACKGROUND = 0,
    WALL_INDEX = 1,
    COLLECTIBLE_INDEX = 2,
    EXIT_INDEX = 3,
    PLAYER_INDEX = 4
}           t_asset_index;

// * STRUCTS (MÁXIMO 4, REDISTRIBUÍDAS)
typedef struct s_sprite
{
    void    *image_data;
    int     pixel_width;
    int     pixel_height;
}           t_sprite;

typedef struct s_world
{
    char        **terrain;
    t_sprite    visuals[5];
    int         treasure_total;
    int         portal_total;
    int         hero_total;
    int         width;
    int         height;
}               t_world;

typedef struct s_player
{
    int     pos_x;
    int     pos_y;
    int     steps_made;
}           t_player;

typedef struct s_game
{
    void        *graphics_engine;
    void        *game_window;
    t_world     environment;
    t_world     pathfinder;
    t_player    adventurer;
    int         screen_max_width;
    int         screen_max_height;
    const char  *valid_elements;
    const char  *step_message;
    const char  *background_file;
    const char  *wall_file;
    const char  *treasure_file;
    const char  *portal_file;
    const char  *hero_file;
}               t_game;

// * CONFIGURAÇÕES GLOBAIS
static const t_game g_game_defaults = {
    .graphics_engine = NULL,
    .game_window = NULL,
    .environment = {0},
    .pathfinder = {0},
    .adventurer = {0, 0, 0},
    .screen_max_width = 1920,
    .screen_max_height = 1080,
    .valid_elements = "01CEP",
    .step_message = "Movement count: %i\n",
    .background_file = "./assets/map/background.xpm",
    .wall_file = "./assets/map/wall.xpm",
    .treasure_file = "./assets/map/collectible.xpm",
    .portal_file = "./assets/map/exit.xpm",
    .hero_file = "./assets/player/player_r_01.xpm"
};

// * FUNCTION PROTOTYPES
int     check_player_on_exit(t_game *data, int x, int y);
int     is_a_wall(char *line);
int     is_cell_valid(char cell);
void    check_exit(t_game *data);
void    clean_grid(char **grid);
void    throw_error(char *msg);
void    clean_exit(t_game *data, char *msg);
void    clean_exit_fd(int fd, char *msg);
void    read_map(t_game *data, char *map_path);
void    validate_map(t_game *data, t_world *map, t_world *flooded_map);
void    render_map(t_game *data);
void    render_image(t_game *data, char cell, int x, int y);
void    handle_movement(t_game *data, int x, int y);
int     on_keypress(int keysym, t_game *data);
int     on_destroy(int keysym, t_game *data);

#endif