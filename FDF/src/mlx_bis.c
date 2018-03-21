/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 18:39:04 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/08/30 06:37:02 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (e->event->scl_minus)
		e->event->scl_d--;
	if (e->event->scl_plus)
		e->event->scl_d++;
	if (e->event->up)
		e->event->mv_y -= 2;
	if (e->event->down)
		e->event->mv_y += 2;
	if (e->event->left)
		e->event->mv_x -= 2;
	if (e->event->right)
		e->event->mv_x += 2;
	if (e->event->reset)
		reset_param(e);
	render(e);
	return (0);
}

void	reset_param(t_env *e)
{
	t_event	*event;

	event = e->event;
	e->scl = event->scl;
	event->scl_d = 0;
	event->mv_x = 0;
	event->mv_y = 0;
}

void	mlx_clear_image(t_win *win, t_env *e)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < e->h)
	{
		x = 0;
		while (x < e->w)
		{
			i = (x * win->bpp / 8) + y * win->sizeline;
			win->data[i] = 0;
			win->data[i + 1] = 0;
			win->data[i + 2] = 0;
			x++;
		}
		y++;
	}
}
