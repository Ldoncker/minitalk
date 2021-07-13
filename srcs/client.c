/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:56:11 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/13 11:35:23 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	sendit(pid_t pid, char c)
{
	int		bit;

	bit = 64;
	while (bit != 0)
	{
		if (c >= bit)
		{
			c -= bit;
			if (kill(pid, SIGUSR2) == -1)
				error("Failed sending");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Failed sending");
		}
		bit /= 2;
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		error("Wrong number of arguments");
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		sendit(pid, argv[2][i]);
		i++;
	}
	sendit(pid, '\n');
	return (0);
}
