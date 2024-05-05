/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:31:51 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:39 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_size(long length)
{
	int	j;

	j = 1;
	if (length < 0)
	{
		j = j + 1;
	}
	while (length / 10 != 0)
	{
		length = length / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		size_l;
	long	nb;

	nb = (long)n;
	size_l = ft_size(nb);
	dst = (char *)malloc(sizeof(char) * (size_l + 1));
	if (!(dst))
		return (NULL);
	dst[size_l] = 0;
	if (nb < 0)
	{
		*dst = '-';
		nb = -nb;
	}
	if (nb == 0)
		dst[0] = '0';
	while (nb > 0)
	{
		dst[size_l - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size_l--;
	}
	return (dst);
}
/*
int main()
{
	long long  num;

	num = 18193775;
	printf("%s", ft_itoa(num));
	return (0);
}*/
