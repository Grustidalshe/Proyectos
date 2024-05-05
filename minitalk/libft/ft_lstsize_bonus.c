/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:35:52 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 13:05:06 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	p;

	p = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		p++;
	}
	return (p);
}
/*int main()
{
	t_list  *po;
	t_list  *lk;
	t_list  *mn;
	
	po = malloc(sizeof(*po));
	lk = malloc(sizeof(*lk));
	mn = malloc(sizeof(*mn));

	po->next = lk;
	lk->next = mn;
	mn->next = NULL;
	printf ("%d\n", ft_lstsize(po));
	free(po);
	free(lk);
	free(mn);
	return (0);
}*/
