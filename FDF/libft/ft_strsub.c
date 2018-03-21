/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:38:31 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:26:34 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s != '\0')
	{
		if ((str = ft_memalloc(len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (len > i && s[i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		while (len > i)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
