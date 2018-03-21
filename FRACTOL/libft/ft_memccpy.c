/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:24:24 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:40:34 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_1;
	unsigned char	*src_1;

	i = 0;
	dst_1 = (unsigned char *)dst;
	src_1 = (unsigned char *)src;
	while (n > i)
	{
		dst_1[i] = src_1[i];
		if (src_1[i] == (unsigned char)c)
			return (dst_1 + i + 1);
		i++;
	}
	return (NULL);
}
