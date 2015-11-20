#include "ft_sh1.h"


void ft_print_env(t_env *e)
{
	int i;

	i = 0;
	while (e->new_env[i])
	{
		ft_putstr(e->new_env[i]);
		ft_putstr("\n");
		i++;
	}
	if (e->setenv != NULL)
	{
		ft_putstr(e->setenv);
		ft_putstr("\n");
	}
}

int	ft_env(char **arg, t_env *e)
{

	(void)e;
	if (ft_strcmp(arg[0], "env") == 0)
	{
		ft_print_env(e);
		return (-1);
	}
	return (0);
}