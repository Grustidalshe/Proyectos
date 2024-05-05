/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:12:25 by vtrubina          #+#    #+#             */
/*   Updated: 2023/11/30 21:24:42 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*memory;

	total_size = count * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total_size);
	return (memory);
}
/*int	main()
{
	size_t	count = 5;
	int *arr = (int *)ft_calloc(count, sizeof(int));

	if (arr != NULL)
	{
		for (int i; i < count; i++)
		{
			printf("%d", arr[i]);
		}
		free(arr);
	}
	else
	{
		printf("gogogo\n");
	}
	return (0);
}
*/
