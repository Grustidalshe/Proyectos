/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:28:22 by vtrubina          #+#    #+#             */
/*   Updated: 2024/08/19 17:28:26 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len2;

	str = NULL;
	if (s != NULL)
	{
		len2 = ft_strlen(s);
		if (len > len2)
			len = len2;
		if (start > len2)
			start = len2;
		if (start + len > len2)
			len = len2 - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			ft_memmove(str, s + start, len);
			str[len] = '\0';
		}
	}
	return (str);
}
