/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 13:41:54 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/07 14:23:54 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
static	void	ft_free_exit(t_env *e)
{
	int i;

	i = 0;
	while (e->new_env[i])
		free(e->new_env[i++]);
	free(e->new_env);
	i = 0;
	while (e->path[i])
	{
		free(e->path[i]);
		i++;
	}
	free(e->path);
	free(e->input);
}

static int ft_exit(char **arg, t_env *e)
{
	int i;

	i = 0;
	if (ft_strcmp(arg[0], "exit") == 0 && arg[1] != 0)
	{
		ft_free_exit(e);
		exit (ft_atoi(arg[1]));
	}
	else if (ft_strcmp(arg[0], "exit") == 0)
	{
		ft_free_exit(e);
		exit (0);
	}
	return (0);
}

int	ft_builtings(char **arg, t_env *e)
{
	if (ft_cd(arg, e) == -1)
		return (-1);
	else if (ft_exit(arg, e) == -1)
		return (-1);
	//else if (ft_setenv(arg, e) == -1)
	//	return (-1);
	return (0);
}
