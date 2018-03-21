/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:38:25 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:54:01 by epimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	delete_list_maillon(void *tmp, size_t n)
{
	(void)n;
	ft_memdel((void **)&tmp);
}

void		delete_env(t_env *e)
{
	if (e)
	{
		if (e->cam)
			ft_memdel((void **)&e->cam);
		if (e->gen.obj_num)
			ft_memdel((void **)&e->obj);
		if (e->gen.light_num)
			ft_memdel((void **)&e->light);
		ft_lstdel(&e->list_obj, &delete_list_maillon);
		ft_lstdel(&e->list_light, &delete_list_maillon);
		ft_strdel(&e->cl.source);
		ft_memdel((void **)&e->pixel);
		ft_memdel((void **)&e);
	}
}
