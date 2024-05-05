/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:54:24 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:54:17 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_line(char const *s, char c)
{
	size_t	cot;
	size_t	i;

	i = 0;
	cot = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		cot++;
	}
	return (cot);
}

static char	*ft_splitdup(char const *s, char c, size_t *start)
{
	char	*dest;
	size_t	i;
	size_t	finish;

	finish = 0;
	while (s[*start + finish] != '\0' && s[*start + finish] != c)
		finish++;
	dest = (char *)malloc(sizeof(char) * (finish + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < finish)
	{
		dest[i] = s[*start + i];
		i++;
	}
	dest[i] = '\0';
	*start += finish;
	while (s[*start] != '\0' && s[*start] == c)
		*start += 1;
	return (dest);
}

static void	*ft_free(char **dest, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(dest[j]);
		j++;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	string;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	string = ft_line(s, c);
	dest = (char **)ft_calloc(string + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start] != '\0' && s[start] == c)
		start += 1;
	while (i < string)
	{
		dest[i] = ft_splitdup(s, c, &start);
		if (dest[i] == NULL)
			return (ft_free(dest, i));
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
