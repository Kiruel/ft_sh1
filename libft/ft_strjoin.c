#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	s3 = (char*)malloc(sizeof(char) * ft_strlen((char*)s1) + \
ft_strlen((char*)s2) + 1);
	i = 0;
	j = 0;
	while (i < (int)ft_strlen((char*)s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s1) + (int)ft_strlen((char*)s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
