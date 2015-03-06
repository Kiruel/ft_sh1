#ifndef FT_SH1
# define FT_SH1
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>

typedef struct 	s_env
{
	char **new_env;
}				t_env;

void	ft_recup_env(char **ev, t_env *e);

/*
** ft_error
**
*/
void	ft_error_args(int ac);

#endif
