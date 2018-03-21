/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:18:23 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 15:25:25 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
			i++;
		while (j > 0 && (s[j] == '\t' || s[j] == '\n' || s[j] == ' '))
			j--;
		j++;
		if (i < j)
		{
			if ((str = ft_strsub(s, i, j - i)))
				return (str);
		}
		else
			return (ft_strnew(0));
	}
	return (NULL);
}
