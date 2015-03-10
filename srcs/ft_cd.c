#include "ft_sh1.h"

void	ft_maj_pwd(t_env *e)
{
	char *buf;
	char *tmp;
	int i;
	int j;
	int k;

	j = -1;
	i = -1;
	k = -1;
	buf = NULL;
	buf = getcwd(buf, 1024);
	while (ft_strncmp(e->new_env[++i], "PWD", 3) != 0);
	ft_bzero(e->new_env[i], ft_strlen(e->new_env[i]));
	tmp = "PWD";
	while (tmp[++j])
		e->new_env[i][j] = tmp[j];
	e->new_env[i][j] = '=';
	while (buf[++k])
		e->new_env[i][++j] = buf[k];
	free(buf);
}

char 	*ft_find_env(char *str, t_env *e)
{
	int i;

	i = 0;
	while (ft_strncmp(e->new_env[i], str, ft_strlen(str)) != 0)
		i++;
	return (&e->new_env[i][ft_strlen(str) + 1]);
}

void 	ft_features_cd(t_env *e, char **arg)
{
	struct stat stat;

	if (arg[1] == NULL && ft_find_env("HOME", e) == NULL)
		ft_putendl_fd("cd: No home on env.", 2);
	else if (arg[1] == NULL && ft_find_env("HOME", e) != NULL)
		chdir(ft_find_env("HOME", e));
	else if (ft_strcmp(arg[1], "/") == 0)
		chdir("/");
	else if (ft_strcmp(arg[1], "~") == 0)
		chdir(ft_find_env("HOME", e));
	else if (arg[1] != NULL)
		if (chdir(arg[1]) == -1)
		{
			if (lstat(arg[1], &stat) == -1)
				ft_error_dir(arg[1]);
			else if (access(arg[1] , R_OK) == -1)
				ft_error_access(arg[1]);
		}
}

int 	ft_cd(char **arg, t_env *e)
{
	char *buf;

	buf = NULL;
	if (ft_strcmp(arg[0], "cd") == 0)
	{
		ft_features_cd(e, arg);
		ft_maj_pwd(e);
		return (-1);
	}
	return (0);
}