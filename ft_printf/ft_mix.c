/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:18:19 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/23 20:10:09 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mix(unsigned long int lin, char g)
{
	char		*stuped;
	int static	kol;

	kol = 0;
	if (g == 'x')
		stuped = "0123456789abcdef";
	if (g == 'X')
		stuped = "0123456789ABCDEF";
	if (lin > 15)
		ft_mix(lin / 16, g);
	ft_putchar(stuped[lin % 16]);
	kol++;
	return (kol);
}

int	ft_direccion_i_y_d(int d, int i)
{
	if (d == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (d >= 0 && d < 10)
		i = ft_putchar(d + '0');
	else if (d < 0)
	{
		i = ft_putchar('-');
		i += ft_direccion_i_y_d(-d, i);
	}
	else
	{
		i = ft_direccion_i_y_d(d / 10, i);
		i += ft_putchar(d % 10 + '0');
	}
	return (i);
}
/*
int main ()
{
	int i = 98;

	printf("%d\n", ft_mix(i, 'x'));
	printf("%x", i);
}


#include <stdio.h>
int	main ()
{
	int y = -9;
	printf("\n");
	int a = ft_direccion_i_y_d(y, 0);
	printf("\n");
	int b = printf("%d", y);
	printf("\n");
	printf("%d\n %d\n", a, b);
	//printf("\n");
	//printf("%d", y);
}
*/
