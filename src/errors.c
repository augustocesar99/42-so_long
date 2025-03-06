#include "so_long.h"

void throw_error(char *msg)
{
    ft_printf("Error\n");
    ft_printf(msg);
    exit(EXIT_FAILURE);
}

void clean_exit(t_game *data, char *msg)
{
    ft_printf("Error\n");
    ft_printf(msg);
    clean_grid(data->environment.terrain);
    clean_grid(data->pathfinder.terrain);
    if (data->game_window)
        mlx_destroy_window(data->graphics_engine, data->game_window);
    if (data->graphics_engine)
        mlx_destroy_display(data->graphics_engine);
    exit(EXIT_FAILURE);
}

void clean_exit_fd(int fd, char *msg)
{
    ft_printf("Error\n");
    ft_printf(msg);
    close(fd);
    exit(EXIT_FAILURE);
}
