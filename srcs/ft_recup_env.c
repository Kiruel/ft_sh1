/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:48:13 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/10 17:29:05 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_fill_in_env(char **ev, t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ev[i])
	{
		j = 0;
		while (ev[i][j])
		{
			e->new_env[i][j] = ev[i][j];
			j++;
		}
		i++;
	}
}

void	ft_recup_env(char **ev, t_env *e)
{
	int i;
	int j;

	i = 0;
	while (ev[i])
		i++;
	e->new_env = (char**)ft_memalloc(sizeof(char*) * i + 1);
	i = 0;
	j = 0;
	while (ev[i])
	{
		j = 0;
		while (ev[i][j++]);
		e->new_env[i] = (char*)ft_memalloc(sizeof(char) * j);
		i++;
	}
	ft_fill_in_env(ev, e);
}
