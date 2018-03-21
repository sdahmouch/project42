/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:01:57 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 19:29:59 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sdl(t_env *e)
{
	e->sdl.window = NULL;
	e->sdl.renderer = NULL;
	e->sdl.texture = NULL;
	e->sdl.pixel_format = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		sdl_cl_error(0, e);
	e->sdl_status = 1;
	if (!(e->sdl.window = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1024, 576, SDL_WINDOW_SHOWN)))
		sdl_cl_error(0, e);
	if (!(e->sdl.renderer = SDL_CreateRenderer(e->sdl.window, -1,
		SDL_RENDERER_ACCELERATED)))
		sdl_cl_error(0, e);
	if (!(e->sdl.texture = SDL_CreateTexture(e->sdl.renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 1024, 576)))
		sdl_cl_error(0, e);
	if (!(e->sdl.pixel_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888)))
		sdl_cl_error(0, e);
	if ((SDL_SetTextureBlendMode(e->sdl.texture, SDL_BLENDMODE_BLEND)) < 0)
		sdl_cl_error(0, e);
}

void	destroy_sdl(t_env *e)
{
	if (e->sdl.pixel_format)
		SDL_FreeFormat(e->sdl.pixel_format);
	if (e->sdl.texture)
		SDL_DestroyTexture(e->sdl.texture);
	if (e->sdl.renderer)
		SDL_DestroyRenderer(e->sdl.renderer);
	if (e->sdl.window)
		SDL_DestroyWindow(e->sdl.window);
	if (e->sdl_status)
		SDL_Quit();
}
