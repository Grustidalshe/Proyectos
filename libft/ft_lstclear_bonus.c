/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:58:02 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/20 13:08:38 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;

	if (del && lst)
	{
		while (*lst)
		{
			a = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = a;
		}
	}
	lst = NULL;
}
/*int main()
{
	t_list *lk;

	lk = ft_lstnew("work 1");
	lk ->next = ft_lstnew("work 2");
	lk ->next ->next = ft_lstnew("work 3");
	ft_lstclear(&(lst -> next), del);
	while (lst)
	{	
		printf("%s\n", lst -> content);
		lst = lst -> next;
	}
}*/
