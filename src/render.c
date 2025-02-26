#include "so_long.h"

static void load_xpm_images(t_game *data)
{
    int width;
    int height;

    width = IMG_WIDTH;
    height = IMG_HEIGHT;

    // Carrega todas as imagens necessárias
    data->images[BACKGROUND_INDEX] = mlx_xpm_file_to_image(data->connect,
                                          BACKGROUND_IMG, &width, &height);
    data->images[WALL_INDEX] = mlx_xpm_file_to_image(data->connect,
                                      WALL_IMG, &width, &height);
    data->images[COLLECTIBLE_INDEX] = mlx_xpm_file_to_image(data->connect,
                                            COLLECTIBLE_IMG, &width, &height);
    data->images[EXIT_INDEX] = mlx_xpm_file_to_image(data->connect,
                                      EXIT_IMG, &width, &height);
    data->images[PLAYER_INDEX] = mlx_xpm_file_to_image(data->connect,
                                        PLAYER_IMG, &width, &height);
}

static void render_cell(t_game *data, char cell, int x, int y)
{
    int  is_player_on_exit;
    void *image;

    // Verifica se o jogador está na saída
    is_player_on_exit = check_player_on_exit(data, x, y);

    // Determina qual imagem deve ser renderizada
    if (cell == EMPTY_CELL)
        image = data->images[BACKGROUND_INDEX];
    else if (cell == WALL_CELL)
        image = data->images[WALL_INDEX];
    else if (cell == COLLECTIBLE_CELL)
        image = data->images[COLLECTIBLE_INDEX];
    else if (cell == EXIT_CELL && !is_player_on_exit)
        image = data->images[EXIT_INDEX];
    else if (cell == PLAYER_CELL || is_player_on_exit)
        image = data->images[PLAYER_INDEX];
    else
        return;

    // Renderiza a imagem na janela
    mlx_put_image_to_window(data->connect, data->window, image,
                            x * IMG_WIDTH, y * IMG_HEIGHT);
}

void render_map(t_game *data)
{
    char **grid;
    int  x;
    int  y;

    // Carrega as imagens XPM
    load_xpm_images(data);

    // Obtém o grid do mapa
    grid = data->map.grid;
    y = 0;

    // Percorre o grid e renderiza cada célula
    while (grid[y])
    {
        x = 0;
        while (grid[y][x])
        {
            render_cell(data, grid[y][x], x, y);
            x++;
        }
        y++;
    }
}
