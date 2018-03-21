/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:17:17 by sdahmouc          #+#    #+#             */
/*   Updated: 2016/11/22 15:48:38 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (s[j] != '\0')
			i++;
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	j = 0;
	n = 0;
	if (s == NULL)
		return (NULL);
	if ((str = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1))
			== NULL)
		return (NULL);
	while (s[i] != '\0' && s[n] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		n = i;
		while (s[n] != '\0' && s[n] != c)
			n++;
		str[j++] = ft_strsub(s, i, n - i);
		i = n;
	}
	str[ft_count_words(s, c)] = 0;
	return (str);
}
