/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:00:35 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/24 10:36:09 by etheodor         ###   ########.fr       */
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
int ft_cd(char **arg, t_env *e);
int	ft_builtings(char **arg, t_env *e);

/*
** ft_error
**
*/
void	ft_error_env();
void	ft_error_access(char *dir);
void 	ft_error_dir(char *dir);
void	ft_error_args(int ac);
void	ft_error_comm(char *input);

#endif
