/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/07 14:08:19 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_put_prompt(t_env *e)
{
	char *tmp;

	ft_putstr("\033[34m{\033[0m\033[32m");
	ft_putstr(ft_find_env("USER", e));
	ft_putstr("\033[0m \033[36m[");
	if (ft_strncmp(ft_find_env("PWD", e), ft_find_env("HOME", e),
		ft_strlen(ft_find_env("HOME", e))) == 0)
	{
		ft_putstr("~");
		tmp = ft_find_env("PWD", e);
		ft_putstr(&tmp[ft_strlen(ft_find_env("HOME", e))]);
	}
	else
		ft_putstr(ft_find_env("PWD", e));
	ft_putstr("]\033[0m\033[34m}\033[0m\033[31m~> \033[0m");
}

int		main(int ac, char **av, char **ev)
{
	char	**arg;
	char 	*bin;
	char	*input; 
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
		get_next_line(1, &input);
		ft_remplac_tab(input);
		arg = ft_strsplit(input, ' ');
		if (!arg[0])
		{
			free(input);
			i = 0;
			while (e.path[i])
				free(e.path[i++]);
			free(e.path);
			free(arg);
			continue ;
		}
		if (ft_builtings(arg, &e) == -1)
		{
			free(input);
			i = 0;
			while (e.path[i])
				free(e.path[i++]);
			free(e.path);
			free(arg);
			continue ;
		}
		bin = ft_find_bin(arg[0], &e);
		if (bin == NULL)
		{
			ft_error_comm(input);
			i = 0;
			while (e.path[i])
				free(e.path[i++]);
			free(e.path);
			free(input);
			free(bin);
			free(arg);
			continue ;
		}
		else
			ft_exe(bin, arg, &e);
		free(arg);
		free(input);
		i = 0;
		while (e.path[i])
			free(e.path[i++]);
		free(e.path);
		free(bin);
	}
	return (0);
}
