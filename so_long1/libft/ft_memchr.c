/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:48:00 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/19 16:48:03 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	b;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (str[i] == b)
			return (str + i);
		i++;
	}
	return (NULL);
}
