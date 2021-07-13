/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:57:09 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/09 11:12:29 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str1;
	unsigned const char	*str2;

	if (!n || !dst || !src)
		return (0);
	str1 = dst;
	str2 = src;
	while (n-- != 0)
	{
		*str1++ = *str2++;
		if (*str1 == (unsigned char)c)
			return (str1);
	}
	return (0);
}
