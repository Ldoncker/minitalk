/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:42:05 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/08 11:53:53 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space_minus(const char *str, int *minus)
{
	int		x;
	long	nb;

	x = 0;
	*minus = 1;
	nb = 0;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
		|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			*minus = *minus * (-1);
		x++;
	}
	return (x);
}

int	ft_atoi(const char *str)
{
	int		x;
	long	nb;
	int		minus;

	if (!str)
		return (0);
	nb = 0;
	x = ft_space_minus(str, &minus);
	while (str[x] >= '0' && str[x] <= '9')
	{
		if ((nb * 10) + str[x] - 48 >= nb)
			nb = (nb * 10) + str[x] - 48;
		else
		{
			if (minus == -1)
				return (0);
			else
				return (-1);
		}
		x++;
	}
	if (str[x] == ('-' | '+'))
		return (0);
	else
		return (nb * minus);
}
