#include "ft_sh1.h"

int		ft_parse_arg2(char *str)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '\"')
			res = 1;
		i++;
	}
	if (str[i - 1] == '\"')
		res = 1;
	else
		res = 0;
	return res;
}

int 	ft_parse_args(char **str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	if (str[0] && str[1] && str[2] && ft_parse_arg2(str[2]) == 1)
		res = 1;
	else
		return (0);
	while (str[1][i])
	{
		if ((str[1][i] >= 'A' && str[1][i] <= 'Z') || str[1][i] == '_')
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}

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
	char **new_env = NULL;

	(void)e;
	if (ft_parse_args(arg) == 0 && ft_strcmp(arg[0], "setenv") == 0)
	{
		ft_putstr("Error: setenv VARIABLE_NAME \"some value\"\n");
		return (-1);
	}
	if (ft_strcmp(arg[0], "setenv") == 0)
	{
		// SET VARIABLE TO ENV HERE.
		new_env = ft_array_cpy(e);
		ft_putstr(new_env[0]);
		return (-1);
	}
	return (0);
}
