#include "./includes/ft_sh1.h"

void	ft_exit(char **arg, pid_t work)
{
	if (ft_strequ(arg[0], "exit"))
		kill(work, SIGKILL);	
}

void	ft_command_not_found(int ret, char **arg)
{
	if (ret == -1 && !ft_strequ(arg[0], "\n") && !ft_strequ(arg[0], NULL) &&
		!ft_strequ(arg[0], "clear") && !ft_strequ(arg[0], "cd"))
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

void	ft_cd(char **arg)
{
	char *buf;
	char *ret;
	int i;
	int j;

	i = 0;
	j = 0;
	buf = (char*)ft_memalloc(sizeof(char) * 256);
	buf = getcwd(buf, 256);
	while (buf[i])
		i++;
	while (i > j && buf[i] != '/')
		i--;
	i++;
	ret = (char*)ft_memalloc(sizeof(char) * i + 1);
	while (j < i)
	{
		ret[j] = buf[j];
		j++;
	}
	ft_putstr(ret);
	if (ft_strequ(arg[1], ".."))
	{
		chdir(ret);
	}
/*	if(fork() == 0) 
	{
		execve("/usr/bin/cd", av, ev);
		exit(1);
	} 
	else
		wait(NULL);*/
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
		}
	}
	return (0);
}
