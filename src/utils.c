#include "so_long.h"

int check_player_on_exit(t_game *data, int x, int y)
{
    // Verifica se o jogador está na posição da saída
    if (data->environment.player_x == x && data->environment.player_y == y)
        return (1);
    return (0);
}

int is_a_wall(char *line)
{
    // Verifica se a linha é composta apenas por paredes
    while (*line)
    {
        if (*line++ != WALL)
            return (0);
    }
    return (1);
}

int is_cell_valid(t_game *data, char cell)
{
    // Verifica se a célula contém um caractere válido
    if (!ft_strchr(data->valid_elements, cell))
        return (0);
    return (1);
}

void check_exit(t_game *data)
{
    // Verifica se o jogador coletou todos os itens e está na saída
    if (!data->environment.treasure_total)
    {
        ft_printf("\033[1;32m" "\nCONGRATULATIONS!\n" "\033[0m");
        ft_printf("\033[32m" "You won with %i movements.\n\n" "\033[0m",
                  data->adventurer.steps_made);
        on_destroy(0, data);
    }
}

void clean_grid(char **grid)
{
    int i;

    // Libera a memória alocada para o grid
    i = 0;
    while (grid[i])
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}
