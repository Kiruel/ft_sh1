#include "ft_sh1.h"

char *ft_find_pwd(char **ev)
{
	int i;
	char *buf;

	i = 0;
	buf = (char*)ft_memalloc(sizeof(char) * 256);
	while (ev[i])
	{
		if (ft_strlcat(ev[i], "PWD", 4))
		{
			getcwd(buf, 256);
			return (buf);
		}
		i++;
	}
	return ("/");
}
