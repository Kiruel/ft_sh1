/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/04/29 16:19:42 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>
#include <signal.h>

void	ft_put_prompt(t_env *e)
{
	char *tmp;

	ft_putstr("\033[0m\033[32m");
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
	ft_putstr("]\033[0m\033\033[0m\033[31m~> \033[0m");
}

void		sighandler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr("\n");
	} else if (signum == SIGQUIT) {
		ft_putstr("\n");
		kill(getpid(), signum);
	}
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
	signal(SIGINT, sighandler);
	while (42)
	{
		signal(SIGQUIT, sighandler);
		bin = NULL;
		ft_put_prompt(&e);
		if (get_next_line(1, &e.input) == -1)
			exit(1);
		ft_remplac_tab(e.input);
		e.arg = ft_strsplit(e.input, ' ');
		if (!e.arg[0] || ft_strcmp(e.arg[0], ".") == 0);
		else if (ft_builtings(e.arg, &e) == -1);
		else if ((bin = ft_find_bin(e.arg[0], &e)) == NULL)
			ft_error_comm(e.input);
		else
		{
			if (ft_strcmp(bin, "/usr/bin/cd") != 0)
				ft_exe(bin, e.arg, &e);
		}
		if (bin)
			free(bin);
		if (e.arg[0])
			ft_free(&e);
		if (e.input)
			free(e.input);
	}
	return (0);
}

