/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:51:23 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/29 23:03:41 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	strlen_dst;
	size_t	strlen_src;

	strlen_dst = ft_strlen(dst);
	strlen_src = ft_strlen(src);
	if (size <= strlen_dst)
		return (size + strlen_src);
	else
		ft_strncat(dst, src, size - strlen_dst - 1);
	return (strlen_dst + strlen_src);
}
