/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:00:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 20:11:57 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_cam(t_env *e)
{
	if (!(e->cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
		syntax_error(e);
	e->cam->ori.x = 0.0f;
	e->cam->ori.y = 0.0f;
	e->cam->ori.z = 0.0f;
	e->cam->ori.w = 0.0f;
	e->cam->dir.x = 0.0f;
	e->cam->dir.y = 0.0f;
	e->cam->dir.z = 0.0f;
	e->cam->dir.w = 0.0f;
	e->cam->fov = M_PI_2;
	e->cam->pitch = 0.0;
	e->cam->yaw = 0.0;
}

static void	camera_origin(char *str, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		e->cam->ori.x = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		e->cam->ori.y = (cl_float)ft_atoif(parse_empty(&str));
		parse_number(&str);
		e->cam->ori.z = (cl_float)ft_atoif(parse_empty(&str));
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

static void	camera_rotation(char *str, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		e->cam->pitch = (cl_float)ft_atoif(parse_empty(&str)) * M_PI / 180.0;
		parse_number(&str);
		e->cam->yaw = (cl_float)ft_atoif(parse_empty(&str)) * M_PI / 180.0;
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

static void	init_cam_bis(char *str, t_env *e)
{
	if (!ft_strncmp("Origin", str, 6))
		camera_origin(str + 6, e);
	else if (!ft_strncmp("Rotation", str, 8))
		camera_rotation(str + 8, e);
	else if (!ft_strncmp("Fov", str, 3))
	{
		init_float(str + 3, &e->cam->fov, e);
		e->cam->fov = e->cam->fov * M_PI / 180.0;
	}
	else
		syntax_error(e);
}

void		camera(char *str, t_env *e)
{
	if (e->status == 1 && !e->cam_status)
	{
		str += 6;
		parse_empty(&str);
		if (*str != '{')
			syntax_error(e);
		str++;
		e->status = 3;
		parse_empty(&str);
		init_cam(e);
		e->cam_status = 1;
		camera(str, e);
	}
	else if (*str == '}')
		e->status = 1;
	else if (*str)
		init_cam_bis(str, e);
}
