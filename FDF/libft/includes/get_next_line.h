/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:59:11 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/07/25 01:24:39 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9

typedef struct	s_node
{
	int			ret;
	int			index;
	int			new_line;
	int			fd;
	char		*buff;
}				t_node;
int				get_next_line(const int fd, char **line);

#endif
