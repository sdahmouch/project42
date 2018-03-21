/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:56:51 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:32:25 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sdl_cl_error(int i, t_env *e)
{
	if (!i)
	{
		ft_printf("Error: SDL failed\n");
		delete_env(e);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (e->cl.ret != CL_SUCCESS)
		{
			ft_printf("Error: OpenCL failed %d\n", e->cl.ret);
			delete_env(e);
			exit(EXIT_SUCCESS);
		}
	}
}

void	basic_error(char *str, t_env *e)
{
	if (errno == EISDIR)
		ft_printf("Error: %s %s\n", str, strerror(errno));
	else
		perror("Error");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	malloc_error(t_env *e)
{
	ft_printf("Error: Malloc failed\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	empty_file(t_env *e)
{
	ft_printf("Error: Empty file\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	syntax_error(t_env *e)
{
	ft_printf("Error: Syntax incorrect\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}
