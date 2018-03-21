/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:05:10 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:40:50 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*s_1;
	unsigned char	*res;

	i = 0;
	res = NULL;
	chr = (unsigned char)c;
	s_1 = (unsigned char *)s;
	while (n > i && s_1[i] != chr)
	{
		if (s_1[i] == chr)
			res = ((unsigned char *)s + i);
		i++;
	}
	if (n > i && s_1[i] == chr)
		res = ((unsigned char *)s + i);
	return (res);
}
