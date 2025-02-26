#include "so_long.h"

static void handle_movement_keys(int keysym, t_game *data)
{
    // Verifica qual tecla foi pressionada e move o jogador
    if (keysym == XK_Up || keysym == XK_w)
        handle_movement(data, data->adventurer.pos_x, data->adventurer.pos_y - 1);
    else if (keysym == XK_Left || keysym == XK_a)
        handle_movement(data, data->adventurer.pos_x - 1, data->adventurer.pos_y);
    else if (keysym == XK_Down || keysym == XK_s)
        handle_movement(data, data->adventurer.pos_x, data->adventurer.pos_y + 1);
    else if (keysym == XK_Right || keysym == XK_d)
        handle_movement(data, data->adventurer.pos_x + 1, data->adventurer.pos_y);
}

static void destroy_images(t_game *data)
{
    // Destrói todas as imagens carregadas
    mlx_destroy_image(data->graphics_engine, data->environment.visuals[0].image_data); // BACKGROUND_INDEX = 0
    mlx_destroy_image(data->graphics_engine, data->environment.visuals[1].image_data); // WALL_INDEX = 1
    mlx_destroy_image(data->graphics_engine, data->environment.visuals[2].image_data); // COLLECTIBLE_INDEX = 2
    mlx_destroy_image(data->graphics_engine, data->environment.visuals[3].image_data); // EXIT_INDEX = 3
    mlx_destroy_image(data->graphics_engine, data->environment.visuals[4].image_data); // PLAYER_INDEX = 4
}

int on_keypress(int keysym, t_game *data)
{
    // Verifica se a tecla pressionada é de movimento ou de saída
    if (keysym == XK_Escape)
        on_destroy(keysym, data);
    else
        handle_movement_keys(keysym, data);

    return (EXIT_SUCCESS);
}

int on_destroy(int keysym, t_game *data)
{
    // Remove a chamada para get_data()
    (void)keysym;

    // Limpa as grades do mapa
    clean_grid(data->environment.terrain);
    clean_grid(data->pathfinder.terrain);

    // Destrói as imagens e a janela do MLX
    destroy_images(data);
    mlx_destroy_window(data->graphics_engine, data->game_window);
    mlx_destroy_display(data->graphics_engine);

    // Libera a memória e encerra o programa
    free(data->graphics_engine);
    exit(EXIT_SUCCESS);
}