/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:11:23 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/19 12:50:06 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char	ptr[19] = "hey nautilus";
	char	c = 'b';

	printf("Original: %s\n", ptr);
	ft_memset(ptr + 3, c, 4);
	printf("Modificado: %s\n", ptr);
}*/
