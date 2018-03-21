/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motif_sf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:34:33 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/26 23:34:35 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_motif_sf(char **motif)
{
	if (!motif)
		return (0);
	if (motif[2][0] == '#' && motif[2][1] == '#' &&
		motif[3][0] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[2][1] == '#' && motif[2][2] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[2][2] == '#' && motif[2][3] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[2][1] == '#' && motif[2][2] == '#' &&
		motif[3][0] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[2][2] == '#' && motif[2][3] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[1][1] == '#' && motif[2][1] == '#' &&
		motif[3][0] == '#' && motif[3][1] == '#')
		return (1);
	else
		return (ft_motif_sf_bis(motif));
}

int	ft_motif_sf_bis(char **motif)
{
	if (!motif)
		return (0);
	if (motif[1][2] == '#' && motif[2][2] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[1][3] == '#' && motif[2][3] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[1][0] == '#' && motif[1][1] == '#' &&
		motif[2][0] == '#' && motif[3][0])
		return (1);
	else if (motif[1][1] == '#' && motif[1][2] == '#' &&
		motif[2][1] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[1][2] == '#' && motif[1][3] == '#' &&
		motif[2][2] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[2][0] == '#' && motif[3][0] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else
		return (ft_motif_sf_ter(motif));
}

int	ft_motif_sf_ter(char **motif)
{
	if (!motif)
		return (0);
	if (motif[2][1] == '#' && motif[3][1] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[1][0] == '#' && motif[2][0] == '#' &&
		motif[3][0] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[1][1] == '#' && motif[2][1] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[1][2] == '#' && motif[2][2] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[2][2] == '#' && motif[3][0] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[2][3] == '#' && motif[3][1] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else
		return (ft_motif_sf_quater(motif));
}

int	ft_motif_sf_quater(char **motif)
{
	if (!motif)
		return (0);
	if (motif[2][0] == '#' && motif[2][1] == '#' &
		motif[2][2] == '#' && motif[3][0] == '#')
		return (1);
	else if (motif[2][1] == '#' && motif[2][2] == '#' &&
		motif[2][3] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[2][1] == '#' && motif[3][0] == '#' &&
		motif[3][1] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[2][2] == '#' && motif[3][1] == '#' &&
		motif[3][2] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[1][1] == '#' && motif[2][0] == '#' &&
		motif[2][1] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[1][2] == '#' && motif[2][1] == '#' &&
		motif[2][2] == '#' && motif[3][2] == '#')
		return (1);
	else
		return (ft_motif_sf_quint(motif));
}

int	ft_motif_sf_quint(char **motif)
{
	if (!motif)
		return (0);
	if (motif[1][3] == '#' && motif[2][2] == '#' &&
		motif[2][3] == '#' && motif[3][3] == '#')
		return (1);
	else if (motif[2][0] == '#' && motif[2][1] == '#' &&
		motif[2][2] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[2][1] == '#' && motif[2][2] == '#' &&
		motif[2][3] == '#' && motif[3][2] == '#')
		return (1);
	else if (motif[1][0] == '#' && motif[2][0] == '#' &&
		motif[2][1] == '#' && motif[3][0] == '#')
		return (1);
	else if (motif[1][1] == '#' && motif[2][1] == '#' &&
		motif[2][2] == '#' && motif[3][1] == '#')
		return (1);
	else if (motif[1][2] == '#' && motif[2][2] == '#' &&
		motif[2][3] == '#' && motif[3][2] == '#')
		return (1);
	else
		return (0);
}
