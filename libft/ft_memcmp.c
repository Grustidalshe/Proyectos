/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:09:17 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:40:30 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}
/*
int main()
{
	char ar[] = "kok";
	char ar2[] = "kook";

	printf("ar = %s\n", ar);
	printf("ar2 = %s\n", ar2);	
	printf("ft_memcmp(ar, ar2, 5) = %d\n", ft_memcmp(ar, ar2, 5));
	printf("memcmp(ar, ar2, 5) = %d\n", memcmp(ar, ar2, 5));
	return (0);
}
*/
