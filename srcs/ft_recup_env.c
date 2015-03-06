#include "ft_sh1.h"

void	ft_fill_in_env(char **ev, t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ev[i])
	{
		j = 0;
		while (ev[i][j])
		{
			e->new_env[i][j] = ev[i][j];
			j++;
		}
		i++;
	}
}

void	ft_recup_env(char **ev, t_env *e)
{
	int i;
	int j;

	i = 0;
	while (ev[i])
		i++;
	e->new_env = (char**)ft_memalloc(sizeof(char*) * i + 1);
	i = 0;
	j = 0;
	while (ev[i])
	{
		j = 0;
		while (ev[i][j++]);
		e->new_env[i] = (char*)ft_memalloc(sizeof(char) * j);
		i++;
	}
	ft_fill_in_env(ev, e);
}
