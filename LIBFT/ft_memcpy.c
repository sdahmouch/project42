/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:40:39 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:42:39 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
		i++;
	}
	return (dst);
}
