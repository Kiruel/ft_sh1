/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:48:13 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/10 18:04:29 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_fill_in_env(char **ev, t_env *e)
{
	int i;
	int j;
	int k;
	char *tmp;
	char *str;
	char *tmp2;

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
	tmp2 = ft_find_env("HOME", e);
	e->home = (char*)ft_memalloc(sizeof(char) * ft_strlen(tmp2));
	k = 0;
	while (tmp2[k])
	{
		e->home[k] = tmp2[k];
		k++;
	}
	tmp = (char*)ft_memalloc(sizeof(char) * ft_strlen(e->new_env[3]) + 13);
	j = -1;
	str = "/Volumes/Data";
	while (str[++j])
		tmp[j] = str[j];
	i = -1;
	while (tmp2[++i])
		tmp[j] =tmp2[i], j++;
	i = 5;
	j = 0;
	while (tmp[j])
	{
		e->new_env[3][i] = tmp[j];
		j++;
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
		if (i == 3)
			e->new_env[i] = (char*)ft_memalloc(sizeof(char) * 256);
		else
			e->new_env[i] = (char*)ft_memalloc(sizeof(char) * j);
		i++;
	}
	ft_fill_in_env(ev, e);
}
