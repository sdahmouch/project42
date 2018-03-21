/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:25:59 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/18 16:11:12 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	s1_strlen;

	s1_strlen = ft_strlen(s1);
	i = 0;
	while (n > i && s2[i] != '\0')
	{
		s1[s1_strlen + i] = s2[i];
		i++;
	}
	s1[s1_strlen + i] = '\0';
	return (s1);
}
