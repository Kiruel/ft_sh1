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

int	ft_setenv(char **arg, t_env *e)
{
	int i;
	int j;

	(void)e;
	if (ft_parse_args(arg) == 0 && ft_strcmp(arg[0], "setenv") == 0)
	{
		ft_putstr("Error: setenv VARIABLE_NAME \"some value\"\n");
		return (-1);
	}
	if (ft_strcmp(arg[0], "setenv") == 0)
	{
		e->setenv = (char*)ft_memalloc(sizeof(char) * ft_strlen(arg[1]) + ft_strlen(arg[2]) + 2);
		i = 0;
		while (arg[1][i])
		{
			e->setenv[i] = arg[1][i];
			i++;
		}
		e->setenv[i] = '=';
		i++;
		j = 0;
		while (arg[2][j])
		{
			if (arg[2][j] != '\"')
			{
				e->setenv[i] = arg[2][j];
				i++;
			}
			j++;
		}
		e->setenv[i] = 0;
		return (-1);
	}
	return (0);
}
