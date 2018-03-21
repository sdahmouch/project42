/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:39:27 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 19:39:49 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	object_origin(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->ori.x = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		obj->ori.y = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		obj->ori.z = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		parse_empty(&str);
		if (*str == '}')
		{
			str++;
			parse_empty(&str);
			if (*str)
				syntax_error(e);
		}
		else
			syntax_error(e);
	}
	else
		syntax_error(e);
}

static void	object_rotation(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->rot.x = (cl_float)ft_atoif(parse_empty(&str)) * M_PI / 180.0;
		parse_number(&str);
		obj->rot.y = (cl_float)ft_atoif(parse_empty(&str)) * M_PI / 180.0;
		parse_number(&str);
		obj->rot.z = (cl_float)ft_atoif(parse_empty(&str)) * M_PI / 180.0;
		parse_number(&str);
		parse_empty(&str);
		if (*str == '}')
		{
			str++;
			parse_empty(&str);
			if (*str)
				syntax_error(e);
		}
		else
			syntax_error(e);
	}
	else
		syntax_error(e);
}

static void	object_inter_bis(char *str, t_obj *obj, t_env *e)
{
	if (!ft_strncmp("Sphere", str, 6) && obj->type == 1)
		sphere(str + 6, obj, e);
	else if (!ft_strncmp("Plane", str, 5) && obj->type == 2)
		plane(str + 5, e);
	else if (!ft_strncmp("Cylinder", str, 8) && obj->type == 3)
		cylinder(str + 8, obj, e);
	else if (!ft_strncmp("Cone", str, 4) && obj->type == 4)
		cone(str + 4, obj, e);
	else if (!ft_strncmp("Origin", str, 6))
		object_origin(str + 6, obj, e);
	else if (!ft_strncmp("Rotation", str, 8))
		object_rotation(str + 8, obj, e);
}

void		object_type(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		parse_empty(&str);
		object_type_bis(str, obj, e);
		parse_alpha(&str);
		parse_empty(&str);
		if (*str == '}')
		{
			str++;
			parse_empty(&str);
			if (*str)
				syntax_error(e);
		}
		else
			syntax_error(e);
	}
	else
		syntax_error(e);
}

void		object_inter(char *str, t_obj *obj, t_env *e)
{
	if (e->obj_status == 1)
	{
		str += 5;
		parse_empty(&str);
		if (*str != '{')
			syntax_error(e);
		str++;
		e->obj_status = 2;
		parse_empty(&str);
		object_inter(str, obj, e);
	}
	else if (*str == '}')
		e->obj_status = 1;
	else if (*str)
		object_inter_bis(str, obj, e);
}
