/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:38:39 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/01/16 14:11:19 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned char *tmp_1;
	unsigned char *tmp_2;

	while (*big)
	{
		tmp_1 = (unsigned char *)big;
		tmp_2 = (unsigned char *)little;
		while (*tmp_1 != '\0' && *tmp_2 != '\0' && *tmp_1 == *tmp_2)
		{
			tmp_1++;
			tmp_2++;
		}
		if (*tmp_2 == '\0')
			return ((char *)big);
		else
			return (NULL);
		big++;
	}
	return (NULL);
}
