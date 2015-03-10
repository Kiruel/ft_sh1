#include "ft_sh1.h"

void	ft_error_access(char *dir)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void 	ft_error_dir(char *dir)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_error_comm(char *input)
{
	ft_putstr_fd(input, 2);
	ft_putendl_fd(": command not find.", 2);
}

void	ft_error_args(int ac)
{
	if (ac > 1)
	{
		ft_putendl_fd("Error: To many arguments.", 2);
		exit (0);
	}
}
