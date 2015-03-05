#ifndef FT_SH1
# define FT_SH1
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>

typedef struct 	s_env
{
	char **env;
}				t_env;

int		get_next_line(int const fd, char **line);
char 	*ft_find_pwd(char **ev);

/*
** ft_error
**
*/
void	ft_error_args(int ac);

#endif
