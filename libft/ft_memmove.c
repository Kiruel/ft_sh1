/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:53:02 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/13 16:34:49 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*temp_dest;
	char	*temp_src;

	i = 0;
	temp = (char *)malloc(sizeof(temp) * (int)n);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (i < (int)n)
	{
		temp[i] = temp_src[i];
		i++;
	}
	i = 0;
	while (i < (int)n)
	{
		temp_dest[i] = temp[i];
		i++;
	}
	dest = (void *)temp_dest;
	free(temp);
	return (dest);
}
