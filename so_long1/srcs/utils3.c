#include "../so_long.h"

/*int   check_is_file(char *av, t_vars *vars)
{
        int     i;

        i = ft_strlen(av);
        while (av[i] != '.')
        {
                if (i == 0)
                        __exit__("Error\n☞ bad file\n", vars, FAILURE);
                i--;
        }
        i++;
        if (ft_strcmp((av + i), "ber") != 0)
                __exit__("Error\n☞ bad file extension\n", vars, FAILURE);
        return (1);
}
*/

int is_surrounded_by_walls(t_vars *vars, char **map, int x, int y) {
    // Проверяем верх, низ, слева и справа от текущей позиции
    if ((map[y - 1][x] == '1' || y - 1 < 0) &&
        (map[y + 1][x] == '1' || y + 1 >= vars->map_y_len) &&
        (map[y][x - 1] == '1' || x - 1 < 0) &&
        (map[y][x + 1] == '1' || x + 1 >= vars->map_x_len)) {
        return (1);
    }
    return (0);
}

// Функция для проверки валидности карты
int validate_map(t_vars *vars) {
    int x, y;

    y = 0;
    while (y < vars->map_y_len) {
        x = 0;
        while (x < vars->map_x_len) {
            if (vars->map[y][x] == 'P' || vars->map[y][x] == 'E') {
                // Проверяем, окружены ли персонаж или выход стенами
                if (is_surrounded_by_walls(vars, vars->map, x, y)) {
                    __exit__("Error\n☞ Character or Exit is surrounded by walls\n", vars, FAILURE);
                }
            }
            x++;
        }
        y++;
    }
    return check_playable(vars); // Проверка на проходимость карты
}

// Функция flood fill для проверки проходимости карты
void flood_fill(int x, int y, char **gridcopy, t_mouv *exit_coll, t_vars *vars) {
    if (x < 0 || x >= vars->map_x_len || y < 0 || y >= vars->map_y_len)
        return;

    if (ff_get_position(gridcopy[y][x], exit_coll, vars) == 0) {
        gridcopy[y][x] = 'F';
        flood_fill(x, y + 1, gridcopy, exit_coll, vars);
        flood_fill(x + 1, y, gridcopy, exit_coll, vars);
        flood_fill(x, y - 1, gridcopy, exit_coll, vars);
        flood_fill(x - 1, y, gridcopy, exit_coll, vars);
    }
}

// Функция для проверки позиции в flood fill
int ff_get_position(char old, t_mouv *exit_coll, t_vars *vars) {
    if (old == 'P' || old == '0')
        return (0);
    else if (old == 'E') {
        exit_coll->x++;
        return (0);
    } else if (old == 'C') {
        exit_coll->y++;
        return (0);
    }
    __exitc__(6, vars, FAILURE); // Ошибка 6: "Error\n☞ Map error\n"
    return (1);
}

// Функция для проверки проходимости карты
int check_playable(t_vars *vars) {
    t_mouv exit_coll;

    exit_coll.x = 0;
    exit_coll.y = 0;
    flood_fill(vars->mouv->x, vars->mouv->y, vars->map, &exit_coll, vars);
    if (exit_coll.y == vars->collect && exit_coll.x == 1)
        return (1);
    __exitc__(4, vars, FAILURE); // Ошибка 4: "Error\n☞ Bad map\n"
    return (0);
}

// Функция проверки файла
int check_is_file(char *av, t_vars *vars) {
    int i;

    i = ft_strlen(av);
    while (av[i] != '.') {
        if (i == 0)
            __exit__("Error\n☞ bad file\n", vars, FAILURE);
        i--;
    }
    i++;
    if (ft_strcmp((av + i), "ber") != 0)
        __exit__("Error\n☞ bad file extension\n", vars, FAILURE);
    return (1);
}

// Основной цикл игры
void play_loop(int *nbr, int r, t_vars *vars) {
    int i;

    i = 0;
    if (!r) {
        while (i < 3) {
            if (nbr[i++] < 1 || nbr[2] > 1)
                __exitc__(4, vars, FAILURE);
        }
    }
}
