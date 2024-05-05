/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:03:05 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 13:04:28 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/*int main()
{
	t_list  *lok;
	char    i[] = "koko";
	t_list  *prev;
	char    str[] = "goya";
	
	lok = malloc(sizeof(*lok));
	prev = malloc(sizeof(*prev));
	
	prev->content = (void *)i;
	lok->content = (void *)str;
	
	ft_lstadd_front(&prev, lok);
	printf("%s\n", prev->content);
}*/
