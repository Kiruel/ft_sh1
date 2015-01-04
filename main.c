#include "./includes/ft_sh1.h"

void	ft_clear(char **av, char **ev)
{
	if(fork() == 0) 
	{
		execve("/usr/bin/clear", av, ev);
		exit(1);
	} 
	else
		wait(NULL);
}

int	main(int ac, char **av, char **ev)
{
	char	**arg;
	char	*input;
	pid_t	work;
	char 	*buf;
	int 	ret;
	
	ft_clear(av, ev);
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
			ret = execve(input, arg, NULL);
			if (ft_strequ(arg[0], "clear"))
				ft_clear(av, ev);
			if (ret == -1 && !ft_strequ(arg[0], "\n") && !ft_strequ(arg[0], NULL))
			{
				ft_putstr("-bash: ");
				ft_putstr(arg[0]);
				ft_putendl(": command not found");
			}
		}
	}
	return (0);
}
