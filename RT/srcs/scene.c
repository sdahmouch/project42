/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:06:52 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:31:47 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		init_scene(t_cam *cam)
{
	t_scene		scene;
	cl_float4	tmp1;
	cl_float4	tmp2;

	scene.viewdirection = cam->dir;
	scene.up.x = 0.0;
	scene.up.y = 1.0;
	scene.up.z = 0.0;
	scene.up.w = 0.0;
	scene.u = cross(scene.viewdirection, scene.up);
	scene.v = cross(scene.u, scene.viewdirection);
	scene.viewplanewidth = (cl_float)tan((double)cam->fov / 2.0);
	scene.aspectratio = 576.0 / 1024.0;
	scene.viewplaneheight = scene.aspectratio * scene.viewplanewidth;
	tmp1 = mult(scene.v, scene.viewplaneheight / 2.0);
	tmp2 = mult(scene.u, scene.viewplanewidth / 2.0);
	scene.viewplaneupleftpoint = add(cam->ori, add(scene.viewdirection,
				minus(tmp1, tmp2)));
	scene.xincvect = scene.viewplanewidth / 1024.0;
	scene.yincvect = scene.viewplaneheight / 576.0;
	return (scene);
}

static void	scene_bis(t_env *e, char *line)
{
	if ((!ft_strncmp(line, "General", 7) && e->status == 1) ||
			e->status == 2)
		general(line, e);
	else if ((!ft_strncmp(line, "Camera", 6) && !e->cam_status &&
				e->status == 1) || e->status == 3)
		camera(line, e);
	else if ((!ft_strncmp(line, "Light", 5) && e->status == 1) ||
			e->status == 4)
		light(line, e);
	else if ((!ft_strncmp(line, "Object", 6) && e->status == 1) ||
			e->status == 5)
		object(line, e);
	else if (*line == '}' && e->status == 1)
		e->status = 0;
	else
		syntax_error(e);
}

void		scene(t_env *e, char *line)
{
	parse_empty(&line);
	if (*line == '\0' || *line == '#')
		return ;
	else if ((!ft_strncmp(line, "Scene", 5) && !e->status))
	{
		line += 5;
		e->status = 1;
		parse_empty(&line);
		if (*line != '{')
			syntax_error(e);
		line++;
		scene(e, line);
	}
	else
		scene_bis(e, line);
}
