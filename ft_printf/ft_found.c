/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:50:33 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/21 21:24:06 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_direccion_u(unsigned int u, int i)
{
	if (u >= 10)
		i = ft_direccion_u(u / 10, i);
	i += ft_putchar(u % 10 + '0');
	return (i);
}
