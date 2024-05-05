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

static void	manda(int pid, unsigned char *sq)
{
	unsigned char	u;

	u = 128;
	while (u > 0)
	{
		if (octet & u)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		u >>= 1;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	manda(argv[2], pid);
	return (0);
}
