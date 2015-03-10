/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:01:10 by etheodor          #+#    #+#             */
/*   Updated: 2014/11/19 15:18:04 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*gnl_join(char *s1, char *s2, char c)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	char	*chr;

	len_s1 = ft_strlen(s1);
	chr = NULL;
	if (ft_strchr(s2, c) == NULL)
		len_s2 = BUFF_SIZE;
	else
	{
		chr = ft_strchr(s2, c);
		len_s2 = (s2 - chr) * -1;
	}
	if (!(str = (char *)ft_memalloc(sizeof(str) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strncpy(&str[len_s1], s2, len_s2);
	if (len_s2 == BUFF_SIZE)
		ft_bzero(s2, BUFF_SIZE);
	else
		ft_memmove(s2, &s2[len_s2 + 1], BUFF_SIZE);
	return (str);
}

static int		gnl_read_free(char *str)
{
	free(str);
	return (0);
}

static int		gnl_read(int fd, char **line, char *buf, int statut)
{
	char		*buf_save;
	char		*old;
	void		*pos;
	char		c;

	c = '\n';
	buf_save = (char *)ft_memalloc(sizeof(char *));
	pos = NULL;
	while (pos == NULL && statut >= 1)
	{
		if (ft_strlen(buf) == 0)
			statut = read(fd, (void *)buf, BUFF_SIZE);
		if (statut == 0)
			c = 0;
		pos = ft_strchr(buf, c);
		old = buf_save;
		buf_save = gnl_join(buf_save, buf, c);
		free(old);
		if (buf_save == NULL)
			return (-1);
	}
	*line = buf_save;
	if (statut <= 0 && ft_strlen(buf_save) == 0)
		return (gnl_read_free(buf_save));
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*buf;
	int			statut;

	if (fd < 0)
		return (-1);
	if (buf == 0)
		buf = ft_strdup("");
	free(buf);
	buf = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1));
	if (buf == NULL)
		return (-1);
	if (BUFF_SIZE < 1)
		return (-1);
	statut = gnl_read(fd, line, buf, 1);
	return (statut);
}
