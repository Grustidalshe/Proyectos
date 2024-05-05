/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:15:19 by vtrubina          #+#    #+#             */
/*   Updated: 2023/10/21 00:25:04 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst || del)
	{
		(*del)(lst ->content);
		free(lst);
	}
}
/*
int	main ()
{
	t_list	*kik;

	kik = ft_lstnew(kjkj);
	printf("%s\n", ft_lstdelone(kik));
}*/
