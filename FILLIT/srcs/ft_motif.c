/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:31:53 by dcooray           #+#    #+#             */
/*   Updated: 2016/11/26 23:31:55 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_motif(char **motif)
{
	int	i;
	int	j;

	if (!(ft_param(motif, &i, &j)))
		return (0);
	if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i][j + 2] == '#' && motif[i][j + 3] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 2][j] == '#' && motif[i + 3][j] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i + 1][j] == '#' && motif[i + 1][j + 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i + 1][j + 1] == '#' && motif[i + 1][j + 2] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 1][j + 1] == '#' && motif[i + 2][j + 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i + 1][j - 1] == '#' && motif[i + 1][j] == '#')
		return (1);
	else
		return (ft_motif_bis(motif));
}

int	ft_motif_bis(char **motif)
{
	int	i;
	int	j;

	if (!(ft_param(motif, &i, &j)))
		return (0);
	if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 1][j - 1] == '#' && motif[i + 2][j - 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 2][j] == '#' && motif[i + 2][j - 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i][j + 2] == '#' && motif[i + 1][j + 2] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i + 1][j] == '#' && motif[i + 2][j] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 1][j + 1] == '#' && motif[i + 1][j + 2] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 2][j] == '#' && motif[i + 2][j + 1] == '#')
		return (1);
	else
		return (ft_motif_ter(motif));
}

int	ft_motif_ter(char **motif)
{
	int	i;
	int	j;

	if (!(ft_param(motif, &i, &j)))
		return (0);
	if (motif[i][j] == '#' && motif[i + 1][j - 2] == '#' &&
		motif[i + 1][j - 1] == '#' && motif[i + 1][j] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i + 1][j + 1] == '#' && motif[i + 2][j + 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i][j + 2] == '#' && motif[i + 1][j] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j - 1] == '#' &&
		motif[i + 1][j] == '#' && motif[i + 1][j + 1] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i + 1][j - 1] == '#' &&
		motif[i + 1][j] == '#' && motif[i + 2][j] == '#')
		return (1);
	else if (motif[i][j] == '#' && motif[i][j + 1] == '#' &&
		motif[i][j + 2] == '#' && motif[i + 1][j + 1] == '#')
		return (1);
	else
		return (ft_motif_quater(motif));
}

int	ft_motif_quater(char **motif)
{
	int	i;
	int	j;

	if (!(ft_param(motif, &i, &j)))
		return (0);
	if (motif[i][j] == '#' && motif[i + 1][j] == '#' &&
		motif[i + 1][j + 1] == '#' && motif[i + 2][j] == '#')
		return (1);
	else
		return (0);
}
