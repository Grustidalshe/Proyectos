/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:31:47 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/21 23:32:31 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int check_room(int i, int j, t_vars *vars, char *message)
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
		printf("%s", message);
		return 1;
	}
	return 0;

}

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
				if (check_room(i, j, vars, "Error\n☞ Player locked") == 1)
					exit(1);
				else
				{
					vars->mouv->x = j;
					vars->mouv->y = i;
					vars->map[i][j] = '0';
				}
			}
			if (vars->map[i][j] == 'E')
			{
				if (check_room(i, j, vars, "Error\n☞ Exit locked") == 1)
					exit(1);
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

setbuf(stdout, NULL);
	check_is_file(av, vars);
	//if (!vars->map)
	//	__exit__(NULL, vars, FAILURE);
	
	check.fd = open(av, O_RDWR);
	check.read = 1;
	while (check.read)
	{
		check.read = get_next_line(check.fd, &check.line);
		i++;
		free(check.line);
	}
	close(check.fd);
	vars->map = ft_calloc(sizeof(char *), (i + 1));
	check.fd = open(av, O_RDWR);
	i = 0;
	while (check.read)
	{
		check.read = get_next_line(check.fd, &check.line);
		vars->map[i++] = ft_strdup(check.line);
		free(check.line);
	}

	vars->map_x_len = check.len;
	vars->map_y_len = check.i;
	//vars->map = ft_calloc(sizeof(char *), (i + 1));
	check = check_is_map(av, vars);
	close(check.fd);
	get_value(vars, check);
}
