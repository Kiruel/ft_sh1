#include "ft_sh1.h"

void	ft_maj_pwd(t_env *e)
{
	char *buf;
	char *tmp;
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	buf = NULL;
	buf = getcwd(buf, 1024);
	while (ft_strncmp(e->new_env[i], "PWD", 3) != 0)
		i++;
	ft_bzero(e->new_env[i], ft_strlen(e->new_env[i]));
	tmp = "PWD";
	while (tmp[j])
	{
		e->new_env[i][j] = tmp[j];
		j++;
	}
	e->new_env[i][j] = '=';
	j++;
	while (buf[k])
	{
		e->new_env[i][j] = buf[k];
		k++;
		j++;
	}	
/*	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	while (ft_strncmp(e->new_env[i], str, ft_strlen(str)) != 0)
		i++;
	j = 0;
	ft_bzero(e->new_env[i], ft_strlen(e->new_env[i]));
	while (str[j])
	{
		e->new_env[i][j] = str[j];
		j++;
	}
	e->new_env[i][j] = '=';
	j++;
	while (path[k])
	{
		e->new_env[i][j] = path[k];
		k++;
		j++;
	}*/
}

char 	*ft_find_env(char *str, t_env *e)
{
	int i;

	i = 0;
	while (ft_strncmp(e->new_env[i], str, ft_strlen(str)) != 0)
		i++;
	return (&e->new_env[i][ft_strlen(str) + 1]);
}

int 	ft_cd(char **arg, t_env *e)
{
	char *buf;

	buf = NULL;
	if (ft_strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL && ft_find_env("HOME", e) == NULL)
			ft_putendl_fd("cd: No home on env.", 2);
		else if (arg[1] == NULL && ft_find_env("HOME", e) != NULL)
			chdir(ft_find_env("HOME", e));
		else if (ft_strcmp(arg[1], "/") == 0)
			chdir("/");
		else if (ft_strcmp(arg[1], "~") == 0)
			chdir(ft_find_env("HOME", e));
		else if (arg[1] != NULL)
		{

			if (chdir(arg[1]) == -1)
			{
				if (errno == ENOENT)
					ft_putendl_fd("No dir.", 2);
			}
		}
		ft_maj_pwd(e);
		return (-1);
	}
	return (0);
}