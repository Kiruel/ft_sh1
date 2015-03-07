/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/07 12:12:50 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		main(int ac, char **av, char **ev)
{
	char	**arg;
	char 	*bin;
	char	*input;
	t_env	e;

	(void)av;
	ft_error_args(ac);
	ft_recup_env(ev, &e);
	while (42)
	{
		ft_get_bin(&e);		
		ft_putstr("$> ");
		get_next_line(1, &input);

		arg = ft_strsplit(input, ' ');
		if (!arg[0])
			continue ;
		//check builtings
		bin = ft_find_bin(arg[0], &e);
		if (bin == NULL)
		{
			ft_error_comm(input);
			continue ;			
		}
		ft_exe(bin, arg, &e);
	}
	return (0);
}
