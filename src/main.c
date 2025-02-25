#include "so_long.h"

static void initialize_game(t_mlx_data *data, char *map_path)
{
    // Inicializa a conexão com o MLX
    data->connect = mlx_init();
    if (!data->connect)
        clean_exit(data, "Error starting MLX. Please try again!\n");

    // Cria a janela do jogo
    data->window = mlx_new_window(data->connect, data->map.width * IMG_WIDTH,
                                 data->map.height * IMG_HEIGHT, "So Long");
    if (!data->window)
        clean_exit(data, "Error starting MLX. Please try again!\n");
}

static void setup_hooks(t_mlx_data *data)
{
    // Configura os hooks do MLX
    mlx_hook(data->window, KeyPress, KeyPressMask, on_keypress, data);
    mlx_hook(data->window, DestroyNotify, StructureNotifyMask, on_destroy, data);
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
    t_mlx_data data; // Declara a variável localmente

    // Inicializa a estrutura (se necessário)
    ft_bzero(&data, sizeof(t_mlx_data));

    // Valida os argumentos da linha de comando
    validate_arguments(argc, argv);

    // Lê e valida o mapa
    read_map(&data, argv[1]);
    validate_map(&data, &data.map, &data.flooded_map);

    // Inicializa o jogo (MLX e janela)
    initialize_game(&data, argv[1]);

    // Exibe a contagem inicial de movimentos
    ft_printf(MOVEMENT_LOG, data.player_movement_count);

    // Renderiza o mapa
    render_map(&data);

    // Configura os hooks do MLX
    setup_hooks(&data);

    // Inicia o loop principal do MLX
    mlx_loop(data.connect);

    return (EXIT_SUCCESS);
}