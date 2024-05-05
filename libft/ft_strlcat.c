/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:53:36 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:29:41 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0 || dstsize <= dst_len)
		return (dstsize + src_len);
	while (i < (dstsize - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main()
{
	char s1[] = "hhgj";
	char s2[] = "23";
	int y;
	int size = 11;
	char buffer[size];

	strcpy(buffer, s1);
	y = ft_strlcat(buffer, s2, size);
	
	puts(buffer);
    printf("Value returned: %d\n",y);
    return(0);
}*/
