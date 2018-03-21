/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:00:23 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:31:13 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	general_color(char *str, t_env *e)
{
	parse_empty(&str);
	if (*str == '{')
	{
		str++;
		e->gen.clr.x = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		e->gen.clr.y = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		e->gen.clr.z = (cl_float)ft_atoi(parse_empty(&str));
		parse_number(&str);
		e->gen.clr.w = (cl_float)ft_atoi(parse_empty(&str));
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

static void	general_bis(char *str, t_env *e)
{
	if (!ft_strncmp("Recursion", str, 9))
		init_int(str + 9, &e->gen.recursion, e);
	else if (!ft_strncmp("Color", str, 5))
		general_color(str + 5, e);
	else if (!ft_strncmp("Antialliasing", str, 13))
		init_int(str + 13, &e->gen.antialliasing, e);
	else if (!ft_strncmp("Effect", str, 6))
		init_int(str + 6, &e->gen.effect, e);
	else
		syntax_error(e);
}

void		general(char *str, t_env *e)
{
	if (e->status == 1)
	{
		str += 7;
		parse_empty(&str);
		if (*str != '{')
			syntax_error(e);
		str++;
		e->status = 2;
		parse_empty(&str);
		general(str, e);
	}
	else if (*str == '}')
		e->status = 1;
	else if (*str)
		general_bis(str, e);
}
