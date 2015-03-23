/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:00:35 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/23 17:55:59 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_maj_pwd(t_env *e, char *new_path)
{
	char *buf;
	int i;
	int j;
	int k;

	j = -1;
	i = -1;
	k = -1;
	while (ft_strncmp(e->new_env[++i], "PWD", 3) != 0);
	free(e->new_env[i]);
	buf = ft_strjoin("PWD=", new_path);
	e->new_env[i] = (char*)ft_memalloc(sizeof(char) * ft_strlen(buf) + 1);
	ft_strcpy(e->new_env[i], buf);
	free(buf);
}

void 	ft_features_cd(t_env *e, char **arg)
{
	struct stat stat;
	char *path;

	path = NULL;
	if (arg[1] == NULL && ft_find_env("HOME", e) == NULL)
		ft_putendl_fd("cd: No home on env.", 2);
	else if (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0)
	{
		if (ft_find_env("HOME", e))
			path = ft_strdup(ft_find_env("HOME", e));
		else
			path = ft_strdup("/");
	}
	else if (ft_strcmp(arg[1], "/") == 0)
		path = ft_strdup("/");
	else if (ft_strcmp(arg[1], "..") == 0)
	{
		path = ft_find_env("PWD", e);
		if (*(ft_strrchr(path, '/') - 1) == '=')
			path = ft_strdup("/");
		else
			*(ft_strrchr(path, '/')) = 0;
	}
	else
		ft_error_dir(arg[1]);
	if (!chdir(path) && arg[1] != NULL)
	{
		if (lstat(arg[1], &stat) == -1)
			ft_error_dir(arg[1]);
		else if (access(arg[1] , R_OK) == -1)
			ft_error_access(arg[1]);
	}
	ft_maj_pwd(e, path);
}

int 	ft_cd(char **arg, t_env *e)
{
	char *buf;

	buf = NULL;
	if (ft_strcmp(arg[0], "cd") == 0)
	{
		ft_features_cd(e, arg);
		return (-1);
	}
	return (0);
}