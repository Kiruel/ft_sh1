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
	char **path;
}				t_env;

void	ft_recup_env(char **ev, t_env *e);

/*
** ft_tools
**
*/
void 	ft_exe(char *input, char **arg, t_env *e);
void	ft_get_bin(t_env *e);
char 	*ft_find_bin(char *input, t_env *e);
void 	ft_remplac_tab(char *input);

/*
** ft_builtings
**
*/
int ft_cd(char **arg, t_env *e);
int	ft_builtings(char **arg, t_env *e);

/*
** ft_error
**
*/
void 	ft_error_dir(char *dir);
void	ft_error_args(int ac);
void	ft_error_comm(char *input);

#endif
