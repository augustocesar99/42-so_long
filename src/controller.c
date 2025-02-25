#include "so_long.h"

static void handle_cell_interaction(t_game *game, int x, int y)
{
    // Verifica se a célula de destino não é a saída
    if (game->environment.terrain[y][x] != EXIT)
    {
        // Se for uma parede, não move o jogador
        if (game->environment.terrain[y][x] == WALL)
            return;

        // Se for um coletável, decrementa a contagem de tesouros
        if (game->environment.terrain[y][x] == COLLECTIBLE)
            game->environment.treasure_total--;

        // Atualiza a célula de destino para o jogador
        game->environment.terrain[y][x] = PLAYER;
    }
}

static void render_previous_cell(t_game *game)
{
    // Atualiza a célula anterior do jogador
    if (game->environment.terrain[game->adventurer.pos_y][game->adventurer.pos_x] == EXIT)
    {
        // Se o jogador estava na saída, renderiza a saída novamente
        mlx_put_image_to_window(game->graphics_engine, game->game_window,
                               game->environment.visuals[EXIT_INDEX].image_data,
                               game->adventurer.pos_x * game->environment.visuals[EXIT_INDEX].pixel_width,
                               game->adventurer.pos_y * game->environment.visuals[EXIT_INDEX].pixel_height);
    }
    else
    {
        // Se não, atualiza a célula anterior para vazia
        game->environment.terrain[game->adventurer.pos_y][game->adventurer.pos_x] = EMPTY;
        render_image(game, EMPTY, game->adventurer.pos_x, game->adventurer.pos_y);
    }
}

static void update_player_position(t_game *game, int x, int y)
{
    // Atualiza a posição do jogador
    game->adventurer.pos_x = x;
    game->adventurer.pos_y = y;
}

void handle_movement(t_game *game, int x, int y)
{
    // Interage com a célula de destino (paredes, coletáveis, etc.)
    handle_cell_interaction(game, x, y);

    // Renderiza a célula anterior do jogador
    render_previous_cell(game);

    // Atualiza a posição do jogador
    update_player_position(game, x, y);

    // Renderiza o jogador na nova posição
    render_image(game, game->environment.terrain[y][x], x, y);

    // Incrementa a contagem de movimentos e exibe no console
    ft_printf(game->step_message, ++game->adventurer.steps_made);

    // Verifica se o jogador está na saída e se o jogo deve terminar
    if (game->environment.terrain[y][x] == EXIT)
        check_exit(game);
}