/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:46:54 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:37:36 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*gf;
	size_t			i;

	gf = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (gf[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *str;
	str = "hollq";
	printf("%s", (char *) ft_memchr(str, 108, 5));
}*/
