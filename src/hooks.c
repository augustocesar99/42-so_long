#include "so_long.h"

static void handle_movement_keys(int keysym, t_mlx_data *data)
{
    // Verifica qual tecla foi pressionada e move o jogador
    if (keysym == XK_Up || keysym == XK_w)
        handle_movement(data, data->map.player_x, data->map.player_y - 1);
    else if (keysym == XK_Left || keysym == XK_a)
        handle_movement(data, data->map.player_x - 1, data->map.player_y);
    else if (keysym == XK_Down || keysym == XK_s)
        handle_movement(data, data->map.player_x, data->map.player_y + 1);
    else if (keysym == XK_Right || keysym == XK_d)
        handle_movement(data, data->map.player_x + 1, data->map.player_y);
}

static void destroy_images(t_mlx_data *data)
{
    // Destrói todas as imagens carregadas
    mlx_destroy_image(data->connect, data->images[BACKGROUND_INDEX]);
    mlx_destroy_image(data->connect, data->images[WALL_INDEX]);
    mlx_destroy_image(data->connect, data->images[COLLECTIBLE_INDEX]);
    mlx_destroy_image(data->connect, data->images[EXIT_INDEX]);
    mlx_destroy_image(data->connect, data->images[PLAYER_INDEX]);
}

int on_keypress(int keysym, t_mlx_data *data)
{
    // Verifica se a tecla pressionada é de movimento ou de saída
    if (keysym == XK_Escape)
        on_destroy(keysym, data);
    else
        handle_movement_keys(keysym, data);

    return (EXIT_SUCCESS);
}

int on_destroy(int keysym, t_mlx_data *data)
{
    // Remove a chamada para get_data()
    (void)keysym;

    // Limpa as grades do mapa
    clean_grid(data->map.grid);
    clean_grid(data->flooded_map.grid);

    // Destrói as imagens e a janela do MLX
    destroy_images(data);
    mlx_destroy_window(data->connect, data->window);
    mlx_destroy_display(data->connect);

    // Libera a memória e encerra o programa
    free(data->connect);
    exit(EXIT_SUCCESS);
}