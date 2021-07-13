/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoncker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:06:15 by ldoncker          #+#    #+#             */
/*   Updated: 2021/07/12 15:06:16 by ldoncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include "../libft/libft.h"

typedef struct	s_sig
{
	int		size;
	int		pid;
	char	c;
}			t_sig;

void	error(char *str);

#endif
