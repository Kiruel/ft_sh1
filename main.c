#include "./includes/ft_sh1.h"

void	ft_exe_cmd(char *cmd, char **av, char** ev)
{
	if (ft_strequ(cmd, "exit"))
		exit(1);
	if (ft_strequ(cmd, "ls"))
		execve("/bin/ls", av, ev);
}

int 	main(int ac, char **av, char **ev)
{
	pid_t	father;
	char *line;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		while (42)
		{
			ft_putstr("$> ");
			if (get_next_line(1, &line) == -1)
				exit(1);
			ft_exe_cmd(line, av, ev);
		}
	}
	return (0);
}
