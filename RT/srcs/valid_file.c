/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:54:16 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:18 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	check_valid_color(cl_float4 clr)
{
	if (clr.x < 0 || clr.x > 255 || clr.y < 0 || clr.y > 255 ||
			clr.z < 0 || clr.z > 255 || clr.w < 0 || clr.w > 255)
		return (1);
	return (0);
}

static void	check_valid_general(t_env *e)
{
	if (check_valid_color(e->gen.clr))
		syntax_error(e);
	if (e->gen.recursion < 0)
		syntax_error(e);
	if (e->gen.antialliasing != 1 && e->gen.antialliasing != 4 &&
			e->gen.antialliasing != 16)
		syntax_error(e);
	if (e->gen.effect < 0 || e->gen.effect > 4)
		syntax_error(e);
}

static void	check_valid_object_bis(t_env *e, int i)
{
	if (check_valid_color(e->obj[i].clr))
		syntax_error(e);
	if (e->obj[i].ambient < 0.0 || e->obj[i].ambient > 1.0)
		syntax_error(e);
	if (e->obj[i].specular < 0.0 || e->obj[i].specular > 1.0)
		syntax_error(e);
	if (e->obj[i].phong < 0.0)
		syntax_error(e);
	if (e->obj[i].reflective < 0.0 || e->obj[i].reflective > 1.0)
		syntax_error(e);
	if (e->obj[i].refractive < 0.0 || e->obj[i].refractive > 1.0)
		syntax_error(e);
	if (e->obj[i].refractive_n < 1.0)
		syntax_error(e);
	if (e->obj[i].bump < 0.0 && e->obj[i].bump > 1.0)
		syntax_error(e);
	if (e->obj[i].mirror != 0 && e->obj[i].mirror != 1)
		syntax_error(e);
	if (e->obj[i].damier != 0 && e->obj[i].damier != 1)
		syntax_error(e);
}

static void	check_valid_object(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->gen.obj_num)
	{
		if (e->obj[i].type == 0)
			syntax_error(e);
		if (e->obj[i].type == 1 && e->obj[i].radius <= 0.0)
			syntax_error(e);
		if (e->obj[i].type == 3 && (e->obj[i].radius <= 0.0 ||
					e->obj[i].height_max < 0.0))
			syntax_error(e);
		if (e->obj[i].type == 4 && (e->obj[i].k <= 0.0 ||
					e->obj[i].k >= tan(M_PI / 2.0) ||
						e->obj[i].height_max <= e->obj[i].height_min) &&
							e->obj[i].height_max)
			syntax_error(e);
		check_valid_object_bis(e, i);
		i++;
	}
}

void		valid_file(t_env *e)
{
	int	i;

	check_valid_general(e);
	if (!e->cam)
		syntax_error(e);
	if (e->cam->fov <= 0.0 || e->cam->fov >= M_PI)
		syntax_error(e);
	if (e->cam->pitch < -1.1 || e->cam->pitch > 1.1)
		syntax_error(e);
	if (e->cam->yaw < -M_PI || e->cam->yaw >= M_PI)
		syntax_error(e);
	i = 0;
	while (i < e->gen.light_num)
	{
		if (check_valid_color(e->light[i].clr))
			syntax_error(e);
		if (e->light[i].radius < 0.0)
			syntax_error(e);
		i++;
	}
	check_valid_object(e);
}
