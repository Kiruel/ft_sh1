/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:08:23 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/13 14:31:24 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_free(t_env *e)
{
	int i;

	i = 0;
	while (e->arg[i])
	{
		free(e->arg[i]);
		i++;
	}
	free(e->arg);
}

void 	ft_remplac_tab(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\t')
			input[i] = ' ';
		i++;
	}
}

char 	*ft_find_bin(char *input, t_env *e)
{
	struct stat stat;
	int i;
	char *tmp_path;
	char *tmp;

	if (lstat(input, &stat) == 0)
		return (input);
	tmp_path = NULL;
	tmp = NULL;
 	i = 0;
	while (e->path[i])
	{
		tmp = ft_strjoin(e->path[i], "/");
		tmp_path = ft_strjoin(tmp, input);
		if (lstat(tmp_path, &stat) == 0)
		{
			free(tmp);
			return (tmp_path);
		}
		i++;
	}
	return (NULL);
}

void	ft_get_bin(t_env *e)
{
	int i;

	i = 0;
	while (e->new_env[i])
	{
		if (ft_strnstr(e->new_env[i], "PATH=", 5))
		{
			e->path = ft_strsplit(&e->new_env[i][5], ':');
			break ;
		}
		i++;
	}
}

void 	ft_exe(char *input, char **arg, t_env *e)
{
	if(fork() == 0)
	{
		if (execve(input, arg, e->new_env) == -1)
			ft_putendl_fd("Invalid command.", 2);
		exit(1);
	} 
	else
		wait(NULL);
}
