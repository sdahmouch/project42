/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:21:03 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/22 15:36:27 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)s + i + 1);
	while (s[i] != '\0' && s[i] != (char)c)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	else
		return (0);
}
