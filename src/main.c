#include "so_long.h"

static void initialize_game(t_game *data)
{
    // Inicializa a conexão com o MLX
    data->graphics_engine = mlx_init();
    if (!data->graphics_engine)
        clean_exit(data, "Error starting MLX. Please try again!\n");

    // Cria a janela do jogo
    data->game_window = mlx_new_window(data->graphics_engine, data->environment.width * IMG_WIDTH,
                                       data->environment.height * IMG_HEIGHT, "So Long");
    if (!data->game_window)
        clean_exit(data, "Error starting MLX. Please try again!\n");
}

static void setup_hooks(t_game *data)
{
    // Configura os hooks do MLX
    mlx_hook(data->game_window, KeyPress, KeyPressMask, on_keypress, data);
    mlx_hook(data->game_window, DestroyNotify, StructureNotifyMask, on_destroy, data);
}

static void validate_arguments(int argc, char *argv[])
{
    // Valida o número de argumentos
    if (argc != 2)
        throw_error("Invalid number of arguments.\n"
                   "Usage: ./so_long <map_path>.ber\n");

    // Valida a extensão do arquivo do mapa
    if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber"))
        throw_error("The map file extension must be \".ber\".\n");
}

int main(int argc, char *argv[])
{
    t_game data;

    // Valida os argumentos da linha de comando
    validate_arguments(argc, argv);

    // Inicializa a estrutura do jogo
    ft_bzero(&data, sizeof(t_game));

    // Lê e valida o mapa
    read_map(&data, argv[1]);
    validate_map(&data, &data.environment, &data.pathfinder);

    // Inicializa o jogo (MLX e janela)
    initialize_game(&data);

    // Exibe a contagem inicial de movimentos
    ft_printf(data.step_message, data.adventurer.steps_made);

    // Renderiza o mapa
    render_map(&data);

    // Configura os hooks do MLX
    setup_hooks(&data);

    // Inicia o loop principal do MLX
    mlx_loop(data.graphics_engine);

    return (EXIT_SUCCESS);
}