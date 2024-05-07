/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrubina <vtrubina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:44:59 by vtrubina          #+#    #+#             */
/*   Updated: 2024/05/05 21:48:31 by vtrubina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

static void	ft_send_singal(int pid, char *lin)
{
	int		bit;
	unsigned char	u;
	
	while (*lin)
	{
		bit = 8;
		u = *lin;
		while(bit--)
		{
			if ((u >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
		lin++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	ft_send_singal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
