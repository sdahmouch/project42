/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:30:08 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/01/03 15:20:21 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if ((str = (char *)malloc(size * sizeof(*str))) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
