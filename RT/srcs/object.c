/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:31:32 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 17:02:42 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_object_bis(t_obj *obj)
{
	obj->clr.x = 0.0;
	obj->clr.y = 0.0;
	obj->clr.z = 0.0;
	obj->clr.w = 0.0;
	obj->radius = 0.0;
	obj->k = 0.0;
	obj->ambient = 0.0;
	obj->specular = 0.0;
	obj->phong = 0.0;
	obj->reflective = 0.0;
	obj->refractive = 0.0;
	obj->refractive_n = 1.0;
	obj->height_min = 0.0;
	obj->height_max = 0.0;
	obj->bump = 0.0;
	obj->mirror = 0;
	obj->damier = 0;
	obj->type = 0;
}

static void	init_object(t_env *e)
{
	t_obj	*obj;
	t_list	*tmp;

	if (!(obj = (t_obj *)ft_memalloc(sizeof(t_obj))))
		malloc_error(e);
	obj->type = 0;
	obj->ori.x = 0.0;
	obj->ori.y = 0.0;
	obj->ori.z = 0.0;
	obj->ori.w = 0.0;
	obj->rot.x = 0.0;
	obj->rot.y = 0.0;
	obj->rot.z = 0.0;
	obj->rot.w = 0.0;
	init_object_bis(obj);
	if (!(tmp = ft_lstnew(obj, sizeof(t_obj))))
		malloc_error(e);
	ft_lstadd(&e->list_obj, tmp);
	ft_memdel((void **)&obj);
}

static void	object_ter(char *str, t_obj *obj, t_env *e)
{
	if (!ft_strncmp("Color", str, 5))
		object_color(str + 5, obj, e);
	else if (!ft_strncmp("Reflective", str, 10))
		init_float(str + 10, &obj->reflective, e);
	else if (!ft_strncmp("Refractive_n", str, 12))
		init_float(str + 12, &obj->refractive_n, e);
	else if (!ft_strncmp("Refractive", str, 10))
		init_float(str + 10, &obj->refractive, e);
	else if (!ft_strncmp("Bump", str, 4))
		init_float(str + 4, &obj->bump, e);
	else if (!ft_strncmp("Mirror", str, 6))
		init_int(str + 6, &obj->mirror, e);
	else if (!ft_strncmp("Damier", str, 6))
		init_int(str + 6, &obj->damier, e);
	else
		syntax_error(e);
}

static void	object_bis(char *str, t_obj *obj, t_env *e)
{
	if ((!ft_strncmp("Inter", str, 5) && e->obj_status == 1) ||
			e->obj_status == 2)
		object_inter(str, obj, e);
	else if (!ft_strncmp("Type", str, 4))
		object_type(str + 4, obj, e);
	else if (!ft_strncmp("Ambient", str, 7))
		init_float(str + 7, &obj->ambient, e);
	else if (!ft_strncmp("Specular", str, 8))
		init_float(str + 8, &obj->specular, e);
	else if (!ft_strncmp("Phong", str, 5))
		init_float(str + 5, &obj->phong, e);
	else
		object_ter(str, obj, e);
}

void		object(char *str, t_env *e)
{
	t_obj	*obj;

	if (e->status == 1)
	{
		str += 6;
		parse_empty(&str);
		if (*str != '{')
			syntax_error(e);
		str++;
		e->status = 5;
		e->gen.obj_num++;
		init_object(e);
		e->obj_status = 1;
		parse_empty(&str);
		object(str, e);
	}
	else if (*str == '}' && e->obj_status == 1)
		e->status = 1;
	else if (*str)
	{
		obj = (t_obj *)e->list_obj->content;
		object_bis(str, obj, e);
	}
}
