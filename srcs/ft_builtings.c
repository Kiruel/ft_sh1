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

static char *ft_get_home(t_env *e, char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	while (e->new_env[i])
	{
		if (ft_strnstr(e->new_env[i], "HOME=", 5))
		{
			j = 5;
			while (e->new_env[i][j])
				j++;
			buf = (char*)ft_memalloc(sizeof(char) * j + 1);
			j = 5;
			k = 0;
			while (e->new_env[i][j])
			{
				buf[k] = e->new_env[i][j];
				k++;
				j++;
			}
			return (buf);
			break ;
		}
		i++;
	}
	return (NULL);
}

static int ft_cd(char **arg, t_env *e)
{
	char *buf;

	buf = NULL;
	if ((arg[1] == NULL || ft_strcmp(arg[1], "~")) && ft_strcmp(arg[0], "cd") == 0)
	{
		buf = ft_get_home(e, buf);
		if (buf == NULL)
			return (0);
		else
			chdir(buf);
		return (-1);

	}
	if (ft_strcmp(arg[0], "cd") == 0)
	{
		buf = ft_strjoin("./", arg[1]);
		if (arg[1][0] != '.')
		{
			if (chdir(buf) == -1)
				ft_error_dir(arg[1]);
		}
		else
			chdir(arg[1]);
		return (-1);		
	}
	return (0);
}

static int ft_exit(char **arg)
{
	if (ft_strcmp(arg[0], "exit") == 0 && arg[1] != 0)
		exit (ft_atoi(arg[1]));
	else if (ft_strcmp(arg[0], "exit") == 0)
		exit (0);
	return (0);
}

int	ft_builtings(char **arg, t_env *e)
{
	if (ft_cd(arg, e) == -1)
		return (-1);
	if (ft_exit(arg) == -1)
		return (-1);
	return (0);
}
