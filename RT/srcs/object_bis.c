/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:35:14 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:10 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	object_color(char *str, t_obj *obj, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		obj->clr.x = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		obj->clr.y = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		obj->clr.z = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		obj->clr.w = (cl_float)ft_atoi(parse_empty(&str));
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
