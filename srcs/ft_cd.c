/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:00:35 by etheodor          #+#    #+#             */
/*   Updated: 2015/04/30 11:17:32 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_maj_pwd(t_env *e, char *new_path, char **arg)
{
	char *buf;
	int i;
	int j;

	j = -1;
	i = -1;
	while (ft_strncmp(e->new_env[++j], "OLDPWD=", 7) != 0);
	free(e->new_env[j]);
	buf = ft_strjoin("OLDPWD=", ft_find_env("PWD", e));
	e->new_env[j] = buf;
	while (ft_strncmp(e->new_env[++i], "PWD=", 4) != 0);
	free(e->new_env[i]);
	buf = ft_strjoin("PWD=", new_path);
	e->new_env[i] = buf;
	chdir(new_path);
	if ((arg[1] && ft_strcmp(arg[1], "..") != 0) || (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0))
		free(new_path);
}

int 	ft_features_cd(t_env *e, char **arg)
{
	char *path;
	char *tmp;

	tmp = NULL;
	path = NULL;
	if (arg[1] == NULL && ft_find_env("HOME", e) == NULL)
		ft_putendl_fd("cd: No home on env.", 2);
	else if (ft_strcmp(arg[1], "-") == 0)
		path = ft_strdup(ft_find_env("OLDPWD", e));
	else if (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0)
		path = ft_go_to_home(e, path);
	else if (ft_strcmp(arg[1], "/") == 0 || (arg[1][0] == '/' && arg[1][1] == '/'))
		path = ft_strdup("/");
	else if (ft_strcmp(arg[1], "..") == 0)
		path = ft_go_to_back(e, path);
	else if (ft_strcmp(arg[1], ".") == 0)
		return (-1);
	else if (!chdir(path) && arg[1] != NULL)
		return (ft_error_cd(arg));
	else if (ft_strcmp(arg[1], "-P") == 0)
		path = ft_use_option_p(e, arg, tmp, path);
	else
		return (ft_go_to_path(e, arg, tmp, path));
	ft_maj_pwd(e, path, arg);
	return (0);
}

int 	ft_cd(char **arg, t_env *e)
{
	char *buf;

	buf = NULL;
	if (ft_strcmp(arg[0], "cd") == 0)
	{
		if (ft_features_cd(e, arg) == -1)
			return (0);
		return (-1);
	}
	return (0);
}
