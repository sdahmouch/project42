/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:20:25 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:30:08 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sdl_vect_dir(t_env *e)
{
	e->cam->dir.x = cos(e->cam->yaw) * cos(e->cam->pitch);
	e->cam->dir.y = sin(e->cam->pitch);
	e->cam->dir.z = sin(e->cam->yaw) * cos(e->cam->pitch);
	e->cam->dir = normalize(e->cam->dir);
}
