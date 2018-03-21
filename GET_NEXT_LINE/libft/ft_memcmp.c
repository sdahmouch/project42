/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:13:14 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:41:05 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_1;
	const char	*s2_1;

	i = 0;
	s1_1 = (const char *)s1;
	s2_1 = (const char *)s2;
	if (!n)
		return (0);
	while ((n - 1) > i && s1_1[i] == s2_1[i])
	{
		i++;
	}
	return ((unsigned char)s1_1[i] - (unsigned char)s2_1[i]);
}
