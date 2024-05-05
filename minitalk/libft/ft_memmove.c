/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:31 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:27:45 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dar;
	unsigned const char	*sar;
	size_t				i;

	dar = (unsigned char *)dst;
	sar = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			dar[len - 1] = sar[len - 1];
			len--;
		}
	}
	else if (src > dst)
	{
		while (i < len)
		{
			dar[i] = sar[i];
			i++;
		}
	}
	return (dst);
}
/*
int main (void)
{
	char str1[10];
	const char str2[10] = "evet";
	char *ret;

	ret = ft_memmove(str1, str2, 3);
	printf("%s", ret);
	return(0);
}
*/
