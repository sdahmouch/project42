/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:55:24 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 20:27:06 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	sdl_put_pixel(t_env *e, int *j)
{
	int				i;
	int				k;
	unsigned int	*p;

	i = 0;
	k = 0;
	SDL_LockTexture(e->sdl.texture, NULL, (void **)&e->sdl.buffer,
			&e->sdl.pitch);
	while (i < 576)
	{
		p = (unsigned int *)(e->sdl.buffer + e->sdl.pitch * i);
		*j = 0;
		while (*j < 1024)
		{
			*p++ = SDL_MapRGBA(e->sdl.pixel_format, e->pixel[k].x,
					e->pixel[k].y, e->pixel[k].z, e->pixel[k].w);
			(*j)++;
			k++;
		}
		i++;
	}
	SDL_UnlockTexture(e->sdl.texture);
	SDL_RenderClear(e->sdl.renderer);
	SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, NULL, NULL);
	SDL_RenderPresent(e->sdl.renderer);
}

static int	sdl_track_mouse(t_env *e, int c)
{
	int	xrel;
	int	yrel;

	if (c)
	{
		SDL_GetRelativeMouseState(&xrel, &yrel);
		e->cam->pitch -= ((float)yrel * 0.1) * M_PI / 180.0;
		e->cam->yaw += ((float)xrel * 0.1) * M_PI / 180.0;
		if (e->cam->pitch > 1.1)
			e->cam->pitch = 1.1;
		if (e->cam->pitch < -1.1)
			e->cam->pitch = -1.1;
		if (e->cam->yaw < -M_PI)
			e->cam->yaw += 2 * M_PI;
		if (e->cam->yaw > M_PI)
			e->cam->yaw -= 2 * M_PI;
	}
	return (0);
}

static int	sdl_event_bis(t_env *e, const Uint8 *state, int *c)
{
	if (state[SDL_SCANCODE_D])
	{
		e->cam->ori.x += e->scene.u.x;
		e->cam->ori.y += e->scene.u.y;
		e->cam->ori.z += e->scene.u.z;
	}
	if (state[SDL_SCANCODE_C])
	{
		if (*c)
		{
			SDL_SetRelativeMouseMode(SDL_FALSE);
			*c = 0;
		}
		else
		{
			SDL_WarpMouseInWindow(e->sdl.window, 1024 / 2, 576 / 2);
			SDL_SetRelativeMouseMode(SDL_TRUE);
			SDL_GetRelativeMouseState(NULL, NULL);
			*c = 1;
		}
	}
	return (sdl_track_mouse(e, *c));
}

static int	sdl_event(t_env *e, const Uint8 *state, int *c)
{
	if (e->sdl.event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (state[SDL_SCANCODE_W])
	{
		e->cam->ori.x += e->scene.viewdirection.x;
		e->cam->ori.y += e->scene.viewdirection.y;
		e->cam->ori.z += e->scene.viewdirection.z;
	}
	if (state[SDL_SCANCODE_S])
	{
		e->cam->ori.x -= e->scene.viewdirection.x;
		e->cam->ori.y -= e->scene.viewdirection.y;
		e->cam->ori.z -= e->scene.viewdirection.z;
	}
	if (state[SDL_SCANCODE_A])
	{
		e->cam->ori.x -= e->scene.u.x;
		e->cam->ori.y -= e->scene.u.y;
		e->cam->ori.z -= e->scene.u.z;
	}
	return (sdl_event_bis(e, state, c));
}

void		rt(t_env *e)
{
	int			c;
	int			j;
	const Uint8	*state;

	cl_file_platform_context_commandqueue(e);
	cl_init_mem(e);
	cl_kernel_arg(e);
	sdl(e);
	c = 0;
	while (1)
	{
		SDL_PollEvent(&e->sdl.event);
		SDL_PumpEvents();
		sdl_vect_dir(e);
		state = SDL_GetKeyboardState(NULL);
		rotation(e);
		e->scene = init_scene(e->cam);
		cl_buffer_program(e);
		cl_launch_read(e);
		sdl_put_pixel(e, &j);
		if (sdl_event(e, state, &c))
			break ;
	}
	destroy_sdl(e);
	cl_destroy(e);
}
