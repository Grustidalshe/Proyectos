/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:48:46 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/19 16:48:49 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned int	i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)pointer;
	while (i < count)
		c[i++] = (unsigned char)value;
	pointer = (void *)c;
	return (pointer);
}
