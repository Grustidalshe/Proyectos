/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:04:37 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:56:03 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*der;

	i = 0;
	if (!s)
		return (NULL);
	der = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!der)
		return (NULL);
	while (s[i] != '\0')
	{
		der[i] = f(i, s[i]);
		i++;
	}
	der[i] = '\0';
	return (der);
}
/*
char	mi_variante(unsigned char i, char str)
{
	i = 32;
	return (str - i);
	
int main()
{
	char	*tyt;

	tyt = "?toby4ut.?!ou|";
	printf("tyt %s\n", tyt);
	return (0);
}	
*/
