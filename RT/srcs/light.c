/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:31:26 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:24 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_light(t_env *e)
{
	t_light	*light;
	t_list	*tmp;

	if (!(light = (t_light *)ft_memalloc(sizeof(t_light))))
		malloc_error(e);
	light->ori.x = 0.0;
	light->ori.y = 0.0;
	light->ori.z = 0.0;
	light->ori.w = 0.0;
	light->clr.x = 255.0;
	light->clr.y = 255.0;
	light->clr.z = 255.0;
	light->clr.w = 255.0;
	light->radius = 5.0;
	if (!(tmp = ft_lstnew(light, sizeof(t_light))))
		malloc_error(e);
	ft_lstadd(&e->list_light, tmp);
	ft_memdel((void **)&light);
}

static void	light_origin(char *str, t_light *light, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		light->ori.x = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		light->ori.y = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		light->ori.z = (cl_float)ft_atoif(parse_empty(&str));
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

static void	light_color(char *str, t_light *light, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		light->clr.x = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		light->clr.y = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		light->clr.z = (cl_float)ft_atoi(parse_empty(&str));
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

static void	light_bis(char *str, t_light *light, t_env *e)
{
	if (!ft_strncmp("Origin", str, 6))
		light_origin(str + 6, light, e);
	else if (!ft_strncmp("Color", str, 5))
		light_color(str + 5, light, e);
	else if (!ft_memcmp("Radius", str, 6))
		init_float(str + 6, &light->radius, e);
	else
		syntax_error(e);
}

void		light(char *str, t_env *e)
{
	t_light	*tmp_light;

	if (e->status == 1)
	{
		str += 5;
		parse_empty(&str);
		if (*str != '{')
			syntax_error(e);
		str++;
		e->status = 4;
		e->gen.light_num++;
		init_light(e);
		e->light_status = 1;
		parse_empty(&str);
		light(str, e);
	}
	else if (*str == '}')
		e->status = 1;
	else if (*str)
	{
		tmp_light = (t_light *)e->list_light->content;
		light_bis(str, tmp_light, e);
	}
}
