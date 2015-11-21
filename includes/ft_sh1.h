/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:00:35 by etheodor          #+#    #+#             */
/*   Updated: 2015/04/30 11:19:54 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1
# define FT_SH1
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>
#include <errno.h>

typedef struct 	s_env
{
	char **new_env;
	char *home;
	char **path;
	char **arg;
	char *old_pwd;
	char *input;
	char *setenv;
}				t_env;

void	ft_free(t_env *e);
void	ft_recup_env(char **ev, t_env *e);

/*
** ft_tools
**
*/
char 	*ft_find_env(char *str, t_env *e);
void 	ft_exe(char *input, char **arg, t_env *e);
void	ft_get_bin(t_env *e);
char 	*ft_find_bin(char *input, t_env *e);
void 	ft_remplac_tab(char *input);

/*
** ft_builtings
**
*/
int 	ft_cd(char **arg, t_env *e);
int 	ft_go_to_path(t_env *e, char **arg, char *tmp, char *path);
char 	*ft_use_option_p(t_env *e, char **arg, char *tmp, char *path);
int 	ft_error_cd(char **arg);
char 	*ft_go_to_back(t_env *e, char *path);
char 	*ft_go_to_home(t_env *e, char *path);
int	ft_maj_pwd(t_env *e, char *new_path, char **arg);
int	ft_builtings(char **arg, t_env *e);
int	ft_setenv(char **arg, t_env *e);

/*
** ft_error
**
*/
void	ft_error_env();
void	ft_error_access(char *dir);
void 	ft_error_dir(char *dir);
void	ft_error_args(int ac);
void	ft_error_comm(char *input);

/*
** ft_signals
**
*/
void 	sh1_set_signals_hook(void);
void	sh1_hkd_sigint(int sign);
void	sh1_hkd_sigtstp(int sign);

/*
** env
**
*/
int	ft_env(char **arg, t_env *e);
int	ft_unsetenv(char **arg, t_env *e);
void ft_print_env(t_env *e);

#endif
