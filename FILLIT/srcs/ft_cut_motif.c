/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_motif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:16:15 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/12/06 11:20:58 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		**ft_cut_motif(t_tetris *list, t_tetris **s_list)
{
	int			i;
	int			j;
	t_coord		*c;
	int			tmp;

	c = ft_return_min_motif(list);
	ft_init_cut(*s_list);
	tmp = c->j;
	i = 0;
	while (list->tetris[c->i] != NULL)
	{
		c->j = tmp;
		j = 0;
		while (list->tetris[c->i][c->j] != '\0')
			(*s_list)->tetris[i][j++] = list->tetris[c->i][c->j++];
		i++;
		c->i++;
	}
	if (list->next != NULL)
		ft_addlist(s_list);
	ft_delcoord(&c);
	return (s_list);
}

t_tetris		**ft_cut_motif_iter(t_tetris *list, t_tetris **s_list)
{
	t_tetris	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		ft_cut_motif(list, s_list);
		ft_del_onelist(&list);
		list = tmp;
	}
	return (s_list);
}

void			ft_init_cut(t_tetris *s_list)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			s_list->tetris[i][j++] = '.';
		s_list->tetris[i++][j] = '\0';
	}
	s_list->tetris[i] = NULL;
}

t_coord			*ft_return_min_motif(t_tetris *list)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 4;
	k = 3;
	l = 3;
	while (i >= 0 && i--)
	{
		j = 4;
		while (j >= 0 && j--)
		{
			if (list->tetris[i][j] != '.')
			{
				if (i < k)
					k = i;
				if (j < l)
					l = j;
			}
		}
	}
	return (ft_init_point(k, l));
}

void			ft_init_h_w_motif(t_tetris *s_list)
{
	int		i;
	int		j;

	while (s_list != NULL)
	{
		i = 0;
		j = 0;
		ft_return_min_square(s_list->tetris, &i, &j);
		s_list->height = i + 1;
		s_list->width = j + 1;
		s_list = s_list->next;
	}
}
