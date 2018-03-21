/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:28:20 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:43 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../sdl/include/SDL.h"
# include "../libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <OpenCL/opencl.h>

typedef struct	s_cl
{
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				mempixel;
	cl_mem				memgen;
	cl_mem				memcam;
	cl_mem				memobj;
	cl_mem				memlight;
	cl_mem				memscene;
	cl_int				ret;
	cl_program			program;
	cl_kernel			kernel;
	char				*source;
	size_t				source_size;
	size_t				global_item_size[2];
	size_t				local_item_size[2];
}				t_cl;

typedef struct	s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	SDL_PixelFormat	*pixel_format;
	unsigned char	*buffer;
	int				pitch;
}				t_sdl;

typedef struct	s_gen
{
	cl_float4	clr;
	cl_int		obj_num;
	cl_int		light_num;
	cl_int		recursion;
	cl_int		antialliasing;
	cl_int		effect;
}				t_gen;

typedef struct	s_cam
{
	cl_float4	ori;
	cl_float4	dir;
	cl_float	fov;
	cl_float	pitch;
	cl_float	yaw;
}				t_cam;

typedef struct	s_obj
{
	cl_float4	ori;
	cl_float4	rot;
	cl_float4	o_axis;
	cl_float4	clr;
	cl_float	radius;
	cl_float	k;
	cl_float	ambient;
	cl_float	specular;
	cl_float	phong;
	cl_float	reflective;
	cl_float	refractive;
	cl_float	refractive_n;
	cl_float	height_min;
	cl_float	height_max;
	cl_float	bump;
	cl_int		type;
	cl_int		mirror;
	cl_int		damier;
}				t_obj;

typedef struct	s_light
{
	cl_float4	ori;
	cl_float4	clr;
	cl_float	radius;
}				t_light;

typedef struct	s_scene
{
	cl_float4	viewdirection;
	cl_float4	u;
	cl_float4	up;
	cl_float4	v;
	cl_float4	viewplaneupleftpoint;
	cl_float	aspectratio;
	cl_float	viewplanewidth;
	cl_float	viewplaneheight;
	cl_float	xincvect;
	cl_float	yincvect;
}				t_scene;

typedef struct	s_env
{
	t_gen		gen;
	t_sdl		sdl;
	t_cl		cl;
	t_cam		*cam;
	t_obj		*obj;
	t_light		*light;
	t_list		*list_obj;
	t_list		*list_light;
	t_scene		scene;
	cl_uchar4	*pixel;
	int			status;
	int			sdl_status;
	int			cam_status;
	int			obj_status;
	int			light_status;
}				t_env;

/*
**	Error functions
*/

void			sdl_cl_error(int i, t_env *e);
void			basic_error(char *str, t_env *e);
void			malloc_error(t_env *e);
void			empty_file(t_env *e);
void			syntax_error(t_env *e);

/*
**	Divers functions
*/

char			*parse_str(char **str);
void			parse_number(char **str);
char			*parse_empty(char **str);
void			parse_alpha(char **str);
void			init_float(char *str, float *f, t_env *e);
void			init_int(char *str, int *i, t_env *e);
cl_float4		normalize(cl_float4 dir);
void			rotation(t_env *e);

/*
**	Calculus functions for the vectors
*/

cl_float4		cross(cl_float4 u, cl_float4 v);
cl_float4		mult(cl_float4 u, cl_float mult);
cl_float4		add(cl_float4 u, cl_float4 v);
cl_float4		minus(cl_float4 u, cl_float4 v);

/*
**	General, camera, objects, lights and scene intialisation functions
*/

void			scene(t_env *e, char *line);
void			general(char *str, t_env *e);
void			camera(char *str, t_env *e);
void			light(char *str, t_env *e);
void			object(char *str, t_env *e);
void			object_color(char *str, t_obj *obj, t_env *e);
void			object_type(char *str, t_obj *obj, t_env *e);
void			object_type_bis(char *str, t_obj *obj, t_env *e);
void			object_inter(char *str, t_obj *obj, t_env *e);
void			sphere(char *str, t_obj *obj, t_env *e);
void			plane(char *str, t_env *e);
void			cylinder(char *str, t_obj *obj, t_env *e);
void			cone(char *str, t_obj *obj, t_env *e);
t_scene			init_scene(t_cam *cam);

/*
**	Memory allocation function
*/

void			alloc_mem(t_env *e);

/*
**	Free memory function
*/

void			delete_env(t_env *e);

/*
**	Valid file function
*/

void			valid_file(t_env *e);

/*
**	SDL functions
*/

void			sdl_vect_dir(t_env *e);
void			sdl(t_env *e);
void			destroy_sdl(t_env *e);

/*
**	OpenCL functions
*/

void			cl_file_platform_context_commandqueue(t_env *e);
void			cl_init_mem(t_env *e);
void			cl_buffer_program(t_env *e);
void			cl_kernel_arg(t_env *e);
void			cl_launch_read(t_env *e);
void			cl_destroy(t_env *e);

/*
**	Main function for the raytracer where the SDL and OpenCL
**	functions will be involved
*/

void			rt(t_env *e);

#endif
