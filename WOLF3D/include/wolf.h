/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:03:46 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/19 01:54:15 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct	s_player
{
	double		relx;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		distance;
	double		movespeed;
	double		rotspeed;
}				t_player;

typedef struct	s_ray
{
	double		deltadistx;
	double		deltadisty;
	double		distx;
	double		disty;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	int			len;
	int			stepx;
	int			stepy;
	int			start;
	int			end;
}				t_ray;

typedef struct	s_env
{
	t_player	*player;
	t_ray		*ray;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			redraw;
	int			endian;
	int			**map;
	int			mapx;
	int			mapy;
	int			side;
	int			size;
	int			bpp;
	int			hit;
}				t_env;

t_env			*ft_init_env(void);
void			ft_draw(t_env *env);
void			ft_hit_ray(t_env *env);
int				ft_exit_bis(t_env *env);
void			ft_exit(int n, t_env *env);
int				ft_rotate(t_env *env, int keycode);
int				ft_key_press(int keycode, t_env *env);
int				ft_get_color(t_env *env, int y);
int				ft_move(t_env *env, int keycode);
int				music_play(int keycode);

#endif
