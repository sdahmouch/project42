/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:32:03 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/04 11:41:38 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

#define SIZE 1

int		display_file(char **av)
{
	int		fd;
	int		ret;
	char	tab[SIZE + 1];

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error open()\n");
		return (1);
	}
	while ((ret = read(fd, tab, SIZE) != 0))
	{
		tab[ret] = '\0';
		ft_putstr(tab);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Error close()\n");
		return (1);
	}
	return (0);
}
