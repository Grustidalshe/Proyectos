/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:02:36 by vtrubina          #+#    #+#             */
/*   Updated: 2024/04/24 05:21:16 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0' && dstsize != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
/*
int main()
{
const char source[] = "AndrEider";			
char destiny[] = "";
size_t destinysize;			
destinysize = 1;			
printf("string 1: %lu\n", ft_strlcpy(destiny, source, destinysize));			
printf("Destiny = string 2: %s\n", destiny);			
return (0);			
}
*/
