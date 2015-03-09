#include "ft_sh1.h"

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
		if (arg[1] == NULL && ft_find_env("HOME", e) != NULL)
			chdir(ft_find_env("HOME", e));
		if (ft_strcmp(arg[1], "/") == 0)
			chdir("/");
		if (arg[1] != NULL)
		{
			buf = ft_strjoin("./", arg[1]);
			chdir(buf);
		}
		return (-1);
	}
	return (0);
}