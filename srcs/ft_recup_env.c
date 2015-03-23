/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:48:13 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/23 16:56:17 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char 	*ft_find_env(char *str, t_env *e)
{
	int i;

	i = 0;
	while (ft_strncmp(e->new_env[i], str, ft_strlen(str)) != 0)
		i++;
	return (&e->new_env[i][ft_strlen(str) + 1]);
}

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
