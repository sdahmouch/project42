/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:03:26 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/15 15:27:50 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static void		ft_direction_ray(t_env *env)
{
	if (env->ray->dirx < 0)
	{
		env->ray->stepx = -1;
		env->ray->distx = (env->ray->posx - env->mapx) * env->ray->deltadistx;
	}
	else
	{
		env->ray->stepx = 1;
		env->ray->distx = (env->mapx + 1.0 - env->ray->posx)
			* env->ray->deltadistx;
	}
	if (env->ray->diry < 0)
	{
		env->ray->stepy = -1;
		env->ray->disty = (env->ray->posy - env->mapy)
			* env->ray->deltadisty;
	}
	else
	{
		env->ray->stepy = 1;
		env->ray->disty = (env->mapy + 1.0 - env->ray->posy)
			* env->ray->deltadisty;
	}
}

static void		ft_init_ray(t_env *env, int x)
{
	env->player->relx = 2 * x / (double)800 - 1;
	env->ray->posx = env->player->posx;
	env->ray->posy = env->player->posy;
	env->ray->dirx = env->player->dirx + env->player->planex
		* env->player->relx;
	env->ray->diry = env->player->diry + env->player->planey
		* env->player->relx;
	env->mapx = (int)env->ray->posx;
	env->mapy = (int)env->ray->posy;
	env->ray->deltadisty = sqrt(1 + (env->ray->dirx * env->ray->dirx)
			/ (env->ray->diry * env->ray->diry));
	env->ray->deltadistx = sqrt(1 + (env->ray->diry * env->ray->diry)
			/ (env->ray->dirx * env->ray->dirx));
	env->hit = 0;
	ft_direction_ray(env);
}

static void		ft_draw_line(t_env *env, int x)
{
	int			y;
	int			pos;
	int			color;

	y = 0;
	while (y < 600)
	{
		color = ft_get_color(env, y);
		pos = (x * (env->bpp / 8)) + (y * env->size);
		env->img_addr[pos] = mlx_get_color_value(env->mlx, color);
		env->img_addr[pos + 1] = mlx_get_color_value(env->mlx, color >> 8);
		env->img_addr[pos + 2] = mlx_get_color_value(env->mlx, color >> 16);
		y++;
	}
}

static void		ft_size_ray(t_env *env, int x)
{
	if (!env->side)
		env->player->distance = (env->mapx - env->ray->posx
				+ (1 - env->ray->stepx) / 2) / env->ray->dirx;
	else
		env->player->distance = (env->mapy - env->ray->posy
				+ (1 - env->ray->stepy) / 2) / env->ray->diry;
	env->ray->len = (int)(600 / env->player->distance);
	env->ray->start = -(env->ray->len) / 2 + 600 / 2;
	env->ray->end = env->ray->len / 2 + 600 / 2;
	if (env->ray->start < 0)
		env->ray->start = 0;
	if (env->ray->end >= 600)
		env->ray->end = 600 - 1;
	ft_draw_line(env, x);
}

void			ft_hit_ray(t_env *env)
{
	int		x;

	x = -1;
	while (++x < 800)
	{
		ft_init_ray(env, x);
		while (!env->hit)
		{
			if (env->ray->distx < env->ray->disty)
			{
				env->ray->distx += env->ray->deltadistx;
				env->mapx += env->ray->stepx;
				env->side = 0;
			}
			else
			{
				env->ray->disty += env->ray->deltadisty;
				env->mapy += env->ray->stepy;
				env->side = 1;
			}
			if ((env->map[env->mapy][env->mapx]))
				env->hit = 1;
		}
		ft_size_ray(env, x);
	}
}
