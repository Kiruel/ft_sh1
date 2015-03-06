#include "ft_sh1.h"

void	ft_error_args(int ac)
{
	if (ac > 1)
	{
		ft_putendl_fd("Error: To many arguments.", 2);
		exit (0);
	}
}
