/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:57:43 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/21 20:33:10 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char const *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	else
	{
		while (s[len])
		{
			write(1, &s[len++], 1);
		}
	}
	return (len);
}
