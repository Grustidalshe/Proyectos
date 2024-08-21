/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:30:27 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/19 17:30:35 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	counter_bonus(t_vars *vars)
{
	const char		*str = ft_itoa(vars->counter);

	if (!str)
		__exit__(NULL, vars, FAILURE);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xFF0000, (char *)str);
	free((char *)str);
}
