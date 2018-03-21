/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:17:02 by dcooray           #+#    #+#             */
/*   Updated: 2016/12/06 11:22:58 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_resolve_array(t_map *map, t_tetris *list)
{
	int		i;
	int		j;

	if (list == NULL)
		return (1);
	i = 0;
	while (i < map->size - list->height + 1)
	{
		j = 0;
		while (j < map->size - list->width + 1)
		{
			if (ft_place(list, map, i, j))
			{
				if (ft_resolve_array(map, list->next))
					return (1);
				else
					ft_put_value(list, map, ft_init_point(i, j), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map		*ft_resolve(t_tetris *list)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_number_list(list) * 4);
	map = ft_init_map(size);
	while (!(ft_resolve_array(map, list)))
	{
		size++;
		ft_delmap(&map);
		map = ft_init_map(size);
	}
	return (map);
}

void		ft_put_value(t_tetris *list, t_map *map, t_coord *coord,
			char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->height)
	{
		j = 0;
		while (j < list->width)
		{
			if (list->tetris[i][j] == '#')
				map->tab[coord->i + i][coord->j + j] = c;
			j++;
		}
		i++;
	}
	ft_delcoord(&coord);
}
