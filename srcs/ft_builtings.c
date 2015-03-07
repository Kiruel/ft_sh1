/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 13:41:54 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/07 14:15:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

/*static int ft_cd(char *input)
{
	char *buf;

	buf = ft_strjoin("./", arg[1]);
	if (arg[1][0] != '.')
		chdir(buf);
	else
		chdir(arg[1]);	
}*/

static int ft_exit(char **arg)
{
	if (ft_strcmp(arg[0], "exit") == 0)
		exit (ft_atoi(arg[1]));
	return (0);
}

int	ft_builtings(char **arg)
{
	// if (ft_cd(input, arg) == -1)
	// 	return (-1);
	if (ft_exit(arg) == -1)
		return (-1);
	return (0);
}
