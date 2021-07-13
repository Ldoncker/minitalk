/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:11:44 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/09 11:17:40 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		x;
	char	*target;

	x = 0;
	target = malloc(sizeof(char) * (n + 1));
	if (!target)
		return (NULL);
	while (x < n)
	{
		target[x] = s1[x];
		x++;
	}
	target[x] = '\0';
	return (target);
}
