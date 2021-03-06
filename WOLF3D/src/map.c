/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:03:53 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/19 01:06:14 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			ft_map(int x, int y)
{
	static int	map[22][22] = {
	{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5},
	{5, 5, 5, 5, 4, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 4, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 5},
	{5, 0, 5, 5, 4, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 5, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 4, 0, 0, 5},
	{5, 0, 4, 0, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5},
	{5, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5},
	{5, 0, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 5, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5},
	{5, 0, 4, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 5},
	{5, 0, 5, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 5},
	{5, 4, 5, 5, 4, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 4, 5, 5, 5, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 4, 5, 5, 5, 0, 0, 0, 0, 0, 0, 5},
	{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
	{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}};

	return (map[x][y]);
}

int			ft_map2(int x, int y)
{
	static int map[22][44] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	return (map[x - 22][y]);
}

static void	ft_init_map(t_env *env)
{
	int		x;

	x = 0;
	if (!(env->map = (int **)malloc(sizeof(int *) * 45)))
		ft_exit(-1, env);
	while (x < 45)
	{
		if (!(env->map[x] = (int *)malloc(sizeof(int) * 45)))
			ft_exit(-1, env);
		x++;
	}
}

static void	ft_init_map2(t_env *env)
{
	int		x;
	int		y;

	ft_init_map(env);
	x = 0;
	y = 0;
	while (x < 45)
	{
		while (y < 45)
		{
			if (x < 22)
				env->map[x][y] = ft_map(x, y);
			else if (x < 44)
				env->map[x][y] = ft_map2(x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

t_env		*ft_init_env(void)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		exit(0);
	if (!(env->player = (t_player *)malloc(sizeof(t_player))))
		ft_exit(-1, env);
	if (!(env->ray = (t_ray *)malloc(sizeof(t_ray))))
		ft_exit(-1, env);
	env->player->posx = 10;
	env->player->posy = 2;
	env->player->dirx = -1;
	env->player->diry = 0;
	env->player->planex = 0;
	env->player->planey = 0.66;
	env->player->rotspeed = 6.0;
	env->player->movespeed = 9.0;
	env->redraw = 0;
	ft_init_map2(env);
	system("afplay music/music.mp3&");
	return (env);
}
