#include "./includes/ft_sh1.h"

int	main(int ac, char **av, char **ev)
{
	char	**arg;
	char	*input;
	pid_t	work;

	if(fork() == 0) 
	{
		execve("/usr/bin/clear", av, ev);
		exit(1);
	} 
	else
		wait(NULL);
	while (42)
	{
		ft_putstr("$> ");
		work = fork();
		if (work > 0)
			wait(NULL);
		if (work == 0)
		{
			get_next_line(1, &input);
			arg = ft_strsplit(input, ' ');
			if (ft_strequ(arg[0], "exit"))
				kill(work, SIGKILL);
			input = ft_strjoin("/bin/", arg[0]);
			execve(input, arg, NULL);
		}
	}
	return (0);
}
