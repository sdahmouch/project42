/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:46:11 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/07/19 21:42:03 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (tab[index] != '\0')
	{
		if (f(tab[index]) == 1)
		{
			count++;
		}
		index++;
	}
	return (count);
}
