#include "./includes/ft_sh1.h"
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait (0);
		execve("/bin/pwd", argv, envp);
	}
	if (father == 0)
	{
		execve("/bin/ls", argv, envp);
	}
	return 0;
}
