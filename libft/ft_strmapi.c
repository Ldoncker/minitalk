/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:05:35 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/09 11:16:41 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*mem;

	if (s == NULL || f == NULL)
		return (NULL);
	mem = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mem == NULL)
		return (NULL);
	x = -1;
	while (++x < ft_strlen(s))
		mem[x] = (*f)((unsigned int)x, s[x]);
	mem[x] = '\0';
	return (mem);
}
