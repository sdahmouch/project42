/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:04:00 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/19 01:58:19 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void			ft_exit(int n, t_env *env)
{
	if (n < 0)
		ft_putendl("Error");
	else
	{
		system("killall afplay > /dev/null 2>&1");
		ft_putendl("Fin du programme");
	}
	if (env->player)
		free(env->player);
	if (env->ray)
		free(env->ray);
	if (env->map)
		free(env->map);
	mlx_destroy_window(env->mlx, env->win);
	if (env)
		free(env);
	exit(n);
}

static int		ft_loop_hook(t_env *env)
{
	if (env->redraw)
	{
		ft_draw(env);
		env->redraw = 0;
	}
	return (0);
}

static int		ft_expose(t_env *env)
{
	env->redraw = 1;
	return (0);
}

void			ft_draw(t_env *env)
{
	if (!(env->img = mlx_new_image(env->mlx, 800, 600)))
		ft_exit(0, env);
	if (!(env->img_addr = mlx_get_data_addr(env->img, &(env->bpp),
					&(env->size), &(env->endian))))
		ft_exit(0, env);
	ft_hit_ray(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

int				main(void)
{
	t_env		*env;

	if (!(env = ft_init_env()))
		ft_exit(0, env);
	if (!(env->mlx = mlx_init()))
		ft_exit(0, env);
	if (!(env->win = mlx_new_window(env->mlx, 800, 600, "Wolf3d")))
		ft_exit(0, env);
	mlx_expose_hook(env->win, ft_expose, env);
	mlx_hook(env->win, 2, (1L << 0), ft_key_press, env);
	mlx_hook(env->win, 17, 1, ft_exit_bis, env);
	mlx_loop_hook(env->mlx, ft_loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
