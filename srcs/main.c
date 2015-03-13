/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/13 16:05:06 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

void	ft_put_prompt(t_env *e)
{
	char *tmp;

	ft_putstr("\033[34m{\033[0m\033[32m");
	ft_putstr(ft_find_env("USER", e));
	ft_putstr("\033[0m \033[36m[");
	if (ft_strncmp(ft_find_env("PWD", e), ft_find_env("HOME", e),
		ft_strlen(ft_find_env("HOME", e))) == 0 || ft_strncmp(ft_find_env("PWD", e), e->home,
		ft_strlen(e->home)) == 0)
	{
		ft_putstr("~");
		tmp = ft_find_env("PWD", e);
		if (ft_strncmp(ft_find_env("PWD", e), e->home,
		ft_strlen(e->home)) == 0)
			ft_putstr(&tmp[ft_strlen(e->home)]);
		else
			ft_putstr(&tmp[ft_strlen(ft_find_env("HOME", e))]);
	}
	else
		ft_putstr(ft_find_env("PWD", e));
	ft_putstr("]\033[0m\033[34m}\033[0m\033[31m~> \033[0m");
}

int		main(int ac, char **av, char **ev)
{
	char	**arg;
	// char 	*bin;
	t_env	e;
	int i;

	i = 0;
	(void)av;
	ft_error_args(ac);
	ft_recup_env(ev, &e);
	while (42)
	{
		ft_get_bin(&e);
		ft_put_prompt(&e);
		get_next_line(1, &e.input);
		ft_remplac_tab(e.input);
		arg = ft_strsplit(e.input, ' ');
		if (!arg[0])
		{
			ft_free(&e);
			i = 0;
			while (arg[i])
				free(arg[i++]);
			free(arg);
			continue ;
		}
		i = 0;
		while (arg[i])
			free(arg[i++]);
		free(arg);
/*		if (ft_builtings(arg, &e) == -1)
		{
			ft_free(&e);
			i = 0;
			while (arg[i])
				free(arg[i++]);
			free(arg[i]);
			continue ;
		}
		bin = ft_find_bin(arg[0], &e);
		if (bin == NULL)
		{
			ft_error_comm(e.input);
			free(bin);
			i = 0;
			while (arg[i])
				free(arg[i++]);
			free(arg[i]);
			ft_free(&e);
			continue ;
		}
		else
		{
			ft_exe(bin, arg, &e);
			i = 0;
			while (arg[i])
				free(arg[i++]);
			free(arg[i]);
			free(bin);
		}*/
		ft_free(&e);
	}
	return (0);
}
