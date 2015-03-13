/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:02:10 by etheodor          #+#    #+#             */
/*   Updated: 2015/03/13 15:16:55 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_lst
{
	char			*buf;
	int				fd;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(int fd, char **line);

#endif