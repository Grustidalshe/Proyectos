/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:54:45 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/23 20:09:09 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_global(const char s, va_list args)
{
	int	i;

	i = 0;
	if (s == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (s == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		i = ft_putstr("0x") + ft_mix(va_arg(args, unsigned long int), 'x');
	else if (s == 'd' || s == 'i')
		i = ft_direccion_i_y_d(va_arg(args, int), i);
	else if (s == 'u')
		i = ft_direccion_u(va_arg(args, unsigned int), i);
	else if (s == 'x')
		i = ft_mix(va_arg(args, unsigned int), 'x');
	else if (s == 'X')
		i = ft_mix(va_arg(args, unsigned int), 'X');
	else if (s == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			k += ft_global(s[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			k++;
		}
	}
	va_end(args);
	return (k);
}
