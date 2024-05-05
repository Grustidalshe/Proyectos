/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:15:36 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:50:23 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_new;
	unsigned int	i_len;

	if (s[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	i_len = ft_strlen(s);
	if (start + len > i_len)
		len = i_len;
	if (start >= i_len)
	{
		len = 0;
		start = 0;
	}
	s_new = (char *) malloc((len + 1) * sizeof(char));
	if (!s_new)
		return (NULL);
	ft_strlcpy(s_new, &s[start], len + 1);
	return (s_new);
}
/*
int main(void)
{
	char *s;
	s = "hola buenas";
	printf("%s\n", ft_substr(s, 5, 8));
}
*/
