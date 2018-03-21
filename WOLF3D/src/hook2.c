/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:10:34 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/19 01:23:40 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			ft_exit_bis(t_env *env)
{
	ft_exit(0, env);
	return (0);
}

int			ft_get_color(t_env *env, int y)
{
	int		color;

	if (env->side)
	{
		if (env->ray->stepy < 0)
			color = 0xF92250;
		else
			color = 0xB1FF46;
	}
	else
	{
		if (env->ray->stepx < 0)
			color = 0xFF9F3B;
		else
			color = 0x86EDF2;
	}
	if (y < env->ray->start)
		color = 0xA9A9A9;
	else if (y > env->ray->end)
		color = 0x000000;
	else if (env->map[env->mapy][env->mapx] == 2)
		color /= 2;
	else if (env->map[env->mapy][env->mapx] == 4)
		color = 0x663300;
	return (color);
}

int			ft_rotate(t_env *env, int keycode)
{
	int		rot;
	double	dirxtmp;
	double	planextmp;

	if (keycode == 123)
		rot = 1;
	else
		rot = -1;
	if (keycode == 123 || keycode == 124)
	{
		dirxtmp = env->player->dirx;
		planextmp = env->player->planex;
		env->player->dirx = dirxtmp * cos(0.1 * rot)
			- env->player->diry * sin(0.1 * rot);
		env->player->diry = dirxtmp * sin(0.1 * rot)
			+ env->player->diry * cos(0.1 * rot);
		env->player->planex = planextmp * cos(0.1 * rot)
			- env->player->planey * sin(0.1 * rot);
		env->player->planey = planextmp * sin(0.1 * rot)
			+ env->player->planey * cos(0.1 * rot);
	}
	return (0);
}

int			ft_move(t_env *env, int keycode)
{
	if (keycode == 126)
	{
		if (!(env->map[(int)(env->player->posy)][(int)(env->player->posx
						+ env->player->dirx * 0.1)]))
			env->player->posx += env->player->dirx * 0.1;
		if (!(env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx)]))
			env->player->posy += env->player->diry * 0.1;
	}
	if (keycode == 125)
	{
		if (env->map[(int)(env->player->posy - env->player->diry
					* 0.1)][(int)(env->player->posx)] == 0)
			env->player->posy -= env->player->diry * 0.1;
		if (env->map[(int)(env->player->posy)][(int)(env->player->posx
				- env->player->dirx * 0.1)] == 0)
			env->player->posx -= env->player->dirx * 0.1;
	}
	return (0);
}
