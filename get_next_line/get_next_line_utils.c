/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:10:59 by vtrubina          #+#    #+#             */
/*   Updated: 2024/02/22 01:31:53 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*merger;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	merger = (char *)malloc(i + j + 1);
	if (!s1 || !s2 || !merger)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		merger[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		merger[i++] = s2[j++];
	merger[i] = '\0';
	return (merger);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	duplicate = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (s[i] != '\0')
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s || len < 0)
		return (NULL);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst || !n)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
