/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:39:14 by dcooray           #+#    #+#             */
/*   Updated: 2016/12/06 11:22:02 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*ft_define_list(void)
{
	t_tetris	*new;
	int			i;

	i = 0;
	new = (t_tetris *)malloc(sizeof(t_tetris));
	if (!new)
		ft_error();
	new->tetris = (char **)malloc(sizeof(char *) * 5);
	if (!(new->tetris))
		exit(EXIT_FAILURE);
	while (i < 4)
	{
		new->tetris[i] = (char *)malloc(sizeof(char) * 5);
		if (!(new->tetris[i]))
			ft_error();
		i++;
	}
	new->tetris[i] = NULL;
	new->height = 0;
	new->width = 0;
	new->letter = '\0';
	new->next = NULL;
	return (new);
}

void			ft_addlist(t_tetris **list)
{
	t_tetris	*maillon;

	maillon = ft_define_list();
	if (*list != NULL)
		maillon->next = *list;
	*list = maillon;
}

void			ft_del_onelist(t_tetris **list)
{
	int			i;

	i = 0;
	if (!list)
		ft_error();
	if (*list != NULL)
	{
		while ((*list)->tetris[i] != NULL)
		{
			free((*list)->tetris[i]);
			(*list)->tetris[i] = NULL;
			i++;
		}
		free((*list)->tetris);
		(*list)->tetris = NULL;
	}
	free(*list);
	*list = NULL;
}

void			ft_dellist(t_tetris **list)
{
	t_tetris	*tmp;

	if (!list)
		ft_error();
	while (*list != NULL)
	{
		tmp = (*list)->next;
		ft_del_onelist(list);
		*list = tmp;
	}
}

void			ft_list_letter(t_tetris *list)
{
	int	i;
	int	k;

	if (!list)
		ft_error();
	k = 0;
	while (list != NULL)
	{
		i = 0;
		list->letter = 'A' + k;
		if (k > 25)
			ft_error();
		k++;
		list = list->next;
	}
}
