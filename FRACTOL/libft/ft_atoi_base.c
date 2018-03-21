/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:30:42 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/05 23:30:44 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

static int		ft_isvalid(char c, int base)
{
	char *digits;
	char *digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

static int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}
