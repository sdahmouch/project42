/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:09:36 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:11:21 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	alloc_mem_bis(t_env *e, t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		e->light[i++] = *(t_light *)tmp->content;
		tmp = tmp->next;
	}
}

void		alloc_mem(t_env *e)
{
	int		i;
	t_list	*tmp;

	if (e->gen.obj_num)
	{
		if (!(e->obj = (t_obj *)ft_memalloc(sizeof(t_obj) * e->gen.obj_num)))
			malloc_error(e);
		i = 0;
		tmp = e->list_obj;
		while (tmp)
		{
			e->obj[i++] = *(t_obj *)tmp->content;
			tmp = tmp->next;
		}
	}
	if (e->gen.light_num)
	{
		if (!(e->light = (t_light *)ft_memalloc(sizeof(t_light) *
						e->gen.light_num)))
			malloc_error(e);
		tmp = e->list_light;
		alloc_mem_bis(e, tmp);
	}
}
