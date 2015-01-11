#ifndef FT_SH1
# define FT_SH1
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>

int		get_next_line(int const fd, char **line);
char 	*ft_find_pwd(char **ev);

#endif
