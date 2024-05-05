/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:28:51 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 12:56:50 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*void    mi_funcion(unsigned int i, char *ch)
{
	*ch = *ch + i;
}
int main(void)
{
	char str[] = "hihggh5656||?>";
	printf("%s\n", str);
	ft_striteri(str, mi_funcion);
	printf("%s\n", str);
	return (0);   
}*/
