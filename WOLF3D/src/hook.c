/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:03:35 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/19 01:08:39 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static	void	ft_change_color_wall(t_env *env, int keycode)
{
	if (keycode == 49)
	{
		if (env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] == 1)
		{
			env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] = 2;
			system("afplay music/paint.mp3&");
		}
		else if (env->map[(int)(env->player->posy + env->player->diry)]
			[(int)(env->player->posx + env->player->dirx)] == 2)
		{
			env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] = 1;
			system("afplay music/paint.mp3&");
		}
	}
}

static	void	ft_creat_wall(t_env *env, int keycode)
{
	if (keycode == 8)
	{
		if (env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] == 0)
		{
			env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] = 3;
			system("afplay music/creat.mp3&");
		}
	}
	else if (keycode == 9)
	{
		if (env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] == 3)
		{
			env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] = 0;
			system("afplay music/del.mp3&");
		}
	}
}

static	void	ft_open(t_env *env, int keycode)
{
	if (keycode == 31)
	{
		if (env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] == 4)
		{
			env->map[(int)(env->player->posy + env->player->diry)]
				[(int)(env->player->posx + env->player->dirx)] = 0;
			system("afplay music/porte.mp3&");
		}
	}
}

int				ft_key_press(int keycode, t_env *env)
{
	music_play(keycode);
	if (keycode == 53)
		ft_exit(0, env);
	ft_change_color_wall(env, keycode);
	ft_creat_wall(env, keycode);
	ft_open(env, keycode);
	ft_rotate(env, keycode);
	ft_move(env, keycode);
	ft_draw(env);
	return (0);
}
