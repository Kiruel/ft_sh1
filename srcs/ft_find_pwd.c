/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 10:53:04 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/12 14:20:23 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char *ft_find_pwd(char **ev)
{
	int i;
	char *buf;

	i = 0;
	(void)ev;
	buf = (char*)ft_memalloc(sizeof(char) * 256);
	while (ev[i])
	{
		if (ft_strlcat(ev[i], "PWD", 4))
		{
			getcwd(buf, 256);
			return (buf);
		}
		i++;
	}
	return ("/");
}
