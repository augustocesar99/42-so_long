#include "so_long.h"

static void read_map_file(t_game *data, int map_fd)
{
    char *line;
    char *temp;

    line = get_next_line(map_fd);
    if (!line)
        clean_exit_fd(map_fd, "The map file is empty.\n");

    temp = ft_strdup("");
    while (line)
    {
        data->environment.height++;
        temp = ft_strjoin_free(temp, line);
        free(line);
        line = get_next_line(map_fd);
    }

    data->environment.grid = ft_split(temp, '\n');
    data->pathfinder.grid = ft_split(temp, '\n');
    data->environment.width = ft_strlen(data->environment.grid[0]);
    free(temp);
}

void read_map(t_game *data, char *map_path)
{
    int map_fd;

    map_fd = open(map_path, O_RDONLY);
    if (map_fd == -1)
        throw_error("The map file was not found.\n");

    read_map_file(data, map_fd);
    close(map_fd);
}

static void validate_map_size(t_game *data, t_world *map)
{
    if (map->width * IMG_WIDTH > MAX_SCREEN_WIDTH || map->height * IMG_HEIGHT > MAX_SCREEN_HEIGHT)
        clean_exit(data, "The map size must be less than or equal to 30x17.\n");
}

static void validate_map_walls(t_game *data, t_world *map)
{
    if (!is_a_wall(map->grid[0]) || !is_a_wall(map->grid[map->height - 1]))
        clean_exit(data, "The map must be closed by walls.\n");
}

void validate_map(t_game *data, t_world *map, t_world *flooded_map)
{
    int i;

    validate_map_size(data, map);
    validate_map_walls(data, map);

    i = 0;
    while (i < map->height)
    {
        validate_line(data, map, map->grid[i], i);
        i++;
    }

    if (!map->exit_count || map->exit_count > 1)
        clean_exit(data, "The map must contain one exit.\n");
    if (!map->player_count || map->player_count > 1)
        clean_exit(data, "The map must contain one start position.\n");
    if (!map->collectible_count)
        clean_exit(data, "The map must contain at least one collectible.\n");

    has_valid_path(flooded_map, map->player_x, map->player_y);
    if (flooded_map->exit_count != 1 || flooded_map->collectible_count != map->collectible_count)
        clean_exit(data, "The map must contain a valid path.\n");
}

static void validate_line(t_game *data, t_world *map, char *line, int height)
{
    int i;

    i = 0;
    if (map->width != ft_strlen(line))
        clean_exit(data, "The map must be rectangular.\n");
    if (line[i] != WALL_CELL || line[map->width - 1] != WALL_CELL)
        clean_exit(data, "The map must be closed by walls.\n");

    while (i < map->width)
    {
        if (!is_cell_valid(line[i]))
            clean_exit(data, "The map can only contain the characters 0, 1, C, E and P.\n");

        if (line[i] == COLLECTIBLE_CELL)
            map->collectible_count++;
        else if (line[i] == EXIT_CELL)
            map->exit_count++;
        else if (line[i] == PLAYER_CELL)
        {
            map->player_count++;
            map->player_x = i;
            map->player_y = height;
        }
        i++;
    }
}

static void has_valid_path(t_world *map, int x, int y)
{
    if (map->grid[y][x] == WALL_CELL || map->grid[y][x] == WALKED_CELL)
        return;

    if (map->grid[y][x] == COLLECTIBLE_CELL)
        map->collectible_count++;
    else if (map->grid[y][x] == EXIT_CELL)
        map->exit_count++;

    map->grid[y][x] = WALKED_CELL;
    has_valid_path(map, x + 1, y);
    has_valid_path(map, x - 1, y);
    has_valid_path(map, x, y + 1);
    has_valid_path(map, x, y - 1);
}