/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:41:33 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:29 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cl_buffer_program(t_env *e)
{
	e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.memgen,
			CL_TRUE, 0, sizeof(t_gen), &e->gen, 0, NULL, NULL);
	sdl_cl_error(1, e);
	e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.memcam,
			CL_TRUE, 0, sizeof(t_cam), e->cam, 0, NULL, NULL);
	sdl_cl_error(1, e);
	if (e->gen.obj_num)
	{
		e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.memobj,
				CL_TRUE, 0, e->gen.obj_num * sizeof(t_obj), e->obj, 0, NULL,
				NULL);
		sdl_cl_error(1, e);
	}
	if (e->gen.light_num)
	{
		e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.memlight,
				CL_TRUE, 0, e->gen.light_num * sizeof(t_light), e->light, 0,
				NULL, NULL);
		sdl_cl_error(1, e);
	}
	e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.memscene,
			CL_TRUE, 0, sizeof(t_scene), &e->scene, 0, NULL, NULL);
	sdl_cl_error(1, e);
}

static void	cl_kernel_arg_bis(t_env *e)
{
	if (e->gen.light_num)
		e->cl.ret = clSetKernelArg(e->cl.kernel, 4, sizeof(cl_mem),
				(void *)&e->cl.memlight);
	else
		e->cl.ret = clSetKernelArg(e->cl.kernel, 4, sizeof(cl_mem),
				0);
	sdl_cl_error(1, e);
	e->cl.ret = clSetKernelArg(e->cl.kernel, 5, sizeof(cl_mem),
			(void *)&e->cl.memscene);
	sdl_cl_error(1, e);
}

void		cl_kernel_arg(t_env *e)
{
	if (!e->cl.kernel)
		e->cl.kernel = clCreateKernel(e->cl.program, "rt", &e->cl.ret);
	sdl_cl_error(1, e);
	e->cl.ret = clSetKernelArg(e->cl.kernel, 0, sizeof(cl_mem),
			(void *)&e->cl.mempixel);
	sdl_cl_error(1, e);
	e->cl.ret = clSetKernelArg(e->cl.kernel, 1, sizeof(cl_mem),
			(void *)&e->cl.memgen);
	sdl_cl_error(1, e);
	e->cl.ret = clSetKernelArg(e->cl.kernel, 2, sizeof(cl_mem),
			(void *)&e->cl.memcam);
	sdl_cl_error(1, e);
	if (e->gen.obj_num)
		e->cl.ret = clSetKernelArg(e->cl.kernel, 3, sizeof(cl_mem),
				(void *)&e->cl.memobj);
	else
		e->cl.ret = clSetKernelArg(e->cl.kernel, 3, sizeof(cl_mem),
				0);
	sdl_cl_error(1, e);
	cl_kernel_arg_bis(e);
}

void		cl_launch_read(t_env *e)
{
	e->cl.ret = clEnqueueNDRangeKernel(e->cl.command_queue, e->cl.kernel,
			2, NULL, e->cl.global_item_size, e->cl.local_item_size, 0,
			NULL, NULL);
	e->cl.ret = clFinish(e->cl.command_queue);
	sdl_cl_error(1, e);
	e->cl.ret = clEnqueueReadBuffer(e->cl.command_queue, e->cl.mempixel,
			CL_TRUE, 0, 1024 * 576 * sizeof(cl_uchar4), e->pixel, 0,
			NULL, NULL);
	sdl_cl_error(1, e);
}

void		cl_destroy(t_env *e)
{
	e->cl.ret = clReleaseKernel(e->cl.kernel);
	e->cl.ret = clReleaseProgram(e->cl.program);
	e->cl.ret = clReleaseMemObject(e->cl.memgen);
	e->cl.ret = clReleaseMemObject(e->cl.memcam);
	e->cl.ret = clReleaseMemObject(e->cl.memobj);
	e->cl.ret = clReleaseMemObject(e->cl.memlight);
	e->cl.ret = clReleaseMemObject(e->cl.memscene);
	e->cl.ret = clReleaseCommandQueue(e->cl.command_queue);
	e->cl.ret = clReleaseContext(e->cl.context);
	ft_strdel(&e->cl.source);
}
