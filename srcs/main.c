/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/24 13:04:51 by etheodor         ###   ########.fr       */
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
	if (ft_strncmp(ft_find_env("PWD", e), ft_find_env("HOME", e), ft_strlen(ft_find_env("HOME", e))) == 0
		|| ft_strncmp(ft_find_env("PWD", e), e->home, ft_strlen(e->home)) == 0)
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
	char 	*bin;
	t_env	e;

	if (ev == NULL || ev[0] == NULL)
	{
		ft_error_env();
		return (0);
	}
	(void)av;	
	ft_error_args(ac);
	ft_recup_env(ev, &e);
	ft_get_bin(&e);
	e.input = NULL;
	e.arg = NULL;
	while (42)
	{
		bin = NULL;
		ft_put_prompt(&e);
		get_next_line(1, &e.input);
		ft_remplac_tab(e.input);
		e.arg = ft_strsplit(e.input, ' ');
		if (!e.arg[0] || ft_strcmp(e.arg[0], ".") == 0);
		else if (ft_builtings(e.arg, &e) == -1);
		else if ((bin = ft_find_bin(e.arg[0], &e)) == NULL)
			ft_error_comm(e.input);
		else
			ft_exe(bin, e.arg, &e);
		if (bin)
			free(bin);
		ft_free(&e);
		free(e.input);
	}
	return (0);
}
