/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:26:06 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/17 19:41:39 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || \
		(c >= 97 && c <= 122) || \
		(c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
/*
int	main()
{
	int c;

	c = '!';
	printf("%d\n", ft_isalnum(c));
}*/
