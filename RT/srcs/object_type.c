/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:37:41 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:00 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sphere(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->radius = (cl_float)ft_atoif(parse_empty(&str));
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

void	plane(char *str, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
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

void	cylinder(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->radius = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		obj->height_max = (cl_float)ft_atoif(parse_empty(&str));
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

void	cone(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->k = tan(((cl_float)ft_atoif(parse_empty(&str)) *
					M_PI / 180.0) / 2.0);
		parse_number(&str);
		obj->height_min = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		obj->height_max = (cl_float)ft_atoif(parse_empty(&str));
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

void	object_type_bis(char *str, t_obj *obj, t_env *e)
{
	if (!ft_strncmp("Sphere", str, 6))
		obj->type = 1;
	else if (!ft_strncmp("Plane", str, 5))
		obj->type = 2;
	else if (!ft_strncmp("Cylinder", str, 8))
		obj->type = 3;
	else if (!ft_strncmp("Cone", str, 4))
		obj->type = 4;
	else
		syntax_error(e);
}
