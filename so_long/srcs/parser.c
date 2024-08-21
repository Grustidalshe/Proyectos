/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:31:47 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/21 20:41:17 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_value(t_vars *vars, t_check check)
{
	int		i;
	int		j;

	i = 0;
	vars->collect = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->collect++;
			if (vars->map[i][j] == 'P')
			{
				if (vars->map[i + 1][j] == '1' \
						&& vars->map[i - 1][j] == '1' \
						&& vars->map[i][j + 1] == '1' \
						&& vars->map[i][j - 1] == '1' \
						&& vars->map[i + 1][j - 1] == '1'\
						&& vars->map[i + 1][j + 1] == '1' \
						&& vars->map[i - 1][j + 1] == '1' \
						&& vars->map[i - 1][j - 1] == '1')
				{
					printf("Error\n☞ Player locked");
					exit(1);
				}
				vars->mouv->x = j;
				vars->mouv->y = i;
				vars->map[i][j] = '0';
			}
			if (vars->map[i][j] == 'E')
			{
				if (vars->map[i + 1][j] == '1' \
						&& vars->map[i - 1][j] == '1' \
						&& vars->map[i][j + 1] == '1' \
						&& vars->map[i][j - 1] == '1' \
						&& vars->map[i + 1][j - 1] == '1' \
						&& vars->map[i + 1][j + 1] == '1' \
						&& vars->map[i - 1][j + 1] == '1' \
						&& vars->map[i - 1][j - 1] == '1')
				{
					printf("Error\n☞ Exit locked");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	vars->map_x_len = check.len;
	vars->map_y_len = check.i;
}

void	parsing(char *av, t_vars *vars)
{
	t_check		check;
	int			i;

	i = 0;
	check_is_file(av, vars);
	vars->map = ft_calloc(sizeof(char *), (check.i + 1));
	if (!vars->map)
		__exit__(NULL, vars, FAILURE);
	check.fd = open(av, O_RDWR);
	check.read = 1;
	while (check.read)
	{
		check.read = get_next_line(check.fd, &check.line);
		vars->map[i++] = ft_strdup(check.line);
		free(check.line);
	}
	vars->map_x_len = check.len;
	vars->map_y_len = check.i;
	check = check_is_map(av, vars);
	close(check.fd);
	get_value(vars, check);
}
