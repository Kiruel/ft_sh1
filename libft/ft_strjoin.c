#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(str) * (ft_strlen(s2) + len + 1));
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - len] != 0)
	{
		str[i] = s2[i - len];
		i++;
	}
	str[i] = 0;
	return (str);
}
