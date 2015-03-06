#include "ft_sh1.h"

int	main(int ac, char **av, char **ev)
{
	// char	**arg;
	// char	*input;
	t_env	e;

	(void)av;
	ft_error_args(ac);
	ft_recup_env(ev, &e);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(1, &input);
		arg = ft_strsplit(input, ' ');
		input = ft_strjoin("/bin/", arg[0]);
		ft_command_not_found(execve(input, arg, ev), arg);
	}
	return (0);
}
