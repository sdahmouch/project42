/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:38:01 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:53:06 by epimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double		rotation_ter(double e)
{
	double	r;
	double	tmp1;
	double	tmp2;
	double	tmp3;
	double	tmp4;

	tmp1 = ((90.0 - 10e-4) * M_PI) / 180.0;
	tmp2 = ((90.0 + 10e-4) * M_PI) / 180.0;
	tmp3 = ((-90.0 - 10e-4) * M_PI) / 180.0;
	tmp4 = ((-90.0 + 10e-4) * M_PI) / 180.0;
	if ((e > tmp1 && e < tmp2) || (e > tmp3 && e < tmp4))
		r = 0.0;
	else
		r = cos(e);
	return (r);
}

static cl_float4	rotation_bis(cl_float4 rot)
{
	double		xp;
	double		yp;
	double		zp;
	cl_float4	ret;

	xp = rotation_ter((double)rot.x);
	yp = rotation_ter((double)rot.y);
	zp = rotation_ter((double)rot.z);
	ret.x = (cl_float)(-sin((double)rot.z) * xp + zp * sin((double)rot.y) *
		sin((double)rot.x));
	ret.y = (cl_float)(zp * xp + sin((double)rot.z) * sin((double)rot.y) *
		sin((double)rot.x));
	ret.z = (cl_float)(yp * sin((double)rot.x));
	ret.w = 0.0;
	return (ret);
}

void				rotation(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->gen.obj_num)
	{
		e->obj[i].o_axis = rotation_bis(e->obj[i].rot);
		e->obj[i].o_axis = normalize(e->obj[i].o_axis);
		i++;
	}
}
