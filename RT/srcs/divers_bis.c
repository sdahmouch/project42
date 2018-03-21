/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:58:02 by dcooray           #+#    #+#             */
/*   Updated: 2017/12/11 18:12:33 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*parse_str(char **str)
{
	while (!ft_isdigit(**str) && **str != '-' && **str != '+' && **str)
		(*str)++;
	return (*str);
}

void	parse_number(char **str)
{
	while ((ft_isdigit(**str) || **str == '-' || **str == '+' || **str == '.')
			&& **str)
		(*str)++;
}

char	*parse_empty(char **str)
{
	while (ft_isspace(**str) && **str)
		(*str)++;
	return (*str);
}

void	parse_alpha(char **str)
{
	while (ft_isalpha(**str) && **str)
		(*str)++;
}
