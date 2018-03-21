/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:57:11 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 18:57:23 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_float(char *str, float *f, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		*f = (cl_float)ft_atoif(parse_empty(&str));
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

void		init_int(char *str, int *i, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		*i = (cl_int)ft_atoi(parse_empty(&str));
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

cl_float4	normalize(cl_float4 dir)
{
	cl_float	norm;
	cl_float	x;
	cl_float	y;
	cl_float	z;

	x = dir.x;
	y = dir.y;
	z = dir.z;
	norm = (cl_float)sqrt(pow((double)x, 2) + pow((double)y, 2) +
			pow((double)z, 2));
	dir.x /= norm;
	dir.y /= norm;
	dir.z /= norm;
	return (dir);
}
