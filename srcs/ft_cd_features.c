/* ************************************************************************** */
/*																																						*/
/*																												:::			 ::::::::		*/
/*	 ft_cd_features.c																		:+:			 :+:		:+:		*/
/*																										+:+ +:+					+:+			*/
/*	 By: etheodor <etheodor@student.42.fr>					+#+  +:+			 +#+				*/
/*																								+#+#+#+#+#+		+#+						*/
/*	 Created: 2015/04/30 11:16:08 by etheodor					 #+#		#+#							*/
/*	 Updated: 2015/04/30 11:17:34 by etheodor					###		########.fr				*/
/*																																						*/
/* ************************************************************************** */

#include "ft_sh1.h"

char *ft_go_to_home(t_env *e, char *path)
{
	 if (ft_find_env("HOME", e))
			path = ft_strdup(ft_find_env("HOME", e));
	 else
			path = ft_strdup("/");
	 return (path);
}

char *ft_go_to_back(t_env *e, char *path)
{
	 path = ft_find_env("PWD", e);
	 if (ft_strcmp(path, "") == 0)
			return ("");
	 int i;
	 int j;

	 j = 0;
	 i = 0;
	 while (path[i] != '\0')
	 {
	 		if (path[i] == '/')
				j++;
			i++;
	 }
	 if (j == 1)
	 		path = ft_strdup("/");
	 else
	   *(ft_strrchr(path, '/')) = 0;
	 return (path);
}

int ft_error_cd(char **arg)
{
	 struct stat stat;

	 if (lstat(arg[1], &stat) == -1)
			ft_error_dir(arg[1]);
	 else if (access(arg[1] , R_OK) == -1)
			ft_error_access(arg[1]);
	 return (-1);
}

char *ft_use_option_p(t_env *e, char **arg, char *tmp, char *path)
{
	 tmp = ft_strjoin(ft_find_env("PWD", e), "/");
	 path = ft_strjoin(tmp, arg[2]);
	 free(tmp);
	 chdir(path);
	 free(path);
	 path = getcwd(NULL, 0);
	 return (path);
}

int ft_go_to_path(t_env *e, char **arg, char *tmp, char *path)
{
	 struct stat stat;

	 tmp = ft_strjoin(ft_find_env("PWD", e), "/");
	 path = ft_strjoin(tmp, arg[1]);
	 free(tmp);
	 if (lstat(arg[1], &stat) == -1)
	 {
			ft_error_dir(arg[1]);
			free(path);
			return (-1);
	 }
	 else if (access(arg[1] , R_OK) == -1)
	 {
			ft_error_access(arg[1]);
			free(path);
			return (-1);
	 }
	 ft_maj_pwd(e, path, arg);
	 return(0);
}
