/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:26:25 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/04 11:30:38 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

#define SIZE 1

int		main(int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (ac == 1)
		{
			write(1, "File name missing.\n", 19);
			return (1);
		}
		else if (ac == 2)
		{
			display_file(av);
			return (0);
		}
		else
		{
			write(2, "Too many arguments.\n", 20);
			return (1);
		}
		i++;
	}
	return (0);
}
