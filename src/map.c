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

    data->environment.terrain = ft_split(temp, '\n');
    data->pathfinder.terrain = ft_split(temp, '\n');
    data->environment.width = ft_strlen(data->environment.terrain[0]);
    free(temp);
}

void read_map(t_game *data, char *map_path)
{
    int map_fd;
    ft_printf("Tentando abrir: %s\n", map_path);
    map_fd = open(map_path, O_RDONLY);
    if (map_fd == -1)
    {
        ft_printf("Erro ao abrir: %s (errno: %d)\n", map_path, error);
        throw_error("The map file was not found.\n");
    }
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
    if (!is_a_wall(map->terrain[0]) || !is_a_wall(map->terrain[map->height - 1]))
        clean_exit(data, "The map must be closed by walls.\n");
}

void validate_line(t_game *data, t_world *map, char *line, int height)
{
    int i;

    i = 0;
    if (map->width != ft_strlen(line))
        clean_exit(data, "The map must be rectangular.\n");
    if (line[i] != WALL || line[map->width - 1] != WALL)
        clean_exit(data, "The map must be closed by walls.\n");

    while (i < map->width)
    {
        if (!is_cell_valid(data, line[i]))
            clean_exit(data, "The map can only contain the characters 0, 1, C, E and P.\n");

        if (line[i] == COLLECTIBLE)
            map->treasure_total++;
        else if (line[i] == EXIT)
            map->portal_total++;
        else if (line[i] == PLAYER)
        {
            map->hero_total++;
            map->player_x = i;
            map->player_y = height;
        }
        i++;
    }
}

void validate_map(t_game *data, t_world *map, t_world *flooded_map)
{
    int i;

    validate_map_size(data, map);
    validate_map_walls(data, map);

    i = 0;
    while (i < map->height)
    {
        validate_line(data, map, map->terrain[i], i);
        i++;
    }

    if (!map->portal_total || map->portal_total > 1)
        clean_exit(data, "The map must contain one exit.\n");
    if (!map->hero_total || map->hero_total > 1)
        clean_exit(data, "The map must contain one start position.\n");
    if (!map->treasure_total)
        clean_exit(data, "The map must contain at least one collectible.\n");
    has_valid_path(flooded_map, map->player_x, map->player_y);
    if (flooded_map->portal_total != 1 || flooded_map->treasure_total != map->treasure_total)
        clean_exit(data, "The map must contain a valid path.\n");
}

void has_valid_path(t_world *map, int x, int y)
{
    if (map->terrain[y][x] == WALL || map->terrain[y][x] == WALKED)
        return;

    if (map->terrain[y][x] == COLLECTIBLE)
        map->treasure_total++;
    else if (map->terrain[y][x] == EXIT)
        map->portal_total++;

    map->terrain[y][x] = WALKED;
    has_valid_path(map, x + 1, y);
    has_valid_path(map, x - 1, y);
    has_valid_path(map, x, y + 1);
    has_valid_path(map, x, y - 1);
}