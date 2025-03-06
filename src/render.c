#include "so_long.h"

static void load_xpm_images(t_game *data)
{
    int width;
    int height;

    width = IMG_WIDTH;
    height = IMG_HEIGHT;

    data->environment.visuals[BACKGROUND].image_data = mlx_xpm_file_to_image(
        data->graphics_engine, (char *)data->background_file, &width, &height);
    data->environment.visuals[WALL_INDEX].image_data = mlx_xpm_file_to_image(
        data->graphics_engine, (char *)data->wall_file, &width, &height);
    data->environment.visuals[COLLECTIBLE_INDEX].image_data = mlx_xpm_file_to_image(
        data->graphics_engine, (char *)data->treasure_file, &width, &height);
    data->environment.visuals[EXIT_INDEX].image_data = mlx_xpm_file_to_image(
        data->graphics_engine, (char *)data->portal_file, &width, &height);
    data->environment.visuals[PLAYER_INDEX].image_data = mlx_xpm_file_to_image(
        data->graphics_engine, (char *)data->hero_file, &width, &height);
}

void render_image(t_game *data, char cell, int x, int y)
{
    int  is_player_on_exit;
    void *image;

    is_player_on_exit = check_player_on_exit(data, x, y);

    if (cell == EMPTY)
        image = data->environment.visuals[BACKGROUND].image_data;
    else if (cell == WALL)
        image = data->environment.visuals[WALL_INDEX].image_data;
    else if (cell == COLLECTIBLE)
        image = data->environment.visuals[COLLECTIBLE_INDEX].image_data;
    else if (cell == EXIT && !is_player_on_exit)
        image = data->environment.visuals[EXIT_INDEX].image_data;
    else if (cell == PLAYER || is_player_on_exit)
        image = data->environment.visuals[PLAYER_INDEX].image_data;
    else
        return;

    mlx_put_image_to_window(data->graphics_engine, data->game_window, image,
                            x * IMG_WIDTH, y * IMG_HEIGHT);
}

void render_map(t_game *data)
{
    char **grid;
    int  x;
    int  y;

    load_xpm_images(data);

    grid = data->environment.terrain;
    y = 0;

    while (grid[y])
    {
        x = 0;
        while (grid[y][x])
        {
            render_image(data, grid[y][x], x, y);
            x++;
        }
        y++;
    }
}