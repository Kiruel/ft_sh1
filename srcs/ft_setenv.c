#include "ft_sh1.h"

char	**ft_array_cpy(t_env *e)
{
	char **new_env = NULL;

	(void)e;
	new_env = (char **)ft_memalloc(sizeof(char*) * 2);
	new_env[0] = (char*)ft_memalloc(sizeof(char) * 2);
	new_env[1] = (char*)ft_memalloc(sizeof(char) * 1);
	new_env[0][0] = 'q';
	new_env[0][1] = '\0';
	new_env[1][0] = '\0';
	new_env[1] = "\0";
	return (new_env);
}

int	ft_setenv(char **arg, t_env *e)
{
	//char **new_env = NULL;

	(void)e;
	if (ft_strcmp(arg[0], "setenv") == 0 && arg[1] != 0)
	{
		//new_env = ft_array_cpy(e);
		//ft_putstr(new_env[0]);
		return (-1);
	}
	else
	{
		ft_putstr("setenv: Please use [setenv var=...] to set a variable to this environment.\n");
		return (-1);
	}
	return (0);
}
