/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:06:43 by etheodor          #+#    #+#             */
/*   Updated: 2015/01/04 16:06:44 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t p;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	p = 0;
	if (size <= i)
		return (j + size);
	while ((i + p) < size - 1)
	{
		dst[i + p] = src[p];
		p++;
	}
	dst[i + p] = 0;
	return (i + j);
}
