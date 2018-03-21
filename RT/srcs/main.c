/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:01:30 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 22:24:16 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		malloc_error(e);
	if (!(e->pixel = (cl_uchar4 *)ft_memalloc(sizeof(cl_uchar4) *
					1024 * 576)))
		malloc_error(e);
	e->sdl_status = 0;
	e->obj_status = 0;
	e->light_status = 0;
	e->gen.clr.x = 0.0;
	e->gen.clr.y = 0.0;
	e->gen.clr.z = 0.0;
	e->gen.clr.w = 255.0;
	e->gen.recursion = 0;
	e->gen.antialliasing = 1;
	e->gen.effect = 0;
	e->cl.source = ft_strnew(0);
	e->status = 0;
	e->cam = NULL;
	e->obj = NULL;
	e->light = NULL;
	e->gen.obj_num = 0;
	e->gen.light_num = 0;
	return (e);
}

static void		read_line(char *str, t_env *e)
{
	int		fd;
	int		status;
	char	*line;

	status = 0;
	e->list_obj = NULL;
	e->list_light = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		basic_error(str, e);
	while (get_next_line(fd, &line) > 0)
	{
		scene(e, line);
		ft_strdel(&line);
		status = 1;
	}
	if (close(fd) == -1 || errno == EISDIR)
		basic_error(str, e);
	if (!status)
		empty_file(e);
	if (e->status)
		syntax_error(e);
}

int				main(int argc, char **argv)
{
	t_env	*e;

	if (argc == 2)
	{
		if (!ft_strcmp("/dev/zero", argv[1]))
		{
			ft_printf("Error: Can't pass /dev/zero in parameters\n");
			return (0);
		}
		e = init_env();
		read_line(argv[1], e);
		alloc_mem(e);
		valid_file(e);
		rt(e);
		delete_env(e);
	}
	else
		ft_printf("Usage: %s <file>\n", argv[0]);
	return (0);
}
