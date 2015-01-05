#include "./includes/ft_sh1.h"

void	ft_exit(char **arg, pid_t work)
{
	if (ft_strequ(arg[0], "exit"))
		kill(work, SIGKILL);	
}

void	ft_command_not_found(int ret, char **arg)
{
	if (ret == -1 && !ft_strequ(arg[0], "\n") && !ft_strequ(arg[0], NULL) &&
		!ft_strequ(arg[0], "clear") && !ft_strequ(arg[0], "cd") &&
		!ft_strequ(arg[0], "setenv") && !ft_strequ(arg[0], "printenv"))
	{
		ft_putstr_fd(arg[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
}

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

void	ft_setenv(char **av, char **ev)
{
	if(fork() == 0) 
	{
		execve("/usr/bin/setenv", av, ev);
		exit(1);
	} 
	else
		wait(NULL);
}

void	ft_printenv(char **av, char **ev)
{
	if(fork() == 0) 
	{
		execve("/usr/bin/printenv", av, ev);
		exit(1);
	} 
	else
		wait(NULL);
}

void	ft_cd(char **arg)
{
	char *buf;

	buf = ft_strjoin("./", arg[1]);
	if (arg[1][0] != '.')
		chdir(buf);
	else
		chdir(arg[1]);
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
			ft_exit(arg, work);
			input = ft_strjoin("/bin/", arg[0]);
			ft_command_not_found(execve(input, arg, ev), arg);
			if (ft_strequ(arg[0], "clear"))
				ft_clear(av, ev);
			if (ft_strequ(arg[0], "cd"))
				ft_cd(arg);
			if (ft_strequ(arg[0], "setenv"))
				ft_setenv(arg, ev);
			if (ft_strequ(arg[0], "printenv"))
				ft_printenv(arg, ev);			
		}
	}
	return (0);
}
