/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:46:11 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/08 19:48:51 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	cl_read_file(char *file, t_env *e)
{
	char	*line;
	int		fd;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		basic_error(file, e);
	while (get_next_line(fd, &line) > 0)
		e->cl.source = ft_strdeljoin(e->cl.source, line);
	if (close(fd) == -1 || errno == EISDIR)
		basic_error(file, e);
}

static void	cl_init_var(t_env *e)
{
	e->cl.platform_id = NULL;
	e->cl.device_id = NULL;
	e->cl.context = NULL;
	e->cl.command_queue = NULL;
	e->cl.mempixel = NULL;
	e->cl.memgen = NULL;
	e->cl.memcam = NULL;
	e->cl.memobj = NULL;
	e->cl.memlight = NULL;
	e->cl.memscene = NULL;
	e->cl.program = NULL;
	e->cl.kernel = NULL;
	e->cl.global_item_size[0] = 1024;
	e->cl.global_item_size[1] = 576;
	e->cl.local_item_size[0] = 32;
	e->cl.local_item_size[1] = 32;
}

void		cl_file_platform_context_commandqueue(t_env *e)
{
	cl_init_var(e);
	cl_read_file("./srcs/rt.cl", e);
	e->cl.source_size = ft_strlen(e->cl.source);
	e->cl.ret = clGetPlatformIDs(1, &e->cl.platform_id,
			&e->cl.ret_num_platforms);
	sdl_cl_error(1, e);
	e->cl.ret = clGetDeviceIDs(e->cl.platform_id, CL_DEVICE_TYPE_GPU, 1,
			&e->cl.device_id, &e->cl.ret_num_devices);
	sdl_cl_error(1, e);
	e->cl.context = clCreateContext(NULL, 1, &e->cl.device_id,
			NULL, NULL, &e->cl.ret);
	sdl_cl_error(1, e);
	e->cl.command_queue = clCreateCommandQueue(e->cl.context,
			e->cl.device_id, 0, &e->cl.ret);
	sdl_cl_error(1, e);
}

static void	cl_init_mem_bis(t_env *e)
{
	e->cl.memscene = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
			sizeof(t_scene), NULL, &e->cl.ret);
	e->cl.program = clCreateProgramWithSource(e->cl.context, 1,
			(const char **)&e->cl.source, (const size_t *)&e->cl.source_size,
			&e->cl.ret);
	sdl_cl_error(1, e);
	e->cl.ret = clBuildProgram(e->cl.program, 1, &e->cl.device_id,
			NULL, NULL, NULL);
	sdl_cl_error(1, e);
}

void		cl_init_mem(t_env *e)
{
	e->cl.mempixel = clCreateBuffer(e->cl.context, CL_MEM_WRITE_ONLY,
			1024 * 576 * sizeof(cl_uchar4), NULL, &e->cl.ret);
	sdl_cl_error(1, e);
	e->cl.memgen = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
			sizeof(t_gen), NULL, &e->cl.ret);
	sdl_cl_error(1, e);
	e->cl.memcam = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
			sizeof(t_cam), NULL, &e->cl.ret);
	sdl_cl_error(1, e);
	if (e->gen.obj_num)
	{
		e->cl.memobj = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
				e->gen.obj_num * sizeof(t_obj), NULL, &e->cl.ret);
		sdl_cl_error(1, e);
	}
	if (e->gen.light_num)
	{
		e->cl.memlight = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
				e->gen.light_num * sizeof(t_light), NULL, &e->cl.ret);
		sdl_cl_error(1, e);
	}
	cl_init_mem_bis(e);
}
