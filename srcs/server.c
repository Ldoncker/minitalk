/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:57:52 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/13 11:19:18 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	signal_handler(int signal, siginfo_t *siginfo, void	*unused)
{
	static char		bit = 64;
	static char		c = 0;

	(void)unused;
	(void)siginfo;
	if (signal == SIGUSR2)
		c += bit;
	bit /= 2;
	if (bit == 0)
	{
		ft_putchar(c);
		bit = 64;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	catch;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = signal_handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
	{
		error("Error on signal");
	}	
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
	{
		error("Error on signal");
	}
	while (1)
		pause();
	return (0);
}
