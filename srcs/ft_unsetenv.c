#include "ft_sh1.h"

int	ft_unsetenv(char **arg, t_env *e)
{
	if (arg[1] == NULL && ft_strcmp(arg[0], "unsetenv") == 0)
	{
		ft_putstr("Error: setenv VARIABLE_NAME \"some value\"\n");
		return (-1);
	}
	if (ft_strcmp(arg[0], "unsetenv") == 0)
	{
		e->setenv = NULL;
		free(e->setenv);
		return (-1);
	}
	return (0);
}