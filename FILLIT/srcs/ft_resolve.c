/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:15:02 by dcooray           #+#    #+#             */
/*   Updated: 2016/12/06 11:24:44 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*ft_init_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	if (!map)
		ft_error();
	map->tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(map->tab))
		ft_error();
	while (i < size)
	{
		map->tab[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!(map->tab[i]))
			ft_error();
		j = 0;
		while (j < size)
			map->tab[i][j++] = '.';
		map->tab[i++][j] = '\0';
	}
	map->tab[i] = NULL;
	return (map);
}

int			ft_number_list(t_tetris *list)
{
	int		i;

	if (!list)
		ft_error();
	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int			ft_place(t_tetris *list, t_map *map, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (k < list->height)
	{
		l = 0;
		while (l < list->width)
		{
			if (list->tetris[k][l] == '#' && map->tab[i + k][j + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	ft_put_value(list, map, ft_init_point(i, j), list->letter);
	return (1);
}

int			high_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void		ft_return_min_square(char **table, int *k, int *l)
{
	int		i;
	int		j;

	i = 0;
	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != '\0')
		{
			if (table[i][j] != '.')
			{
				if (i > *k)
					*k = i;
				if (j > *l)
					*l = j;
			}
			j++;
		}
		i++;
	}
}
