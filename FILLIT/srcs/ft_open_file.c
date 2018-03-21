/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 08:50:46 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/26 23:38:51 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_open_file(char **argv)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	if (!buf)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (buf[ret - 2] == '\n' && buf[ret - 1] == '\n')
		ft_error();
	if (close(fd) == -1)
		ft_error();
	return (buf);
}

t_tetris	*ft_init_tetris(char *str)
{
	int			i;
	int			j;
	t_tetris	*list;

	list = ft_define_list();
	while (*str != '\0')
	{
		i = 0;
		j = 4;
		while (ft_strlen(str) == 4 && j--)
		{
			ft_strcpy(list->tetris[i++], str);
			while (*str != '\n')
				str++;
			str++;
			if (ft_init_tetris_bis(str, j))
				return (list);
		}
		if (*str == '\n')
			str++;
		if (j || ft_strlen(str) != 4)
			ft_error();
		ft_addlist(&list);
	}
	return (list);
}

int			ft_init_tetris_bis(char *str, int j)
{
	if (*str == '\0' && j == 0)
		return (1);
	else if (*str == '\0' && j)
		ft_error();
	return (0);
}
